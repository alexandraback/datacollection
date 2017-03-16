#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
bool c[10][10], use[10];
int v[10];
int testnum, n, m, a, b;
vector<int> ans, cur;
stack<int> s;
void p(int dep) {
	if (dep == 0) {
		if (cur < ans) ans = cur;
		return;
	}
	stack<int> os = s;
	for (int i = 0;i < n;i++) if (!use[i]) {
		s = os;
		bool suc = false;
		if (s.empty()) {
			suc = true;
		} else {
			while (!s.empty() && !c[s.top()][i]) s.pop();
			if (!s.empty()) {
				suc = true;
			}
		}
		if (!suc) continue;
		s.push(i);
		cur.push_back(v[i]);
		use[i] = true;
		p(dep - 1);
		use[i] = false;
		cur.pop_back();
	}
	s = os;
}
int main() {
	scanf("%d", &testnum);
	for (int test = 1; test <= testnum; test++) {
		scanf("%d%d", &n, &m);
		ans.clear();
		cur.clear();
		while (!s.empty()) s.pop();
		memset(use, false, sizeof(use));
		for (int i = 0;i < n;i++) {
			scanf("%d", &v[i]);
			ans.push_back(99999);
		}
		memset(c, 0, sizeof(c));
		for (int i = 0;i < m;i++) {
			scanf("%d%d", &a, &b); a--; b--;
			c[a][b] = c[b][a] = true;
		}
		p(n);
		printf("Case #%d: ", test);
		for (int i = 0;i < n;i++)
			printf("%d", ans[i]);
		puts("");
	}
	return 0;
}
