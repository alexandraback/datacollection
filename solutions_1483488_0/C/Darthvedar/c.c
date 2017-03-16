#include<stdio.h>
#include<string.h>

int comb[20],c_len=0;
long long int length(long long int a)
{
	long long int j;
	if(a>=0 && a<10)
	j=1;
	else if(a>=10 && a<100)
	j=2;
	else if(a>=100 && a<1000)
	j=3;
	else if(a>=1000 && a<10000)
	j=4;
	else if(a>=10000 && a<100000)
	j=5;
	else if(a>=100000 && a<1000000)
	j=6;
	else j=7;
	return j;
}
long long int power(long long int mod,long long int len)
{
	long long int j;
	if(len==1) j=0;
	if(len==2) j=10;
	if(len==3) j=100;
	if(len==4) j=1000;
	if(len==5) j=10000;
	if(len==6) j=100000;
	if(len==7) j=1000000;
	if(len==8) j=10000000;
	j=j*mod;
	return j;
}
long long int check(long long int i)
{
	int k=0;
	for(k=0;k<c_len;k++)
	{
	if(comb[k]==i) return 0;
	}
	comb[c_len++]=i;
	return 1;
}
long long int operation(long long int a,long long int b)
{
	long long int len,i,t,j,mod,rem,pow,op=0,old;
	len=length(a);
	for(i=a;i<=b;i++)
	{
		old=i;c_len=0;
		for(j=0;j<len;j++)
		{
			mod=i%10;
			i=i/10;
			rem=power(mod,len);
			i=i+rem;
			if(i>=a && i<=b && i>old)
			{
			
			    op=op+check(i);
			
			}
		}
		i=old;
	}
	return op;
}
int main()
{
	long long int a,b,c,t,i,j,k,op;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld",&a,&b);
		op=operation(a,b);
		printf("Case #%lld: %lld\n",i+1,op);
	}
	return 0;
}
