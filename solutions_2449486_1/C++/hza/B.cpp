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

const int NUM=100+10;

int n,m;
int g[NUM][NUM],h[NUM],o[NUM];

int Main(int Test)
{
	int i,j;
	memset(h,0,sizeof h);
	memset(o,0,sizeof o);
	scanf("%d%d",&n,&m);
	REP(i,1,n)
		REP(j,1,m)
		{
			scanf("%d",&g[i][j]);
			h[i]=max(h[i],g[i][j]);
			o[j]=max(o[j],g[i][j]);
		}
	REP(i,1,n)
		REP(j,1,m)
			if(min(h[i],o[j])!=g[i][j])
			{
				printf("Case #%d: NO\n",Test);
				return 0;
			}
	printf("Case #%d: YES\n",Test);
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	int T,p=1;
	scanf("%d",&T);
	while(T--)
		Main(p++);
	return 0;
}
