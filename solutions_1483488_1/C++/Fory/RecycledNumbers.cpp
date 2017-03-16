#include <stdio.h>

int pow[]={1,10,100,1000,10000,100000,1000000,10000000};

int count(int A,int B,int digits)
{
	int respaldo[10];
	int init=pow[digits-1];
	if (A>init)
		init=A;
	int end=pow[digits]-1;
	if (end>B)
		end=B;
	int totalglobal=0;
	for (int i=init;i<=end;i++)
	{
		int total=0;
		int girado=i;
		for (int j=1;j<digits;j++)
		{
			int residuo=girado%10;
			girado/=10;
			girado+=residuo*pow[digits-1];
			if ((girado>i)&&(girado<=end))
			{
				bool bueno=true;
				for (int k=0;k<total;k++)
					if (respaldo[k]==girado)
					{
						bueno=false;
						break;
					}
				if (bueno)
				{
					respaldo[total]=girado;
					total++;
				}
			}
		}
		totalglobal+=total;
	}
	return totalglobal;
}

int main(int argc, char* argv[])
{
	int T;
	scanf("%d\n",&T);
	for (int t=1;t<=T;t++)
	{
		int total=0;
		int A,B;
		scanf("%d %d",&A,&B);
		for (int d=2;d<=7;d++)
			total+=count(A,B,d);
		printf("Case #%d: %d\n",t,total);
	}
	return 0;
}
