#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define mod1 1000000007ll
#define mod2 1000000009ll
int t,c,d,v,l,minn;
int f;
int a[15];
bool dp[15][35];
bool mark[35];
void go(int pos,int prev,int lim)
{
	int i,j;
	if(pos==lim||prev==v)
	{
		int c=0,f=0;
		for(i=1;i<=v;++i)
		{
			if(mark[i])
			{
				c++;
				a[c]=i;
			}
		}
		for(i=0;i<=v;++i)
		{
			dp[0][i]=0;
		}
		dp[0][0]=1;
		for(i=1;i<=c;++i)
		{
			for(j=0;j<=v;++j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
				{
					dp[i][j]=dp[i][j]+dp[i-1][j-a[i]];
				}
			}
		}
		for(i=0;i<=v;++i)
		{
			if(!dp[c][i])
				f++;
		}
		if(!f)
		{
			minn=min(minn,c-d);
		}
		return;

	}
	else
	{
		for(i=prev+1;i<=v;++i)
		{
			if(!mark[i])
			{
				mark[i]=1;
				go(pos+1,i,lim);
				mark[i]=0;
			}
		}
		int c=0,f=0;
		for(i=1;i<=v;++i)
		{
			if(mark[i])
			{
				c++;
				a[c]=i;
			}
		}
		for(i=0;i<=v;++i)
		{
			dp[0][i]=0;
		}
		dp[0][0]=1;
		for(i=1;i<=c;++i)
		{
			for(j=0;j<=v;++j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
				{
					dp[i][j]=dp[i][j]+dp[i-1][j-a[i]];
				}
			}
		}
		for(i=0;i<=v;++i)
		{
			if(!dp[c][i])
				f++;
		}
		if(!f)
		{
			minn=min(minn,c-d);
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,l;
	sd(t);
	for(l=1;l<=t;++l)
	{
		sd(c);
		sd(d);
		sd(v);
		minn=100;
		for(i=1;i<=v;++i)
			mark[i]=0;
		for(i=1;i<=d;++i)
		{
			sd(a[i]);
			mark[a[i]]=1;
		}
		for(i=0;i<=30;++i)
		{
			dp[0][i]=0;
		}
		dp[0][0]=1;
		for(i=1;i<=d;++i)
		{
			for(j=0;j<=v;++j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
				{
					dp[i][j]=dp[i][j]+dp[i-1][j-a[i]];
				}
			}
		}
		f=0;
		for(i=0;i<=v;++i)
		{
			if(!dp[d][i])
				f++;
		}
		if(f<2)
		{
			printf("Case #%d: %d\n",l,f);
		}
		else
		{
			go(0,0,((int)log2(v))+1);
			printf("Case #%d: %d\n",l,minn);
		}
	}
}