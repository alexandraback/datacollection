#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

#define N 2000005
int a,b;
int t;
bool flag[N];

int gen(int x,int w)
{
	int first=x%10;w--;
	while(w--)
	{
		first*=10;
	}
	return first+x/10;
}
int weishu(int x)
{
	int ans=0;
	while(x)
	{
		x/=10;ans++;
	}
	return ans;
}
int find()
{
	int ans=0;
	memset(flag,0,sizeof(flag));
	for(int x=a;x<=b;x++)if(flag[x]==0)
	{
		int nx=x,sans=0;
		int length=weishu(x);
		for(int i=0;i<=length;i++)
		{
			if(nx>=a&&nx<=b&&flag[nx]==0)
			{
					flag[nx]=1;
					sans++;
			}
			nx=gen(nx,length);
		}
		if(sans>=2)
		ans+=(sans*(sans-1))>>1;
	}
	return ans;
}
#define mydebug
int main()
{
#ifdef mydebug
	freopen("C-large.in","r",stdin);	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		int ans=find();
		printf("Case #%d: %d\n",i+1,ans);	
	}
	return 0;
}
