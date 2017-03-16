#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
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
map<VI, int> cnt;
int n, m, r, t, k;
int main() {
	for(int a = 2; a <= 5; ++a) {
		for(int b = 2; b <= 5; ++b) {
			for(int c = 2; c <= 5; ++c) {
				VI v(0);
				v.pb(a); v.pb(b); v.pb(c);
				sort(all(v));
				if (data.count(v)) continue;
				for(int mask = 0; mask < (1 << L(v)); ++mask) {
					int prod = 1;
					for(int i = 0; i < L(v); ++i) {
						if (mask & (1 << i)) {
							prod *= v[i];
						}
					}
					data[v].insert(prod);
				}
			}
		}
	}
	freopen("C-small-1-attempt0.in", "r", stdin);
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
		for(map<VI, set<int> >::iterator it = data.begin(); it != data.end(); ++it) {
			bool ok = 1;
			for(int i = 0; i < k; ++i) {
				if (!it->y.count(prod[i])) ok = 0;
			}
			if (ok) {
				for(int i = 0; i < L(it->x); ++i) {
					cout << it->x[i];
				}
				cout << endl;
				break;
			}
		}
	}
} 