#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector< pair<long long,int> > box;
vector< pair<long long,int> > toy;
long long dp[200][200];

long long min(long long a, long long b)
{
	if(a<=b)
		return a;
	return b;
}

long long max(long long a, long long b)
{
	if(a>=b)
		return a;
	return b;
}

long long dyn(int n, int m)
{
	if(n==0 || m==0)
		return 0;
	if(dp[n][m]!=-1)
		return dp[n][m];
	pair<long long, int> p1=box[n-1];
	pair<long long, int> p2=toy[m-1];

	if(p1.second==p2.second)
	{
		dp[n][m]=min(p1.first,p2.first)+dyn(n-1,m-1);
		long long rez=max(p1.first,p2.first);
		if(p1.first!=p2.first)
		{
			if(p1.first==rez)
			{
				box[n-1].first-=p2.first;
				dp[n][m]=max(dp[n][m],p2.first+dyn(n,m-1));
				box[n-1].first+=p2.first;
			}
			if(p2.first==rez)
			{
				toy[n-1].first-=p1.first;
				dp[n][m]=max(dp[n][m],p1.first+dyn(n-1,m));
				toy[n-1].first+=p1.first;
			}
		}
	}
	else
		dp[n][m]=max(dyn(n-1,m),dyn(n,m-1));
	return dp[n][m];
}
	
int main()
{
	int t;

	FILE *f=fopen("C.in","r");
	FILE *g=fopen("C.out","w");

	fscanf(f,"%i",&t);
	for(int i=0;i<t;++i)
	{
		int n,m;
		box.clear();
		toy.clear();
		fscanf(f,"%i%i",&n,&m);
		for(int j=0;j<=n;++j)
			for(int k=0;k<=m;++k)
				dp[j][k]=-1;
		for(int j=0;j<=n;++j)
			dp[j][0]=0;
		for(int j=0;j<=m;++j)
			dp[0][j]=0;

		for(int j=0;j<n;++j)
		{
			long long nr;
			int tip;
			fscanf(f,"%lli%i",&nr,&tip);
			pair<long long, int> p=make_pair(nr,tip);
			box.push_back(p);
		}
		for(int j=0;j<m;++j)
		{
			long long nr;
			int tip;
			fscanf(f,"%lli%i",&nr,&tip);
			pair<long long, int> p=make_pair(nr,tip);
			toy.push_back(p);
		}
		long long rez=dyn(n,m);
		fprintf(g,"Case #%i: %lli\n",i+1,rez);
	}
	fclose(f);
	fclose(g);
}
