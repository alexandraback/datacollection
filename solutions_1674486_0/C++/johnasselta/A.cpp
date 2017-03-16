#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 1007
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

int t,n,m,a,start;
int ile[MAXN],posiada[MAXN][MAXN];
vector<int> baza[MAXN],byly[MAXN];
bool dasie;

int main()
{
	scanf("%d",&t);
	REP(g,t)
	{
		scanf("%d",&n);
		FOR(i,1,n)
		{
			scanf("%d",&m);
			REP(j,m) 
			{
				scanf("%d",&a); 
				++ile[a]; 
				baza[i].PB(a);
			}
		}
		FOR(i,1,n)
		{
			FOR(j,1,n) if (ile[j] == 0) start = j;
			ile[start] = -1;
			FOREACH(it,baza[start])
			{
				int nast = *it;
				--ile[nast];
				FOREACH(it2,byly[start])
				{
					if (posiada[nast][*it2]) {dasie = true; break;}
					else
					{
						posiada[nast][*it2] = 1;
						byly[nast].PB(*it2);
					}
				}
				byly[nast].PB(start);
				posiada[nast][start] = 1;
				if (dasie) break;
			} 
			if (dasie) break;
		}
		if (dasie) printf("Case #%d: Yes\n",g+1); else printf("Case #%d: No\n",g+1);
		
		dasie = false;
		FOR(i,1,n) {ile[i] = 0; baza[i].clear(); byly[i].clear();}
		FOR(i,1,n) FOR(j,1,n) posiada[i][j] = 0;
	}
	return 0;
}
