#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
class Attack
{
public:
	int d;
	int delta_d;
	int w;
	int e;
	int s;
	int delta_s;
	int delta_p;
	int n;
	int cnt;
	Attack(int d_=0,int dd=0,int w_=0,int e_=0,int s_=0,int ds=0,int dp=0,int n_=0,int c_=0)
	{
		d=d_;
		delta_d=dd;
		w=w_;
		e=e_;
		s=s_;
		delta_s=ds;
		delta_p=dp;
		n=n_;
		cnt=c_;
	}
};
bool operator < (const Attack &a,const Attack &b)
{
	return a.d>b.d;
}
int main()
{
	int T,N,X,Y;
	int d_,n_,w_,e_,s_,dd,dp,ds;
	scanf("%d",&T);
	for (int cs=1;cs<=T;cs++)
	{
		priority_queue<Attack> q;
		map<int,int> h;
		scanf("%d",&N);
		long long ans = 0;
		for (int i=0;i<N;i++)
		{
			scanf("%d%d%d%d%d%d%d%d",&d_,&n_,&w_,&e_,&s_,&dd,&dp,&ds);
			q.push(Attack(d_,dd,w_,e_,s_,ds,dp,n_,0));
		}
		while(!q.empty())
		{
			Attack cur = q.top();
			map<int,int> nh;
			set<int> na;
			while(!q.empty() && q.top().d == cur.d)
			{
				Attack now = q.top();
				q.pop();
				bool flag = false;
				for (int i = now.w+1;i<=now.e;i++)
				{
					if (now.s>h[i])
					{
						nh[i] = nh[i]>now.s?nh[i]:now.s;
						na.insert(i);
						flag = true;
					}
				}
				if (flag)
					ans++;
				if (now.cnt<now.n-1)
				{
					q.push(Attack(now.d+now.delta_d,now.delta_d,now.w+now.delta_p,now.e+now.delta_p,now.s+now.delta_s,now.delta_s,now.delta_p,now.n,now.cnt+1));
				}
			}
			set<int>::iterator it;
			for (it=na.begin();it!=na.end();it++)
			{
				h[*it]=nh[*it];
			}
		}
		printf("Case #%d: %lld\n",cs,ans);
	}
	return 0;
}