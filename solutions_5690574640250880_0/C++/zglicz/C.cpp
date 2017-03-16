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

const int R = 51;
int tab[R][R];
int r, c, m;
bool zmien;
bool ok;

void read() {
	scanf("%d %d %d", &r, &c, &m);
	m = r * c - m;
}

void solve() {
	zmien = false;
	if (r > c) {
		swap(r, c);
		zmien = true;
	}
	if (r == 1) {
		REP(i, m) tab[0][i] = 1;
		tab[0][0] = 2;
	} else if (r == 2) {
		if (m == r * c) {
			REP(i, r) REP(j, c) tab[i][j] = 1;
			tab[0][0] = 2;
		} else if (m == 1) {
			tab[0][0] = 2;
		} else if (m&1 || m == 2) {
			ok = false;
		} else {
			REP(i, r) {
				REP(j, m / 2) tab[i][j] = 1;
			}
			tab[0][0] = 2;
		}
	} else {
		if (m == 1) {
			tab[0][0] = 2;
		} else if (m < 4) {
			ok = false;
		} else {
			REP(i, 2) REP(j, 2) tab[i][j] = 1;
			tab[0][0] = 2;
			m -= 4;
			if (m == 0) return ;
			if (m == 1) {
				ok = false;
				return ;
			}
			tab[0][2] = tab[1][2] = 1;
			m -= 2;
			if (m == 0) return ;
			if (m == 1) {
				ok = false;
				return ;
			}
			tab[2][0] = tab[2][1] = 1;
			m -= 2;
			if (m == 0) return ;
			int ile2woj = min(c - 3, m / 2);
			REP(i, 2) {
				REP(j, ile2woj) {
					--m;
					tab[i][j + 3] = 1;
				}
			}
			ile2woj = min(r-3, m / 2);
			REP(i, 2) {
				REP(j, ile2woj) {
					--m;
					tab[3 + j][i] = 1;
				}
			}
			int x = 2, y = 2;
			while (m) {
				tab[x][y] = 1;
				--m;
				++y;
				if (y == c) {
					y = 2;
					++x;
				}
			}
		}
	}
}

void print(int x) {
	if (x == 0) {
		printf("*");
	} else if (x == 1) {
		printf(".");
	} else {
		printf("c");
	}
}

void print() {
	if (!ok) {
		printf("Impossible\n");
		return ;
	}
	if (zmien) {
		REP(i, c) {
			REP(j, r) {
				print(tab[j][i]);
			}
			printf("\n");
		}
	} else {
		REP(i, r) {
			REP(j, c) {
				print(tab[i][j]);
			}
			printf("\n");
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	REP(z, t) {
		ok = true;
		read();
		printf("Case #%d:\n", z+1);
		REP(i, max(r, c)) REP(j, max(r, c)) tab[i][j] = 0;
		solve();
		print();
	}
}