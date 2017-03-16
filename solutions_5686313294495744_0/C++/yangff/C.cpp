#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

char buf1[22], buf2[22];

vector<int> G[5555];
int matching[5555];
int check[5555];

bool dfs(int u) {
	for (vector<int>::iterator i = G[u].begin(); i != G[u].end(); i++) {
		int v = *i;
		if (!check[v]) {
			check[v] = true;
			if (matching[v] == -1 || dfs(matching[v])) {
				matching[v] = u;
				matching[u] = v;
				return true;
			}
		}
	}
	return false;
}


int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		map<string, int> dx; int cntx = 0;
		map<string, int> dy; int cnty = 0;

		scanf("%d", &n);
		string x, y;
		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 0; i < n; i++){
			scanf("%s%s", buf1, buf2);
			x = buf1; y = buf2; int ix, iy;
			if (dx.find(x) != dx.end()) {
				ix = dx[x];
			} else {
				ix = cntx++; dx[x] = ix;
			}if (dy.find(y) != dy.end()) {
				iy = dy[y];
			} else {
				iy = cnty++; dy[y] = iy;
			}
			G[ix].push_back(iy + 1001);
			G[iy + 1001].push_back(ix);
		}

		int ans = 0;
		memset(matching, -1, sizeof(matching));
		for (int i = 0; i < cntx; i++) {
			if (matching[i] == -1) {
				memset(check, 0, sizeof(check));
				if (dfs(i))
					ans++;
			}
		}
		printf("%d\n", n - (cntx + cnty - ans));
	}
}