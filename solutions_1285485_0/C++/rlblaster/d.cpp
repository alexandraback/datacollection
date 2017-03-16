#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define maxit(x,y) ((x) = max((x),(y)))
#define minit(x,y) ((x) = min((x),(y)))
typedef long long LL;

bool was[4][2000][2000];

bool wasat(int dir, int dr, int dc)
{
	if (dr >= 2000 || dc >= 2000) return true;
	int g = __gcd(dr, dc);
	dr /= g;
	dc /= g;
	return was[dir][dr][dc];
}

void setat(int dir, int dr, int dc)
{
	if (dr >= 2000 || dc >= 2000) return;
	int g = __gcd(dr, dc);
	dr /= g;
	dc /= g;
	was[dir][dr][dc] = true;
}

int main()
{
	setlinebuf(stdout);
	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		memset(was, 0, sizeof was);
		int R, C, D;
		int rr = -1, cc = -1;
		scanf("%d %d %d", &R, &C, &D);
		for (int r = 0; r < R; ++r) {
			char buf[256];
			scanf("%s", buf);
			char *p = strchr(buf, 'X');
			if (p != NULL) {
				rr = r;
				cc = p - buf;
			}
		}
		long r1 = 1 + 2*(rr - 1);
		long r2 = 1 + 2*(R-2 - rr);
		long c1 = 1 + 2*(cc - 1);
		long c2 = 1 + 2*(C-2 - cc);
		int result = 0;
		for (int r = 0; r < 1600; ++r) {
			for (int c = 0; c < 1600; ++c) {
				if (r == 0 && c == 0) continue;

				long dr1 = (r-1)*2*(R-2) + r1 + ((1-r%2)?r2:r1);
				long dr2 = (r-1)*2*(R-2) + r2 + ((1-r%2)?r1:r2);
				if (r == 0) dr1 = dr2 = 0;
				long dc1 = (c-1)*2*(C-2) + c1 + ((1-c%2)?c2:c1);
				long dc2 = (c-1)*2*(C-2) + c2 + ((1-c%2)?c1:c2);
				if (c == 0) dc1 = dc2 = 0;

				int cnt = 0;

				if (r == 0) {
					if (!wasat(0, dr1, dc1) && dc1*dc1 <= 4*D*D) cnt += 1;
					setat(0, dr1, dc1);
					if (!wasat(1, dr1, dc2) && dc2*dc2 <= 4*D*D) cnt += 1;
					setat(1, dr1, dc2);
				} else if (c == 0) {
					if (!wasat(2, dr1, dc1) && dr1*dr1 <= 4*D*D) cnt += 1;
					setat(2, dr1, dc1);
					if (!wasat(3, dr2, dc1) && dr2*dr2 <= 4*D*D) cnt += 1;
					setat(3, dr2, dc1);
				} else {
					if (!wasat(0, dr1, dc1) && dr1*dr1 + dc1*dc1 <= 4*D*D) cnt += 1;
					setat(0, dr1, dc1);
					if (!wasat(1, dr2, dc1) && dr2*dr2 + dc1*dc1 <= 4*D*D) cnt += 1;
					setat(1, dr2, dc1);
					if (!wasat(2, dr1, dc2) && dr1*dr1 + dc2*dc2 <= 4*D*D) cnt += 1;
					setat(2, dr1, dc2);
					if (!wasat(3, dr2, dc2) && dr2*dr2 + dc2*dc2 <= 4*D*D) cnt += 1;
					setat(3, dr2, dc2);
				}

				//if (cnt != 0) printf("%d %d => %d\n", r, c, cnt);
				result += cnt;
			}
		}
		printf("Case #%d: %d\n", T, result);
	}
	return 0;
}
