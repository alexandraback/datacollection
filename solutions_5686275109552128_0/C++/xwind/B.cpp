#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<string>
#define REP(it,end) for (int it = 1; it <= (end); it++)
#define FOR(it,begin,end) for (int it = (begin); it <= (end); it++)
#define ROF(it,begin,end) for (int it = (begin); it >= (end); it--)
using namespace std;
const int manx=1001;
priority_queue<int> q;
int cal[1002][1002];
int mp[1002][1002];
int dp[1002][1002];
const int INF=((~0u)>>2);
int main()
{
	int tmx,minv,con,T,n,ov,v,i,j;
	for(i=1;i<=1000;i++)
		for(j=1;j<=i;j++)
			cal[i][j]=i/j+(i%j!=0)-1;
	scanf("%d",&T);
	//for(i=1;i<=10;i++,cout <<endl)for(j=1;j<=i;j++)cout <<cal[i][j]<<" ";
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		memset(mp,0,sizeof(mp));
		for(i=0;i<n;i++)
		{
			scanf("%d",&ov);
			con=0;
			v=ov;
			for(j=1;j<=v;j++)mp[i][j]=cal[v][j];
			/*
			while(!q.empty())q.pop();
			q.push(v);
			while(1)
			{
				v=q.top();
				mp[i][v]=min(mp[i][v],con);
				if(v==1)break;
				q.pop();
				q.push(v/2);
				q.push(v-v/2);
				con++;
			}
			minv=INF;
			for(j=1;j<=ov;j++)
			{
				mp[i][j]=min(minv,mp[i][j]);
				minv=min(minv,mp[i][j]);
			}*/
		}
		//for(i=0;i<n;i++,cout <<endl) for(j=1;j<=10;j++) cout <<mp[i][j]<<" ";
		for(i=0;i<n;i++)
		{
			minv=INF;
			for(j=1;j<=1000;j++)
			{
				if(i==0)dp[i][j]=mp[i][j];
				else
				{
					minv=min(dp[i-1][j],minv);
					dp[i][j]=minv+mp[i][j];
				}
			}
		}
		//cout <<"success"<<endl;
		minv=INF;
		for(i=1;i<=1000;i++)
		{
			//cout <<dp[n-1][i]<<" maxv:"<<i<<endl;
			minv=min(minv,dp[n-1][i]+i);	
		}
		printf("Case #%d: %d\n",cas,minv); 
	}
	return 0;
}
