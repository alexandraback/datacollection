#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007

int powten[10];
void precompute(void)
{
	int i;
	powten[0]=1;
	for(i=1;i<10;i++)
		powten[i]=powten[i-1]*10;
}
int digit(int x)
{
	int ret=0;
	if(x==0)
		return 0;
	while(x>0)
	{
		ret++;
		x/=10;
	}
	return ret;
}
long long  n,m;
// 12345      5 4 3 2 1     12345  1234  123   12  1  
int recycle(int x)
{
	int cur,temp,num[10],i,ret=0,dx=digit(x);
	set < int > S;
//	printf("%d %d\n",x,digit(x));
	cur=0;
	temp=x;
	while(temp>0)
	{
		num[cur++]=temp%10;
		temp/=10;
	}
	num[cur]=0;
	for(i=cur-1;i>=0;i--)
	{
		num[i]+=num[i+1]*10;
	}
	ret=0;
	for(i=0;i<cur;i++)
	{
//		printf("%d %d %d\n",num[i],x,(num[i]+powten[cur-i]*(x%powten[i])));
		temp=num[i]+powten[cur-i]*(x%powten[i]);
		if(temp>x)
		{
			if(temp<=m)
			{
				if(digit(temp)==dx)
				{
			//		printf("%d %d\n",x,temp);
					S.insert(temp);
				}
			}
		}
	}
	return (int)S.size();
}

int main()
{
	long long i,ans,t,test;
	precompute();
	while(scanf("%lld",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			scanf("%lld%lld",&n,&m);
			ans=0;
			for(i=n;i<=m;i++)
			{
				ans+=recycle(i);
			}
			printf("Case #%lld: %lld\n",test,ans);
			fprintf(stderr,"Case #%lld: %lld\n",test,ans);
		}
	}
	return 0;
}
