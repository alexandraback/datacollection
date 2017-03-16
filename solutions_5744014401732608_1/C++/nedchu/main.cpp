#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
const int N = 55;

bool g[N][N];

int main() {
	freopen("out.txt", "w", stdout);
	int t, cas = 1, n;
	LL m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%I64d", &n, &m);
    printf("Case #%d: ", cas++);
    LL mx = 1LL << (n-2);
    puts(m <= mx ? "POSSIBLE" : "IMPOSSIBLE");
    if (m > mx) continue;
    memset(g, 0, sizeof g);
    for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n-1; j++) {
				g[i][j] = true;
			}
    }
    for (int i = n-3; i >= 0; i--) {
			LL cur = 1LL << i;
			if (m >= cur) m -= cur, g[i+1][n-1] = true;
    }
    if (m) g[0][n-1] = true;
    for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", g[i][j]);
			}
			puts("");
    }
	}
	return 0;
}
