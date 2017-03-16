#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int MAXD = 676100;
const int INF = 1e9;
const int MAXW = 1e9;
//const int DELTA = 2 * 1e8;
const int DELTA = 600;

struct vertex {
	vertex *l, *r;
	int min, val;
	bool change;
	vertex():l(NULL), r(NULL), change(false){}
	vertex(int val):l(NULL), r(NULL), min(val), val(val), change(false){}
};

void push(vertex *t, int tl, int tr) {
	//assert(t);//Assert
	if (!t->l) {
		t->l = new vertex();
		t->r = new vertex();
	}
	if (t->change) {
		//assert(t->sum % (tr - tl + 1) == 0);//Assert
		t->r->val = t->val;
		t->l->val = t->val;
		t->l->min = t->l->val;
		t->r->min = t->r->val;
		t->l->change = true;
		t->r->change = true;
		t->change = false;
	}
}

int getmin(vertex *t, int tl, int tr, int l, int r) {
	if (r < tl || tr < l) {
		return INF;
	}
	if (l <= tl && tr <= r) {
		return t->min;
	} else {
		push(t, tl, tr);
		int tm = (tl + tr) / 2;
		return min(getmin(t->l, tl, tm, l, r), getmin(t->r, tm + 1, tr, l, r));
	}
}

void change(vertex *t, int tl, int tr, int l, int r, int d) {
	if (r < tl || tr < l) {
		return;
	}
	if (l <= tl && tr <= r) {
		if (t->min >= d) {
			return;
		}
		if (t->val == t->min) {
			t->change = true;
			t->val = d;
			t->min = d;
		} else {
			//push(t, tl, tr);
			int tm = (tl + tr) / 2;
			if (t->l->min < d) {
				change(t->l, tl, tm, l, r, d);
			}
			if (t->r->min < d) {
				change(t->r, tm + 1, tr, l, r, d);
			}
			if (t->val != t->l->val || t->val != t->r->val) {
				t->val = -1;
			}
			t->min = min(t->l->min, t->r->min);	
		}
	} else {
		push(t, tl, tr);
		int tm = (tl + tr) / 2;
		change(t->l, tl, tm, l, r, d);
		change(t->r, tm + 1, tr, l, r, d);
		if (t->val != t->l->val || t->val != t->r->val) {
			t->val = -1;
		}
		t->min = min(t->l->min, t->r->min);
	}
}

struct attack {
	int l, r, s;
	attack() {}
	attack(int l, int r, int s): l(l), r(r), s(s) {}
};

int wall[2000];

void solve() {
	//fprintf(stderr, "new test\n");
	memset(wall, 0, sizeof(wall));
	int n;
	scanf("%d", &n);
	vector<vector<attack> > ats(MAXD);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int d, cnt, l, r, s, delta_d, delta_p, delta_s;
		scanf("%d%d%d%d%d%d%d%d", &d, &cnt, &l, &r, &s, &delta_d, &delta_p, &delta_s);
		for (int j = 0; j < cnt; ++j) {
			ats[d].push_back(attack(2 * l + DELTA, 2 * r + DELTA - 1, s));
			d += delta_d;
			l += delta_p;
			r += delta_p;
			s += delta_s;
		}
	}
	vertex *root = new vertex(0);
	root->change = true;
	for (int i = 0; i < MAXD; ++i) {
		if (!ats[i].empty()) {
			for (size_t j = 0; j < ats[i].size(); ++j) {
				//int curh = getmin(root, 0, MAXW, ats[i][j].l, ats[i][j].r);
				int curh = INF;
				int l = ats[i][j].l;
				int r = ats[i][j].r;
				for (int k = l; k <= r; ++k) {
					curh = min(curh, wall[k]);
				}
				if (curh < ats[i][j].s) {
					ans++;
				}
			}
			for (size_t j = 0; j < ats[i].size(); ++j) {
				int l = ats[i][j].l;
				int r = ats[i][j].r;
				for (int k = l; k <= r; ++k) {
					wall[k] = max(wall[k], ats[i][j].s);
				}
				//change(root, 0, MAXW, ats[i][j].l, ats[i][j].r, ats[i][j].s);
			}
		}
	}
	printf("%d", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}