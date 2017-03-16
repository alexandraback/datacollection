 //if you want,you can

#include<stdio.h>

int f(int a,int b)
{
	int aa=a;
	int mul=1;
	while(1)
	{
		aa/=10;
		if(!aa)
		{
			break;
		}
		mul*=10;
	}
	int ret=0;

	for(int i=a;i<=b;i++)
	{
		int ran=i;
		while(1)
		{
			ran=(ran%10)*mul+ran/10;
			if(ran>i&&ran<=b)
			{
				ret++;
			}
			if(ran==i)
			{
				break;
			}
		}
	}
	return ret;
}

int main()
{
	freopen("c.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case #%d: ",tt+1);
		printf("%d\n",f(a,b));
	}
}
