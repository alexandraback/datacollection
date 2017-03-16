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

inline void ch_max(int &x, int y) {if (x < y) x = y;}
inline void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;


const int N = 1005;
int n, a[N], b[N];
int ok[N][2];

priority_queue< pii > que;

int main() {
	//freopen("GCJ\\in.txt", "r", stdin);
	freopen("GCJ\\B-large.in", "r", stdin);
	freopen("GCJ\\out.txt", "w", stdout);
	int i, j, k, t, nc = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
		}
		clr(ok, 0);
		int ans = 0, sum = 0, work = 0;
		while (1) {
			while (!que.empty()) que.pop();
			for (i = 0; i < n; ++i) {
				if (!ok[i][1]) que.push(mp(-b[i], i));
			}

			while (que.size() > 0 && -que.top().first <= sum) {
				k = que.top().second;
				if (ok[k][0]) sum++;
				else sum += 2;
				ok[k][1] = 1;
				ans++;
				que.pop();
			}
			if (que.size() == 0) {
				work = 1;
				break;
			}
			int tmax = 0;
			for (i = 0, k = -1; i < n; ++i) {
				if (!ok[i][1] && !ok[i][0]) {
					if (a[i] <= sum && b[i] > tmax) {
						tmax = b[i];
						k = i;
					}
				}
			}
			if (k == -1) break;
			ok[k][0] = 1;
			sum++;
			ans++;
		}
		if (work) printf("Case #%d: %d\n", ++nc, ans);
		else printf("Case #%d: Too Bad\n", ++nc);
	}
	return 0;
}