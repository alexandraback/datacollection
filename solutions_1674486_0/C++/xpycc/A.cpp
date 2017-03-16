#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI v;
int n;

bool u[100];
int t;

bool dfs(int x) {
	for (int i = 0; i < v[x].size(); ++i) {
		int w = v[x][i];
		if (!u[w]) {
			u[w] = true;
			dfs(w);
		} else
			throw true;
	}
}

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		scanf("%d", &n);
		v.clear(); v.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			int c; scanf("%d", &c);
			for (int j = 0; j < c; ++j) {
				int b; scanf("%d", &b);
				v[i].push_back(b);
			}
		}
		bool fg = false;
		try {
			for (int i = 1; i <= n; ++i) {
				memset(u, 0, sizeof u);
				u[i] = true;
				dfs(i);
			}
		} catch (bool) {
			fg = true;
		}
		printf("Case #%d: %s\n", cas, fg ? "Yes" : "No");
	}
	return 0;
}
