#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double EPS = 1e-9;

const int TREESIZE = 1<<15;

struct intervalTree
{
	pii tree[TREESIZE*2];

	void set(int pos, int val)
	{
		tree[pos+TREESIZE] = pii(val, pos);
		pos += TREESIZE;
		pos /= 2;
		while (pos > 0)
		{
			tree[pos] = max(tree[pos*2], tree[pos*2 + 1]);
			pos /= 2;
		}
	}

	pii getMax(int l, int r)
	{
		l += TREESIZE;
		r += TREESIZE;
		pii ans = max(tree[l], tree[r]);

		while (l/2 != r/2)
		{
			if ((l&1) == 0) ans = max(ans, tree[l+1]);
			if ((r&1) == 1) ans = max(ans, tree[r-1]);
			l /= 2;
			r /= 2;
		}
		return ans;
	}
} I;

ll R, E;
int N;

ll ans = 0;

void solve(int l, int r, int st, int end)
{
	if (r < l) return;
	pii mx = I.getMax(l, r);
	int pos = mx.second;
	ll pst = min(R, (pos - l)*E + st);
	ll pen = max(0ll, end - (r - pos)*E);
	ans += mx.first*(pst - pen);
	solve(l, pos - 1, st, max(0ll, pst - E));
	solve(pos + 1, r, min(R, pen + E), end);
}

void solve()
{
	ans = 0;
	scanf("%lld%lld%d", &R, &E, &N);
	for (int i = 0; i < N; ++i)
	{
		int t;
		scanf("%d", &t);
		I.set(i, t);
	}

	solve(0, N - 1, R, 0);

	printf("%lld\n", ans);
}
int main()
{
	freopen("Btest.txt", "r", stdin);
	freopen("Bout.txt", "w", stdout);

	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		fprintf(stderr, "%d/%d\n", i+1, T);
		solve();
	}
	return 0;
}