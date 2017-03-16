#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[16];
int e,r,n;
int dp[11][10];
int recur(int p,int en);
int main()
{
	int cas;
	cin>>cas;
	for(int q = 1 ;q<=cas ;q++)
	{
		memset(dp,-1,sizeof(dp));
		cin>>e>>r>>n;
		for(int i = 0 ;i < n ; i++)
			cin>>a[i];
		cout<<"Case #"<<q<<": "<<recur(0,e)<<endl;
	}
	return 0;
}
int recur(int p,int en)
{
	if(p==n)return 0;
	if(dp[p][en]!=-1)return dp[p][en];
	int & ret = dp[p][en];
	for(int i = 0 ;i <= en ; i++)
	{
		int tmp = recur(p+1, min(e,en - i + r)) + i*a[p];
		if(ret == -1 || ret < tmp) ret = tmp;
	}
	return ret;
}
