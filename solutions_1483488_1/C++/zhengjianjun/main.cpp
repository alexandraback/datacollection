#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;

#define mp make_pair
#define lowbit(x) ((x) & (-(x)))
#define pf(x) ((x) * (x))
#define two(x) (1 << (x))
#define twoL(x) ((llong) 1 << (x))
#define clr(x, c) memset(x, c, sizeof(x))

void ch_max(int &x, int y) {if (x < y) x = y;}
void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;

const int N = 2000005;
int cnt[N], d[N];

void cal_cnt() {
	int i, j, k;
	clr(cnt, 0);
	for (i = 1; i < N; ++i) {
		int tmp = i;
		d[i] = 1;
		while (tmp > 0) {
			cnt[i]++;
			tmp /= 10;
			d[i] *= 10;
		}
	}
}
int n, m;
int b[10];

int main() {
	freopen("GCJ\\C-large.in", "r", stdin);
//	freopen("GCJ\\in.txt", "r", stdin);
	freopen("GCJ\\out.txt", "w", stdout);
	
	int i, j, k, t, nc = 0;
	cal_cnt();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		for (i = n; i <= m; ++i) {
			int tmp = 1;
			int cnt_b = 0;
			for (j = 1; j < cnt[i]; ++j) {
				tmp *= 10;
				int t0 = i % tmp;
				int t1 = i / tmp;
				int t2 = t0 * (d[i] / tmp) + t1;
				if (t2 > i && t2 <= m && d[i] == d[t2]) {
					for (k = 0; k < cnt_b; ++k) if (b[k] == t2) break;
					if (k < cnt_b) continue;
					ans++;
					b[cnt_b++] = t2;
				}
			}
		}
		printf("Case #%d: %d\n", ++nc, ans);
	}
	return 0;
}