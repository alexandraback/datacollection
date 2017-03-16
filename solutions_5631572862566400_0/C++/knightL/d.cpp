#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctype.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

const int MAXN=10;

int n;
int adj[MAXN][MAXN];
int ord[MAXN];
int used[MAXN];

int brute(int len)
{
	int res=0;
	bool isFine=true;
	for(int i=1;i+1<len;i++)
	{
		int cur=ord[i];
		int prv=ord[(i+len-1)%len];
		int nxt=ord[(i+1)%len];
		isFine&=(adj[cur][prv] || adj[cur][nxt]);
	}
	if(!isFine) return 0;

	if(len>1)
	{
		bool ok=true;
		REP(i,len)
		{
			int cur=ord[i];
			int prv=ord[(i+len-1)%len];
			int nxt=ord[(i+1)%len];
			ok&=(adj[cur][prv] || adj[cur][nxt]);
		}
		if(ok) res=max(res, len);
	}

	REP(i,n)
		if(!used[i])
		{
			used[i]=true;
			ord[len]=i;
			res=max(res, brute(len+1));
			used[i]=false;
		}

	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		memset(adj,0,sizeof(adj));

		scanf("%d",&n);
		REP(i,n)
		{
			int f;
			scanf("%d",&f);
			f--;
			adj[i][f]=true;
		}
		int res=brute(0);
		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
