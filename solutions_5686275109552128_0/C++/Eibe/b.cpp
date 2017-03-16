#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())
#define init(a,v) memset(a, v, sizeof(a))
#define all(a) a.begin(), a.end()

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int t, d, p;
multiset<int> plates;

int main() {
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		plates.clear();
		cin >> d;
		for (int i = 0; i < d; i++) {
			cin >> p;
			plates.insert(p);
		}
		int specials = 0;
		auto biggest = --plates.end();
		int best = (*biggest);
		while ((*biggest) > 2) {
			int bval = *biggest;
			plates.erase(biggest);
			int p1 = bval / 2;
			int p2 = bval - p1;
			specials++;
			plates.insert(p1);
			plates.insert(p2);
			biggest = --plates.end();
			best = min(best, specials + (*biggest));
		}
		cout << best;
		if (tt != t) cout << endl;
	}
	return 0;
}
