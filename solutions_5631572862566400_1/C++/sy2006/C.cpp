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
const int N = 1005;
int n, f[N], deg[N], l[N], mx[N];
bool intree[N];

void topo() {
	int ls = 1, le = 0, x;
	for (int i=1; i<=n; ++i)
		if (!deg[i])
			l[++le] = i;
	for (; ls<=le; ++ls) {
		x = l[ls];
		intree[x] = 1;
		mx[f[x]] = max(mx[f[x]], mx[x] + 1);
		if (!--deg[f[x]])
			l[++le] = f[x];
	}
}
int ans1, ans2;
void solve(int x) {
	int len = 0, s = 0, _x = x;
	do {
		s += mx[x] + 1;
		++len;
		x = f[x];
		intree[x] = 1;
	} while (x != _x);
	if (len <= 2)
		ans1 += s; else
		ans2 = max(ans2, len);
}
void run() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		intree[i] = 0, deg[i] = mx[i] = 0;
	for (int i=1; i<=n; ++i) {
		scanf("%d", &f[i]);
		++deg[f[i]];
	}
	topo();
	ans1 = ans2 = 0;
	for (int i=1; i<=n; ++i) if (!intree[i])
		solve(i);
	printf("%d\n", max(ans1, ans2));
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}