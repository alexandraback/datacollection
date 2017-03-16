#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1100;
const int maxe = 1100000;

struct s1{
	int n, next;
} edge[maxe]; 

int n, ec, phead[maxn], fa[maxn], mark[maxn];
bool ans;

void dfs(int x, int d) {
	for (int i = phead[x]; i; i = edge[i].next) {
		if (ans) { return; }
		int y = edge[i].n;
		if (mark[y] != d) {
			mark[y] = d;
			dfs(y, d);
		} else if (mark[y] == d) {
			ans = true;
			return;
		}
	}
}

int main() {
	int ncase;
	cin >> ncase;
	for (int c = 1; c <= ncase; ++c) {
		cin >> n;
		memset(phead, 0, sizeof(phead));
		ec = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> fa[i];
			for (int j = 1; j <= fa[i]; ++j) {
				int x;
				cin >> x;
				++ec;
				edge[ec].n = i;
				edge[ec].next = phead[x];
				phead[x] = ec;
			}
		}
		memset(mark, 0, sizeof(mark));
		ans = false;
		for (int i = 1; i <= n; ++i) if (fa[i] == 0) {
			dfs(i, i);
			if (ans) { break; }
		}
		cout << "Case #" << c << ": ";
		if (ans) cout << "Yes"; else cout << "No";
		cout << endl;
	}
	return 0;
}
