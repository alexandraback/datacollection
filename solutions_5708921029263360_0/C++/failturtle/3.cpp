#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) < (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

#define DEBUG

#ifdef DEBUG
#define D(x...) printf(x)
#else
#define D(x...) 
#endif

typedef long long ll;
typedef pair<int,int> ii;

struct state {
	int j, p, s;
	bool operator < (const state &o) const {
		if (j == o.j) {
			if (p == o.p) {
				return s < o.s;
			}
			return p < o.p;
		}
		return j < o.j;
	}
};

map <int, state> m;
map <state, int> r;
int num_cnt[1004];
map <state, int> mm;
map <state, int> M;
map <int, state> R;
int cc[1004];
int nq[1004];
int alive[1004];
set <pair <int, state> >e;

void minu (int a, int b, int c) {
	int &num = nq[M[{a,b,c}]];
	if (e.find({num,{a,b,c}}) != e.end()) {
		e.erase(e.find({num,{a,b,c}}));
		num--;
		e.insert({num,{a,b,c}});
	}
}

void die (int a, int b, int c) {
	D("killing %d %d %d\n", a, b,c );
	if (alive[r[{a,b,c}]] == 0) {
		return;
	}
	alive[r[{a,b,c}]] = 0;
	minu(a,b,0);
	minu(a,0,c);
	minu(0,b,c);
}

map <state, int> qq;

int k;

int get(state dd) {
	int a = dd.j;
	int b = dd.p;
	int c = dd.s;
	int tot = 0;
	if (qq[{a,b,0}] > k) tot += qq[{a,b,0}];
	if (qq[{a,0,c}] > k) tot += qq[{a,0,c}];
	if (qq[{0,b,c}] > k) tot += qq[{0,b,c}];
	return tot;
}
vector <state> dank;

int main() {
	int t;
	scanf("%d\n", &t);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: ", _);
		dank.clear();
		int j, p, s;
		scanf("%d %d %d %d", &j, &p, &s, &k);
		vector <state> v;
		fo(wer,0,2345) {
			v.clear();
			for (int a = 1; a <= j; a++)  {
				for (int b = 1; b <= p; b++) { 
					for (int c = 1; c <= s; c++) {
						v.pb({a,b,c});
					}	
				}
			}
			random_shuffle(v.begin(), v.end());
			while (1) {
				vector <state> cur;
				qq.clear();
				for (auto it : v) {
					qq[{0, it.p, it.s}]++;
					qq[{it.j, 0, it.s}]++;
					qq[{it.j, it.p, 0}]++;
				}
				int big = 0;
				for (auto it : qq) {
					big = max(big, it.second);
				}
				if (big <= k) goto out;
				int num = 0;
				fo(i,0,sz(v)) {
					if (get(v[i]) > get(v[num]))
						num = i;
				}
				fo(i,0,sz(v)) {
					if (num != i) {
						cur.pb(v[i]);
					}
				}
				swap(v, cur);
			}
out:;
	if (sz(v) > sz(dank)) swap(dank, v);
		}
		swap(dank, v);
		printf("%d\n", sz(v));
		for (auto dd : v) {
			int a = dd.j;
			int b = dd.p;
			int c = dd.s;
			printf("%d %d %d\n", a, b, c);
		}
	}

	return 0;
}
