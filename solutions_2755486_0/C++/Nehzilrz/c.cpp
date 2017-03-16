#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define INF 134217728
#define MP make_pair
#define PB push_back

struct SegmentTree {
	struct SegNode {
		int l, r, mid;
		SegNode *lch, *rch;
		int minValue;
		bool c;
		SegNode(int ll, int rr, int mv) : c(0), minValue(mv), l(ll), r(rr), lch(0), rch(0) {
			mid = (l + r + 1) / 2 - 1;
		};
	};
	
	SegNode *root;
	SegmentTree() {
		root = new SegNode(-INF, INF - 1, 0);
	}
	
	int ask(SegNode *x, int l, int r) {
		if (l <= x->l && r >= x->r) {
			return x->minValue;
		}
		if (r <= x->mid) {
			if (!x->lch) x->lch = new SegNode(x->l, x->mid, x->minValue);
			else x->lch->minValue = max(x->lch->minValue, x->minValue);
			return ask(x->lch, l, r);
		}
		else if (l > x->mid) {
			if (!x->rch) x->rch = new SegNode(x->mid + 1, x->r, x->minValue);
			else x->rch->minValue = max(x->rch->minValue, x->minValue);
			return ask(x->rch, l, r);
		}
		else {
			if (!x->lch) x->lch = new SegNode(x->l, x->mid, x->minValue);
			else x->lch->minValue = max(x->lch->minValue, x->minValue);
			if (!x->rch) x->rch = new SegNode(x->mid + 1, x->r, x->minValue);
			else x->rch->minValue = max(x->rch->minValue, x->minValue);
			return min(ask(x->lch, l, r), ask(x->rch, l, r));
		}
	}
	
	int ask(int l, int r) {
		return ask(root, l, r);
	}
	
	int fill(SegNode *x, int l, int r, int m) {
		if (l <= x->l && r >= x->r) {
			if (m <= x->minValue) return 0;
			else { x->minValue = m; return 1; }
		}
		if (r <= x->mid) {
			if (!x->lch) x->lch = new SegNode(x->l, x->mid, x->minValue);
			else x->lch->minValue = max(x->lch->minValue, x->minValue);
			return fill(x->lch, l, r, m);
		}
		else if (l > x->mid) {
			if (!x->rch) x->rch = new SegNode(x->mid + 1, x->r, x->minValue);
			else x->rch->minValue = max(x->rch->minValue, x->minValue);
			return fill(x->rch, l, r, m);
		}
		else {
			if (!x->lch) x->lch = new SegNode(x->l, x->mid, x->minValue);
			else x->lch->minValue = max(x->lch->minValue, x->minValue);
			if (!x->rch) x->rch = new SegNode(x->mid + 1, x->r, x->minValue);
			else x->rch->minValue = max(x->rch->minValue, x->minValue);
			return fill(x->lch, l, r, m) + fill(x->rch, l, r, m);
		}
	}
	
	int fill(int l, int r, int m) {
		return fill(root, l, r, m);
	}
}*st;

int d[1005], n[1005], w[1005], e[1005], s[1005], dd[1005], dp[1005], ds[1005];

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T, nn;
	scanf("%d", &T);
	for (int t0 = 1; t0 <= T; ++t0) {
		int ans = 0;
		st = new SegmentTree;
		scanf("%d", &nn);
		for (int i = 0; i < nn; ++i) {
			scanf("%d%d%d%d%d%d%d%d", d + i, n + i, w + i, e + i, s + i, dd + i, dp + i, ds + i);
			--e[i];
		}
		
		while (1) {
			int m = INF;
			for (int i = 0; i < nn; ++i) if (n[i]) m = min(m, d[i]);
			if (m == INF) break;
			for (int i = 0; i < nn; ++i) if (n[i] && d[i] == m) {
				if (st->ask(w[i], e[i]) < s[i]) ++ans;
			}
			for (int i = 0; i < nn; ++i) if (n[i] && d[i] == m) {
				st->fill(w[i], e[i], s[i]);
				--n[i]; d[i] += dd[i]; s[i] += ds[i];
				w[i] += dp[i]; e[i] += dp[i];
			}
		}
		
		delete st;
		cout << "Case #" << t0 << ": " << ans << endl;
	}
	return 0;
}
