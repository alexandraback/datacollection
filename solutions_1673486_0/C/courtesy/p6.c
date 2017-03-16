#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fs fscanf
#define fp fprintf
#define rd(x) fscanf(f1,"%d",&x)
#define rld(x) fscanf(f1,"%ld",&x)
#define rlld(x) fscanf(f1,"%lld",&x)
#define rf(x) fscanf(f1,"%f",&x)
#define rlf(x) fscanf(f1,"%lf",&x)
#define rs(x) fscanf(f1,"%s",x)
FILE *f1,*f2;
long int a,b;
double pa[100000],re,rete1,rete2,rete3,rete4,temp,temp1;

void Main()
{
	rld(a);
	rld(b);
	int i,j,k;
	for(i=0;i<a;i++)
	rlf(pa[i]);
	for(i=0;i<=a;i++)
	{
		rete1=1;
		for(j=0;j<(a-i);j++)
		rete1*=pa[j];
		temp=rete1;
		rete1=(b-a+1+2*i)*temp;
		rete1+=(b-a+1+2*i+b+1)*(1-temp);
		if(i==0)
		re=rete1;
		else
		{
			if(re>rete1)
			re=rete1;
		}
	}
	rete1=1+b+1;
	if(re>rete1)
	re=rete1;
	fp(f2,"%lf",re);
	
}
int main()
{
	f1=fopen("/home/vivek/Desktop/s.in","r");
	f2=fopen("/home/vivek/Desktop/s.out","w");
	int cs,i;
	char c;
	fscanf(f1,"%d",&cs);
	for(i=1;i<=cs;i++)
	{
		fprintf(f2,"Case #%d: ",i);
		Main();
		c='\n';
		fputc(c,f2);
		printf("%d",i);
	}
	return(1);
}
