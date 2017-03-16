#include <stdio.h>
#include <string.h>

int casen;
int a,b;
int ret;
int list[10]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000};

int decide(int x)
{
	char str[11];
	sprintf(str, "%d", x);
	int len = strlen(str);
	int exist = 0;
	int k = x;
	int c[11];
	int cn=1;
	c[0]=x;
	
	for(int i=1;i<len;i++)
	{
		int p1 = k/10;
		int p2 = k%10;
		int same = 0;
		k = p1 + p2*(list[len]);
		sprintf(str, "%d", k);
		if(strlen(str)<len) continue;
		//printf("x=%d k=%d\n",x,k);
		if(k<=b && k>=a)
		{
			same = 0;
			for(int j=0;j<cn;j++)
			{
				if(k==c[j])
				{
					same=1;
					break;
				}
			}
			if(0 == same)
				c[cn++]=k;
		}
	}
	
	int minn;
	for(int i=0;i<cn-1;i++)
	{
		minn=i;
		for(int j=i+1;j<cn;j++)
		{
			if(c[minn]>c[j]) minn=j;
		}
		if(minn!=i)
		{
			int tmp = c[minn];
			c[minn] = c[i];
			c[i] = tmp;
		}
	}

	if(c[0]<x) 
		exist=0;
	else
	{	
		for(int i=0;i<cn-1;i++)
			for(int j=i+1;j<cn;j++)
			{
				if(c[i]<c[j]) exist++;
			}
		//if(exist>0) printf("x=%d %d\n",x,exist);
	}
	return exist;
}

void solve()
{
	ret=0;
	for(int i=a;i<=b;i++)
	{
		ret+=decide(i);
	}
}

int main()
{
	scanf("%d",&casen);
	for(int i=1;i<=casen;i++)
	{
		scanf("%d%d",&a,&b);
		solve();
		printf("Case #%d: %d\n",i,ret);
	}

	return 0;
}
