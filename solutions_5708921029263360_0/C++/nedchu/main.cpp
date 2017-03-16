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
struct Node {
	int a, b, c;
	Node() {}
	Node(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<Node> ans;
map<PII, int> ma[3];
bool vis[15][15][15];

PII get(Node &x) {
	int a = ma[0][{x.a, x.b}];
	int b = ma[1][{x.a, x.c}];
	int c = ma[2][{x.b, x.c}];
	return {a + b + c, max(a, max(b, c))};
}

int main() {
	freopen("out1.txt", "w", stdout);
	int t, cas = 1, a, b, c, k;
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof vis);
		ans.clear();
		for (int i = 0; i < 3; i++) {
			ma[i].clear();
		}
		scanf("%d%d%d%d", &a, &b, &c, &k);
		while (true) {
			Node tempans(-1, -1, -1);
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					for (int k = 0; k < c; k++) {
						Node temp(i, j, k);
						if (vis[i][j][k]) continue;
						if (tempans.a == -1 || get(temp) < get(tempans)) {
							tempans = temp;
						}
					}
				}
			}
			if (tempans.a == -1 || get(tempans).se == k) {
				break;
			} else {
				ma[0][{tempans.a, tempans.b}]++;
				ma[1][{tempans.a, tempans.c}]++;
				ma[2][{tempans.b, tempans.c}]++;
				vis[tempans.a][tempans.b][tempans.c] = true;
				ans.push_back(tempans);
			}
		}
		printf("Case #%d: %d\n", cas++, ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].c + 1);
		}
	}
	return 0;
}
