#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
int T, n, x;
const int N = 2511;
bool vis[N];
int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &x);
				vis[x] = !vis[x];
			}
		}
		printf("Case #%d:", t);
		for (int i = 1; i < N; ++i) if (vis[i]) printf(" %d", i);
		printf("\n");
	}
}