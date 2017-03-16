#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const long long coordshift = 1ll << 31;
const long long totalcount = (1ll << 32);
const long long inf = 1ll<<60;

struct node {
	long long L, R;
	long long minim;
	long long prisv;

	node *l, *r;

	node(long long _L, long long _R) {
		l = r = 0;
		L = _L;
		R = _R;
		minim = 0;
		prisv = -1;
	}
};

node *root;

inline void init() {
	root = new node(0, totalcount - 1);
	root->prisv = -1;
}

inline void update(node *cur) {
	long long res = inf;
	res = min(res, max(cur->l->minim, cur->l->prisv));
	res = min(res, max(cur->r->minim, cur->r->prisv));

	cur->minim = res;
}

void clear(node * root) {
	if (!root)
		return;
	clear(root->l);
	clear(root->r);
	delete(root);
}

inline void push(node *cur) {
	if (!cur->l)
		cur->l = new node(cur->L, (cur->L+cur->R)/2);
	if (!cur->r)
		cur->r = new node((cur->L+cur->R) / 2 + 1, cur->R);

	cur->l->prisv = max(cur->l->prisv, cur->prisv);
	cur->r->prisv = max(cur->r->prisv, cur->prisv);
	cur->prisv = -1;
	update(cur);
}

long long query(long long L, long long R, node *cur) {
	if (cur->L > R || L > cur->R )
		return inf;

	if (L <= cur->L && cur->R <= R)
		return max(cur->prisv, cur->minim);

	push(cur);

	long long curres = query(L, R, cur->l);
	curres = min(curres, query(L, R, cur->r));

	return curres;
}

void change(long long L, long long R, node *cur, long long newval) {
	if (cur->L > R || L > cur->R)
		return;

	if (L <= cur->L && cur->R <= R)
	{
		cur->prisv = max(cur->prisv, newval);
		return;
	}

	push(cur);
	change(L, R, cur->l, newval);
	change(L, R, cur->r, newval);
	update(cur);

	return;
}


struct attack {
	long long l, r;
	long long s;

	attack( long long _l, long long _r, long long _s) {
		l = _l;
		r = _r;
		s = _s;
	}
};

vector< long long > s_init, delta_s;
vector< long long > l_init, r_init;
vector< long long > delta_x;
vector< int > delta_d;
vector< int > first_day;
vector< int > attack_count;

map< int, vector< attack > > A;
//map< int, long long > wall_height;
int n;

void solve() {
//	cerr << totalcount << ' ' << inf << endl;
	init();

	cin >> n;
	attack_count.resize(n);
	first_day.resize(n);
	delta_x.resize(n);
	delta_d.resize(n);
	l_init.resize(n);
	r_init.resize(n);
	s_init.resize(n);
	delta_s.resize(n);
	A.clear();
//	wall_height.clear();

	for (int i = 0; i < n; i++) {
		cin >> first_day[i] >> attack_count[i] >> l_init[i] >> r_init[i];
		cin >> s_init[i];
		cin >> delta_d[i];
		cin >> delta_x[i];
		cin >> delta_s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < attack_count[i]; j++) {
			long long l = l_init[i] + j * delta_x[i];
			long long r = r_init[i] + j * delta_x[i];
			long long s = s_init[i] + j * delta_s[i];
			int day = first_day[i] + j * delta_d[i];

			A[day].push_back(attack(l, r, s));
		}
	}

	long long ans = 0;
	map< int, vector< attack > >::iterator it = A.begin();
	for (; it != A.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {

			long long minim = query(it->second[i].l + coordshift,
					it->second[i].r - 1 + coordshift, root);

//			cerr << minim << endl;
			ans += (minim < it->second[i].s ? 1 : 0);
		}

		for (int i = 0; i < it->second.size(); i++) {
			change(it->second[i].l + coordshift,
					it->second[i].r - 1 + coordshift, root, it->second[i].s);

//			long long minim = query(it->second[i].l + coordshift,
//								it->second[i].r - 1 + coordshift, root);
//			cerr << "oilolo " << minim << endl;
		}
	}

	cout << ans << endl;

	clear(root);
	return;
}

int main() {
#ifdef OFFLINE
	freopen("C_input.txt","r", stdin);
	freopen("C_output.txt","w", stdout);
#endif
	int t;
	scanf("%d\n", &t);
	for (int testnum = 0; testnum < t; testnum++) {
		printf("Case #%d: ", testnum + 1);
		solve();
	}
}
