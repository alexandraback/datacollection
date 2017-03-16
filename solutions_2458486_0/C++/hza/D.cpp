#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;

typedef long long LL;
typedef double ld;

const int NUM=200+10;

int n,type[NUM],f[1<<20],ans[NUM],all[NUM];
vector<int> ch[NUM];

int calc(int u,int dep)
{
	if(f[u]!=-1)
		return f[u];
	if(u==0)
		return f[u]=1;
	int i,j,flag=0;
	REP2(i,0,n)
		if( ((u>>i)&1) && all[type[i]]>0)
		{
			--all[type[i]];
			REP2(j,0,ch[i].size())
				++all[ch[i][j]];
			if(calc(u&(~(1<<i)),dep+1))
				flag=1;
			++all[type[i]];
			REP2(j,0,ch[i].size())
				--all[ch[i][j]];
			if(flag)
			{
				f[u]=1;
				ans[dep]=i;
				break;
			}
		}
	if(f[u]!=1)
		f[u]=0;
	return f[u];
}

int Main()
{
	memset(all,0,sizeof all);
	memset(f,-1,sizeof f);
	int k,i,a;
	scanf("%d%d",&k,&n);
	while(k--)
	{
		scanf("%d",&a);
		++all[a];
	}
	REP2(i,0,n)
	{
		scanf("%d",&type[i]);
		scanf("%d",&k);
		ch[i].clear();
		while(k--)
		{
			scanf("%d",&a);
			ch[i].pb(a);
		}
	}
	if(calc((1<<n)-1,1))
	{
		REP(i,1,n)
			cout<<ans[i]+1<<" ";
		cout<<endl;
		return 0;
	}
	else cout<<"IMPOSSIBLE\n";
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	int i;
	int T;
	scanf("%d",&T);
	REP(i,1,T)
	{
		printf("Case #%d: ",i);
		Main();
	}
	return 0;
}
