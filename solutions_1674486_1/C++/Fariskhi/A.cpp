#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <bitset>
#include <fstream>
using namespace std;
 
#define LL long long
#define INF 2000000000
#define inf 1000000000
#define INF64 9200000000000000000LL
#define eps 1e-9
 
#define DEBUG cout << "DEBUG" << endl
#define DEBUGX(a) cout << "DEBUG : " << a << endl
#define TC(a) while (a--)
 
#define PB push_back
#define MP make_pair
#define fi first
#define se second
 
#define REP(a,b) for (int a = 0; a < b; a++)
#define FORN(a,b,c) for (int a = b; a <= c; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)

bool ok;
int n,m,x;
vector <int> adj[1111];
bool flag[1111];

void dfs(int x)
{
	if (ok) return;
	if (flag[x])
	{
		ok = true;
		return;
	}
	flag[x] = true;
	REP(i,adj[x].size())
	{
		dfs(adj[x][i]);
	}
}

void main_program(void)
{
	scanf("%d",&n);
	ok = false;
	FORN(i,1,n)
	{
		scanf("%d%",&m);
		adj[i].clear();
		REP(j,m)
		{
			scanf("%d",&x);
			adj[i].PB(x);
		}
	}
	FORN(i,1,n)
	{
		memset(flag,false,sizeof(flag));
		dfs(i);
	}
	if (ok) puts("Yes"); else puts("No");
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int tc;
	scanf("%d",&tc);
	for (int i = 1; i <= tc; i++)
	{
		printf("Case #%d: ",i);
		main_program();
	}
	
	fclose(stdin); fclose(stdout);
	return(0);
}
