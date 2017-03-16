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

string solve() {
	if (x >= 7) return "RICHARD";
	if ((r * c) % x != 0) return "RICHARD";
	if (x == 6 && min(r, c) <= 3) return "RICHARD";
	if (x == 5 && min(r, c) < 3) return "RICHARD";
	if (x == 5 && min(r, c) == 3 && max(r, c) < 10) return "RICHARD";
	if (x == 4 && min(r, c) < 3) return "RICHARD";
	if (x == 3 && min(r, c) < 2) return "RICHARD";
	return "GABRIEL";
}

int main() {
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> x >> r >> c;
		cout << solve() << endl;
	}
	return 0;
}
