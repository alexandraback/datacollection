#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it,V) for(__typeof__(V.begin()) it = V.begin(); it != V.end(); ++it)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
typedef long long LL;

 int liczba[25];
 int kandydat[25];

 bool iteruj(int n, int m) {
 	int latacz = 0;
 	while (liczba[latacz] == m) {
 		liczba[latacz] = 2;
 		++latacz;
 	}
 	++liczba[latacz];
 	if (latacz == n) {
 		return false;
 	}
 	return true;
 }

int main() {
	int t;
	scanf("%d", &t);
  printf("Case #1:\n");
  int r, n, m, k;
  scanf("%d%d%d%d", &r, &n, &m, &k);
  REP(o,r) {
  	set<LL> mnozniki;
  	REP(j,k) {
  		LL x;
  		scanf("%lld", &x);
  		mnozniki.insert(x);
  	}
  	REP(i,n+5) {
  		liczba[i] = 2;
  	}

  	bool printed = false;
  	do {
  		set<LL> produkty;
  		produkty.clear();
  		REP(i,1<<n) {
  			LL produkt = 1;
  			REP(j,n) if (i & (1<<j)) {
  				produkt *= liczba[j];
  			}
  			produkty.insert(produkt);
  		}
  		bool ok = true;
  		FORE(it, mnozniki) if (!produkty.count(*it)) { ok = false; break; }
  		if (ok) {
  			REP(i,n) printf("%d", liczba[i]);
  			printf("\n");
  			printed = true;
  			break;
  		}
  	} while (iteruj(n, m));
  	if (!printed) {
  		REP(i,n) printf("%d", liczba[i]);
  			printf("\n");
  	}
  }

}
