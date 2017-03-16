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
const int maxn=1e6+10;
const int INF=1e9;
int ans[maxn];
bool in[maxn];
queue<int> q;
int rever(int now)
{
	int base=1,rbase=1,res=0;
	for(;base<=now;base*=10);base/=10;
	for(;base>0;base/=10)
	{
		res+=(now%10)*base;
		now/=10;
	}
	return res;
}
void spfa(int u)
{
	int now,rev;
	for(int i=1;i<maxn;i++)ans[i]=INF;
	memset(in,0,sizeof(in));
	ans[u]=1;
	in[u]=true;
	q.push(u);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		//cout <<now<<endl;system("pause");
		in[now]=false;
		if(now+1<maxn&&ans[now+1]>ans[now]+1)
		{
			ans[now+1]=ans[now]+1;
			if(!in[now+1])
			{
				q.push(now+1);
				in[now+1]=true;
			}
		}
		rev=rever(now);
		if(rev<maxn&&ans[rev]>ans[now]+1)
		{
			ans[rev]=ans[now]+1;
			if(!in[rev])
			{
				q.push(rev);
				in[rev]=true;
			}
		}
	}
}
int main()
{
	spfa(1);
	int T,n;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",cas,ans[n]);
	}
	return 0;
}
