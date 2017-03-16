#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define mp make_pair
#define x first
#define y second
#define L(s) ((int)(s).size())
#define pb push_back
#define VI vector<int>
#define ll long long
#define all(v) (v).begin(), (v).end()
int tc;
map<VI, set<int> > data;
vector<pair<ll, VI > > prob;
int n, m, r, t, k;
int inpt[12];
ll c[15][15];
void dfs(int lev) {
	if (lev == 12) {
		VI v(0);
		for(int i = 0; i < 12; ++i) {
			v.pb(inpt[i]);
		}
		sort(all(v));
		data[v].insert(1);
		for(int mask = 0; mask < (1 << L(v)); ++mask) {
			int prod = 1;
			for(int i = 0; i < L(v); ++i) {
				if (mask & (1 << i)) {
					prod *= v[i];
				}
			}
			data[v].insert(prod);
		}
		int tot = L(v);
		ll ways = 1;
		for(int val = 2; val <= 8; ++val) {
			int cnt = 0;
			for(int i = 0; i < L(v); ++i) {
				if (v[i] == val) cnt++;
			}
			ways *= c[tot][cnt];
			tot -= cnt;
		}
		prob.pb(mp(ways, v));
		return;
	}
	int last = 2;
	if (lev) last = inpt[lev - 1];
	for(int i = last; i <= 8; ++i) {
		inpt[lev] = i;
		dfs(lev + 1);
	}
}
int main() {
	for(int i = 0; i < 15; ++i) {
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	/*prob.clear();
	dfs(0);
	sort(all(prob));
	reverse(all(prob));*/
	/*freopen("dump.txt", "w", stdout);
	for(int i = 0; i < L(prob); ++i) {
		for(int j = 0; j < L(prob[i].y); ++j) cout << prob[i].y[j];
		cout << " " << prob[i].x << endl;
	}
	exit(0);*/
	prob.clear();
	ifstream ifs("dump.txt");
	string s; ll val;
	while(ifs >> s >> val) {
		VI v(0);
		for(int i = 0; i < L(s); ++i) v.pb(s[i] - '0');
		prob.pb(mp(val, v));
	}
	sort(all(prob));
	reverse(all(prob));
//	cerr << "Finished\n";
//	int tmp;
//	cin >> tmp;
	freopen("C-small-2-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	cin >> r >> n >> m >> k;
	cout << "Case #1:\n";
	while(r--) {
		cerr << r << endl;
		VI prod(0);
		for(int i = 0; i < k; ++i) {
			int x;
			cin >> x;
			prod.pb(x);
		}
		double bestmul = -1;
		VI bestv(0);
		for(int act = 0; act < L(prob); ++act) {
			VI v = prob[act].y;
			int totmul = 1;
			for(int i = 0; i < L(v); ++i) totmul *= v[i];
			bool ok = 1;
			for(int i = 0; i < k; ++i) if (totmul % prod[i]) ok = 0;
			if (!ok) continue;
			double curmul = prob[act].x;
			int inv[12]; memset(inv, 0, sizeof(inv));
			for(int ch = 2; ch <= 8; ++ch) {
				for(int i = 0; i < L(v); ++i) {
					if (v[i] == ch) inv[ch]++;
				}
			}
			for(int i = 0; i < k; ++i) {
				int x = prod[i];
				for(int ch = 2; ch <= 8; ++ch) {
					int now = 0;
					while(x % ch == 0) {
						x /= ch;
						now++;
					}
					curmul *= c[inv[ch]][now];
				}
			}
			if (curmul > bestmul) {
				bestmul = curmul;
				bestv = v;
			}
		}
		for(int i = 0; i < L(bestv); ++i) {
			cout << bestv[i];
		}
		cout << endl;
	}
} 