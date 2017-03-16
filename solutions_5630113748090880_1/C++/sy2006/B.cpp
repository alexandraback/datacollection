#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

template <typename T> inline void R(T &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0' || ch>'9'; ch = getchar());
	for (; ch<='9' && ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int N = 105, M = 3000;
int n, m, a[N][N], ans[N], c[M];
bool valid[N];
void solve(int l, int r) {
	int mi = M, mx = 0, cnt = 0;
	if (l == r) {
		for (int i=1; i<=m; ++i)
			if (valid[i])
				ans[l] = a[i][l];
		return;
	}
	for (int i=1; i<=m; ++i) if (valid[i]) {
		if (a[i][l] < mi) mi = a[i][l], cnt = 1; else
		if (a[i][l] == mi) ++cnt;
		mx = max(mx, a[i][r]);
	}
	vector<int> pos;
	if (cnt > 1) {
		for (int i=1; i<=m; ++i) if (valid[i])
			if (a[i][l] == mi)
				pos.pb(i);
		for (int t=0; t<2; ++t)
			for (int i=l; i<=r; ++i)
				c[a[pos[t]][i]]++;
		for (int i=1; i<=m; ++i) if (valid[i])
			c[a[i][l]]--;
		for (int t=0; t<2; ++t)
			for (int i=l; i<=r; ++i)
				if (c[a[pos[t]][i]]) {
					ans[l] = a[pos[t]][i];
					c[a[pos[t]][i]]--;
				}
		valid[pos[0]] = 0;
		valid[pos[1]] = 0;
		solve(l + 1, r);
	}
	else {
		for (int i=1; i<=m; ++i) if (valid[i])
			if (a[i][r] == mx)
				pos.pb(i);
		for (int t=0; t<2; ++t)
			for (int i=l; i<=r; ++i)
				c[a[pos[t]][i]]++;
		for (int i=1; i<=m; ++i) if (valid[i])
			c[a[i][r]]--;
		for (int t=0; t<2; ++t)
			for (int i=l; i<=r; ++i)
				if (c[a[pos[t]][i]]) {
					ans[r] = a[pos[t]][i];
					c[a[pos[t]][i]]--;
				}
		valid[pos[0]] = 0;
		valid[pos[1]] = 0;
		solve(l, r - 1);
	}
}
void run() {
	scanf("%d", &n);
	m = n * 2 - 1;
	for (int i=1; i<=m; ++i) {
		valid[i] = 1;
		for (int j=1; j<=n; ++j) 
			scanf("%d", &a[i][j]);
	}
	solve(1, n);
	for (int i=1; i<=n; ++i)
		printf("%d ", ans[i]);
	puts("");
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}