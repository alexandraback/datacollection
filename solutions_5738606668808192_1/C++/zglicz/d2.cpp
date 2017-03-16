#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
typedef short int sint;

const int N = 16;
VI podzb[N];

void generuj(int n, int x, int y) {
	int tab[n];
	REP(i, n) tab[i] = 0;
	tab[0] = tab[n - 1] = 1;
	int c = n / 2 - 1;
	REP(i, c) {
		if (x & (1 << i)) {
			tab[1 + 2*i] = 1;
		}
		if (y & (1 << i)) {
			tab[2 + 2*i] = 1;
		}
	}
	REP(i, n) printf("%d", tab[i]); printf(" ");
	FOR(i, 3, 11) printf("%d ", i); printf("\n");
	FOR(j, 2, 10) {
		LL num = 0;
		REP(i, n) {
			num = (num * j) + tab[i];
		}
		//printf("liczba %d: %lld\n", j, num);
	}
}

void solve() {
	int n, j;
	cin >> n >> j;
	int ile = 0;
	int c = n / 2 - 1;
	REP(i, 1 << c) {
		int cnt = __builtin_popcount(i);
		podzb[cnt].PB(i);
		//printf("adding: %d - %d\n", cnt, i);
	}
	int t;
	//printf("c: %d\n", c);
	REP(i, c + 1) {
		REP(ii, SIZE(podzb[i])) {
			if (ile >= j) break;
			REP(jj, SIZE(podzb[i])) {
				if (ile >= j) break;
				generuj(n, podzb[i][ii], podzb[i][jj]);
				++ile;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	FOR(i, 1, t) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}
}