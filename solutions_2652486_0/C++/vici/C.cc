#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int const maxn = 111;
int r, n, m, k;
int p[maxn];
int x[10], q[maxn];
bool mark[11];

int main() {
	freopen("C-small-1-attempt0.in", "r", stdin); freopen("C-small-ans.txt", "w", stdout);
	//freopen("C-large.in", "r", stdin);  freopen("C-large-ans.txt", "w", stdout);
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d%d", &r, &n, &m, &k);
		printf("Case #%d:\n", ca++);
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < k; ++j) scanf("%d", &p[j]);
			for (int a = 2; a <= m; ++a) {
				for (int b = 2; b <= m; ++b) {
					for (int c = 2; c <= m; ++c) {
						x[0] = a, x[1] = b, x[2] = c;
						int mx = 1 << n;
						for (int d = 0; d < mx; ++d) {
							int tr = 1;
							for (int e = 0; e < n; ++e) {
								if (d >> e & 1) tr *= x[e];
							}
							q[d] = tr;
						}
						memset(mark, 0, sizeof mark);
						int cc = 0;
						for (int d = 0; d < mx; ++d) {
							for (int e = 0; e < k; ++e) {
								if (!mark[e] && q[d] == p[e]) {
									mark[e] = true;
									++cc;
								}
							}
						}
						if (cc == k) {
							goto __skip;
						}
					}
				}
			}
			__skip:;
			printf("%d%d%d\n", x[0], x[1], x[2]);
		}
		
		
		
	}
	return 0;
}



