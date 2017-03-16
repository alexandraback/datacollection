#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 107
#define MAXVL 100
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

int test,n,m,x;
vector<pair<int,int > > v[MAXVL+3];
bool mozna,mkolumna[MAXN],mwiersz[MAXN];

int main() {
	scanf("%d",&test);
	FOR(g,1,test) {
		mozna = true;
		printf("Case #%d: ",g);
		scanf("%d%d",&n,&m);
		REP(i,max(n,m)) mkolumna[i] = mwiersz[i] = true;
		REP(i,n) REP(j,m) {
			scanf("%d",&x);
			v[x].PB(MP(i,j));
		}
		FORD(i,MAXVL,1) {
			FOREACH(it,v[i]) if (!mwiersz[it->ST] && !mkolumna[it->ND]) mozna = false;
			FOREACH(it,v[i]) mwiersz[it->ST] = false,mkolumna[it->ND] = false;
			v[i].clear();
		}
		if (mozna) puts("YES"); else puts("NO");
	}
	return 0;
}
