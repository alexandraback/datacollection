#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>
#pragma comment(linker, "/STACK:640000000")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
int r,c,m,sx,sy;
char s[55][55];
int was[1 << 25],T = 0;
bool dfs(int mask) {
	if (was[mask] == T) return false;
	was[mask] = T;	
	int M = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			bool ok = false;
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) {
					int x = i + dx;
					int y = j + dy;
					if (x < 0 || x >= r || y < 0 || y >= c) continue;
					if ((mask >> (x * c + y)) & 1) ok = true;
				}
			}
			if (ok) {
				s[i][j] = '.';
			} else {
				s[i][j] = '*';
				M++;
			}
		}
	}
	s[sx][sy] = 'c';
	if (M == m) {
		/*for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				putchar(s[i][j]);
			}
			puts("");
		}*/
		return true;
	}
	if (M < m) return false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) if ((mask >> (i * c + j)) & 1) {
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) if (dx != 0 || dy != 0) {
					int x = i + dx;
					int y = j + dy;
					if (x < 0 || x >= r || y < 0 || y >= c) continue;
					if ((mask >> (x * c + y)) & 1) continue;
					if (dfs(mask | (1 << (x * c + y)))) return true;
				}
			}
		}
	}
	return false;
}
bool get() {
	if (m == 0 || r == 1 || c == 1 || m == r * c - 1) return true;
     for (int R = 0; R <= r - 2; R++) {
     	for (int C = 0; C <= c - 2; C++) if (R * c + C * r - R * C <= m) {
     		int mm = m - R * c - C * r + R * C;
     		if (mm == 0) return true;
     		if (c - C > 2 && r - R > 2 && mm <= c - C - 2 + r - R - 2 - 1) return true;
     	}
     }
     return false;
}
bool get2() {
	if (m == r * c - 1) return true;
	++T;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sx = i;
			sy = j;
			if (dfs(1 << (i * c + j))) {
				return true;
			}	
		}
	}
	return false;
}
void solve() {	
	/*for (r = 1; r <= 5; r++) {
		for (c = 1; c <= 5; c++) {
			for (m = 0; m < r * c; m++) {
				if (get() != get2()) cout << r << " " << c << " " << m << " " << get() << " " << get2() << endl;
			}
		}
	}*/
	cin >> r >> c >> m;
	if (m == 0) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == 0 && j == 0) {
					putchar('c');
				} else {
					putchar('.');
				}
			}
			puts("");
		}
	} else if (r == 1) {
     	for (int i = 0; i < c; i++) {
     		if (i == 0) {
     			putchar('c');
     		} else if (i < c - m) {
     			putchar('.');
     		} else {
     			putchar('*');
     		}
     	}
     	puts("");
     } else if (c == 1) {
     	for (int i = 0; i < r; i++) {
     		if (i == 0) {
     			puts("c");
     		} else if (i < r - m) {
     			puts(".");
     		} else {
     			puts("*");
     		}
     	}
     } else if (m == r * c - 1) {
     	for (int i = 0; i < r; i++) {
     		for (int j = 0; j < c; j++) {
     			if (i == 0 && j == 0) {
     				putchar('c');
     			} else {
     				putchar('*');
     			}
     		}
     		puts("");
     	}
     } else {
     	for (int R = 0; R <= r - 2; R++) {
	     	for (int C = 0; C <= c - 2; C++) if (R * c + C * r - R * C <= m) {
	     		int mm = m - R * c - C * r + R * C;
	     		if (mm == 0) {
	     			for (int i = 0; i < r; i++) {
	     				for (int j = 0; j < c; j++) {
	     					if (i == 0 && j == 0) {
	     						putchar('c');
	     					} else if (i < r - R && j < c - C) {
	     						putchar('.');
	     					} else {
	     						putchar('*');
	     					}
	     				}
	     				puts("");
	     			}
	     			return;
	     		}
	     		if (c - C > 2 && r - R > 2 && mm <= c - C - 2 + r - R - 2 - 1) {
	     			for (int i = 0; i < r; i++) {
	     				for (int j = 0; j < c; j++) {
	     					if (i == 0 && j == 0) {
	     						s[i][j] = 'c';
	     					} else if (i < r - R && j < c - C) {
	     						s[i][j] = '.';
	     					} else {
	     						s[i][j] = '*';
	     					}
	     				}
	     			}
	     			int x = r - R - 1;
	     			int y = c - C - 1;
	     			for (int i = 0; x - i >= 2 && mm > 0; i++) {
	     				s[x - i][y] = '*';
	     				mm--;
	     			}
	     			for (int j = 1; y - j >= 2 && mm > 0; j++) {
	     				s[x][y - j] = '*';
	     				mm--;
	     			}
	     			for (int i = 0; i < r; i++) {
	     				for (int j = 0; j < c; j++) {
	     					putchar(s[i][j]);
	     				}
	     				puts("");
	     			}
	     			return;
	     		}
     		}
	     }
	     puts("Impossible");
     }
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int Cases; cin >> Cases;
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d:\n",Case);
		solve();
	}
	return 0;
}
