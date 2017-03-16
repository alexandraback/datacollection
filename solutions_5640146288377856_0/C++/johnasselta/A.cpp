#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,n)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 100;

int pom[nax];

int zatopiony(int c, int w) {
	int res = c;
	int ile = 1<<c;
	REP(i,ile) {
		int ilosc = 0;
		int bloki = 0;
		REP(j,c) {
			if (i & (1<<j)) {
				pom[ilosc++] = bloki;
				bloki = -1;
			}
			++bloki;
		}
		pom[ilosc++] = bloki;
		bool mozna = true;
		REP(j,ilosc) if (pom[j] >= w)
			mozna = false;
		
		if (!mozna)
			continue;
		
		//puts("bloki");
		//REP(j,ilosc) printf("%d ",pom[j]); puts("");
		
		REP(j,ilosc-1) {
			res = min(res, ilosc-1 + w-1 + (pom[j] + pom[j+1] > w-1 ? 1 : 0));
			//printf("%d %d\n",ilosc-1 + w-1,(pom[j] + pom[j+1] > w-1 ? 1 : 0)); 
		}
	}
	
	return res;
}

int testy,r,c,w;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	scanf("%d",&testy);
	FOR(g,1,testy) {
		scanf("%d%d%d",&r,&c,&w);
		//int a = wiem_ze_nie_ma(c,w);
		int b = zatopiony(c,w);
		
		if (r == 1) 
			printf("Case #%d: %d\n",g,b);
		else {
		
		}
	}
	return 0;
}
