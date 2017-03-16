#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#define rep(x,n) for(int x=0;x<n;++x)
#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
#define mem(a, b) memset(a, b, sizeof(a))

#define mp(x,y) make_pair(x,y)
#define getBit(code, i) (code & (1 << i))
#define setBit(code, i) (code | (1 << i))
#define xetBit(code, i) (code & ~(1 << i))
#define PI acos(-1.0)
#define oo (int)10e7
#define rd(x) scanf("%d", &x)
#define rdfile(x) freopen(x, "r", stdin)
#define wtfile(x) freopen(x, "w", stdout)
using namespace std;

#define negmod(x, mod) ((x + mod) % mod)

char b[4][4];

int main() {

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

	int cases;

	cin >> cases;

	for (int c = 1; c <= cases; ++c) {
		bool complete = true;
		rep(i, 4) {
			rep(j, 4) {
				cin >> b[i][j];
				if (b[i][j] == '.') {
					complete = false;
				}
			}
		}

		bool x = false, o = false;
		rep(i, 4) {
			int rx = 0, ro = 0, rt = 0, cx = 0, co = 0, ct = 0;
			rep(j, 4) {
				rx += b[i][j] == 'X';
				ro += b[i][j] == 'O';
				rt += b[i][j] == 'T';

				cx += b[j][i] == 'X';
				co += b[j][i] == 'O';
				ct += b[j][i] == 'T';
			}
			if (rx + rt == 4 || cx + ct == 4) {
				x = true;
				break;
			}
			if (ro + rt == 4 || co + ct == 4) {
				o = true;
				break;
			}
		}

		if (!x && !o) {
			int dix = 0, dio = 0, rdx = 0, rdo = 0, dit = 0, rdt = 0;
			rep(i, 4) {
				dix += b[i][i] == 'X';
				dio += b[i][i] == 'O';
				dit += b[i][i] == 'T';

				rdx += b[i][3 - i] == 'X';
				rdo += b[i][3 - i] == 'O';
				rdt += b[i][3 - i] == 'T';
			}

			if (dix + dit == 4 || rdx + rdt == 4) {
				x = true;
			}
			if (dio + dit == 4 || rdo + rdt == 4) {
				o = true;
			}
		}

		cout << "Case #" << c << ": ";

		if (!x && !o) {
			if (complete) {
				puts("Draw");
			} else {
				puts("Game has not completed");
			}
		} else if (x) {
			puts("X won");
		} else {
			puts("O won");
		}

	}

	return 0;
}
