#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int r, c, m;
int t;
char s[55][55];

int solve(int br, int bc, int ml) {
	int cnt = 0;
	MS(s, '*');
	for (int i = 0; i < br; i += 1) {
		for (int j = 0; j < bc; j += 1) {
			s[i][j] = '.';
		}	
	}

	int orr = br, orc = bc;
	// printf("%d %d\n", r, c);
	while (ml) {
		if (cnt == 0) s[orr - 1][orc - 1] = '*', br--, bc--;
		else {
			if (br - 1 >= min(2, r)) {
				br--;
				s[br][orc - 1] = '*';
			}
			else if (bc - 1 >= min(2, c)) {
				bc--;
				s[orr - 1][bc] = '*';
			}
			else return 0;
		}
		++cnt;
		ml--;
	}
	return br >= min(2, r) && bc >= min(2, c);
}

int main() {
	cin >> t;
	F(z, t) {
		int solved = 0;
		cin >> r >> c >> m;
		for (int i = 0; i < r && !solved; i += 1) {
			for (int j = 0; j < c && !solved; j += 1) {
				// if (i > j) continue;
				int br = i + 1;
				int bc = j + 1;
				int other = r * c - br * bc;
				int minesLeft = m - other;
				// printf("%d %d\n", minesLeft, br + bc - 1);
				if (minesLeft >= 0 && minesLeft <= br + bc - 1) {
					if (solve(br, bc, minesLeft)) {
						solved = 1;
					}
				}
			}
		}
		printf("Case #%d:\n", z + 1);
		if (solved) {
			s[0][0] = 'c';
			F(i, r) {
				F(j, c) printf("%c", s[i][j]); NL;
			}
		} else if (m == r * c - 1) {
			MS(s, '*');
			s[0][0] = 'c';
			F(i, r) {
				F(j, c) printf("%c", s[i][j]); NL;
			}
		} else {
			puts("Impossible");
		}
	}	
	return 0;
}