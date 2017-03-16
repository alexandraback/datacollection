#include <cstdio>
#include <cstdint>
#include <cmath>

//typedef __int128_t intmax;
typedef int64_t intmax;

intmax x=0;

intmax num(int rbin, int base)
{
	intmax res=0;
	while(rbin)
	{
		res=res*base+(rbin&1);
		rbin=(rbin>>1);
	}
	return res;
}

/*
char buf[35];
void printnum(intmax num)
{
	char* p=p+34;
	while(num>0)
	{
		--p;
		*p=(num%10+'0');
		num/=10;
	}
	printf("%s",p);
}*/

bool d[100000010];
int p=2;

int prime[20000000];
int pc=0;

void init()
{
	int mp=10000,m=100000000;
	for(int i=2;i<=mp;++i)
	{
		if(d[i])continue;
		prime[pc++]=i;
		for(int j=2;i*j<=m;++j)
			d[i*j]=true;
	}
	for(int i=mp+1;i<=m;++i)
		if(!d[i])
			prime[pc++]=i;
}

int div(intmax x)
{
	int mp=ceil(sqrt(x)),t;
	for(int i=0;i<pc&&(t=prime[i])<=mp;++i)
		if(x%t==0)
			return t;
	return 1;
}

int main()
{
	init();
	//freopen("o3.txt","w",stdout);
	printf("Case #1:\n");
	int res[11],c=0;
	for(int i=32769;i<65536;i+=2)
	{
		bool flag=true;
		for(int b=2;b<=10;++b)
		{
			res[b]=div(num(i,b));
			if(res[b]==1)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			printf("%lld", num(i,10));
			for(int b=2;b<=10;++b)
				printf(" %d",res[b]);
			printf("\n");
			++c;
			if(c>=50)
				return 0;
		}
	}
	return 0;
}


