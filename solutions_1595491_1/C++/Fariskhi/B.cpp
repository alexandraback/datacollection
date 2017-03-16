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
#define INF64 9200000000000000000LL
#define eps 1e-9
 
#define DEBUG printf("===DEBUG===\n")
#define DEBUGX(a) cout << "DEBUG : " << a << endl
#define TC(a) while (a--)
 
#define PB push_back
#define MP make_pair
#define fi first
#define se second
 
#define REP(a,b) for (int a = 0; a < b; a++)
#define FORN(a,b,c) for (int a = b; a <= c; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)

int t,n,s,p;
int g[111];
int ans;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&t);
	FORN(tc,1,t)
	{
		scanf("%d %d %d",&n,&s,&p); REP(i,n) scanf("%d",&g[i]);
		sort(g,g+n);
		ans = 0;
		REP(i,n)
		{
			if (g[i] < p) continue;
			if (g[i] % 3 == 0)
			{
				if (g[i]/3 >= p){ ++ans; continue; }
				if (g[i]/3+1 >= p && s > 0){ ++ans; --s; continue; }
				continue;
			}
			if (g[i] % 3 == 1)
			{
				if (g[i]/3+1 >= p) ++ans;
				continue;
			}
			if (g[i]/3+1 >= p){ ++ans; continue; }
			if (g[i]/3+2 >= p && s > 0){ ++ans; s--; continue; }
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	
	fclose(stdin); fclose(stdout);
	return(0);
}
