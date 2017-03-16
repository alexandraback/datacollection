#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

#define CLR(a,x) memset(a,x,sizeof a)
#define LL long long
#define ALL(v) v.begin(),v.end()
#define FR(i,n) for(LL i=0;i<(LL)n;i++)
#define FAB(i,a,b) for(LL i=(LL)a;i<(LL)b;i++)
#define FBA(i,b,a) for(LL i=(LL)b;i>=(LL)a;i--)
#define IIN(x) scanf("%d",&x)
#define IIN2(x,y) scanf("%d%d",&x,&y)
#define LIN(x) scanf("%I64d",&x)
#define LIN2(x,y) scanf("%I64d%I64d",&x,&y)
#define EXIT(n) {cout<<n<<endl;return 0;}
#define PII pair<int,int>
#define PPI pair<PII,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define PDI pair<double,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PI 3.141592653589793238
#define VI vector<int>
#define VLL vector<long>
#define VPL vector<PLL>
#define VS vector<string>
#define SI set<int>
#define SLL set<LL>
#define SPL set<PLL>
#define SS set<string>
#define MII map<int,int>
#define MLL map<LL,LL>
#define MPL map<PLL,LL>
#define MSI map<string,int>
#define MSL map<string,LL>
#define MIS map<int,string>
#define INF 10000000000000
#define MOD 1000000007
#define MAX 9

int q,tc;
int n,m,s;
string zip[MAX];
SS all;
VI v;
bool mark[MAX][MAX],mat[MAX][MAX];

void input()
{
	CLR(mat,0);
	cin>>n>>m;
	FR(i,n) cin>>zip[i];
	FR(i,m)
	{
		int x,y; cin>>x>>y;
		x--; y--;
		mat[x][y]=mat[y][x]=1;
	}
}

bool check()
{
	VI vis;
	//CLR(mark,0);
	int par[MAX];
	FR(i,MAX) par[i]=-1;
	FAB(i,1,n)
	{
		int x=v[i-1],y=v[i];
		if(mat[x][y]) 
		{
			par[y]=x;
			continue;
		}
		while(!mat[x][y])
		{
			if(par[x]==-1) return 0;
			x=par[x];
		}
		par[y]=x;
	}
	return 1;
}

void solve()
{
	if(n==1) return;
	v.clear(); all.clear();
	FR(i,n)v.push_back(i);
	do
	{
		if(check())
		{
			string t;
			FR(i,n) t+=zip[v[i]];
			all.insert(t);
		}
	}while(next_permutation(ALL(v)));
}

void output()
{
	SS::iterator it=all.begin();
	string res=(*it);
	printf("Case #%d: ",q);	
	cout<<res<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>tc;
	for(q=1;q<=tc;q++)
	{
		input();
		solve();
		output();
	}

	return 0;
}