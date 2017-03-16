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

int t, x, r, c;

string solve_small() {
	if (x == 1) return "GABRIEL";
	if (x == 2 && (r % 2 == 0 || c % 2 == 0)) return "GABRIEL";
	if (x == 3 && (r * c % 3 == 0 && r * c >= 6)) return "GABRIEL";
	if (x == 4 && ((r == 4 && c == 3) || (r == 4 && c == 4) || 
				   (r == 3 && c == 4))) return "GABRIEL";
	return "RICHARD";
}

int main() {
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> x >> r >> c;
		cout << solve_small() << endl;
	}
	return 0;
}
