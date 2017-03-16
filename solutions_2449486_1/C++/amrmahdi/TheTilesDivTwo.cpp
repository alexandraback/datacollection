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

bool isPal(long long n) {
	long long rev = 0;
	long long tmp = n;
	while (n) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev == tmp;
}

int b[105][105];
int r[105], col[105];
int main() {

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

	int cases;

	cin >> cases;

	for (int c = 1; c <= cases; ++c) {
		int n, m;
		cin >> n >> m;
		rep(i, n) rep(j, m) cin >> b[i][j];

		memset(r, 0, sizeof r);
		memset(col, 0, sizeof col);


		rep(i, n) {
			int rm = 0;
			rep(j, m) {
				rm = max(rm, b[i][j]);

			}
			r[i] = rm;
		}

		rep(i, m) {
			int cm = 0;
			rep(j, n) {
				cm = max(cm, b[j][i]);
			}
			col[i] = cm;
		}

		bool no = false;
		rep(i, n) {
			rep(j, m) {
				if(b[i][j] < min(r[i], col[j])) {
					no = true;
					break;
				}
			}
			if(no) {
				break;
			}
		}
		cout << "Case #" << c << ": ";
		if(no) {
			puts("NO");
		} else {
			puts("YES");
		}
	}



	return 0;
}
