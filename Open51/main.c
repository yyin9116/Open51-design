#include <reg51.h>

#define uint unsigned int
#define uchar unsigned char

sbit P17=P1^7;

main ( ) 
{
	//字符 0:0xbf. 1:0x86. 2:0xdb. 3:0xcf. 4:0xe6. 5:0xed. 6:0xfd. 7:0x87. 8:0xff
	//学号前6位
	uchar code tab1[6]={0xdb,0xbf,0x86,0xff,0xbf,0xbf};
	//学号后6位,默认201800 000000按需修改
	//拨码开关上调为前6位
	//下调为后6位
	uchar code tab2[6]={0xbf,0xbf,0xbf,0xbf,0xbf,0xbf};
	uchar i;
	uint j;
	while (1)
  {
  	P3=0x01;
  	for(i=0;i<6; i++)
   	{
   	 	if(P17==1)
				P1=tab1[i];
   	 	else 
				P1=tab2[i];
    	for(j=0;j<=25000;j++);
				P3<<=1;
		}
	}
} 
