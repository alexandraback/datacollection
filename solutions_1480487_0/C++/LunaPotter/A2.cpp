/*************************************************************************
 > File Name: A2.cpp
 > Created Time: 日  5/ 6 01:06:01 2012
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,n;
int X, S;
int s[300];
double ans[300];
bool visit[300];
void solve()
{
	S=X=0;
	for (int i=0;i<N;i++){X+=s[i];visit[i]=false;}
	S=X*2;
	n=N;
	bool alive=true;
	while(alive)
	{
		alive=false;
		for (int i=0;i<N;i++)
            if(!visit[i])
            {
                if(s[i]*n>S) {n--;S-=s[i];visit[i]=true;alive=true;ans[i]=0;}
            }
	}
	for (int i=0;i<N;i++)
	{
		if(visit[i]) continue;
		ans[i]=((S*1.0)/n-s[i])/X;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for (int j=0;j<N;j++)scanf("%d",&s[j]);
		solve();
		printf("Case #%d: ",i);
		for (int j=0;j<N-1;j++)printf("%.6lf ",ans[j]*100);
		printf("%.6lf\n",ans[N-1]*100);
	}
}

