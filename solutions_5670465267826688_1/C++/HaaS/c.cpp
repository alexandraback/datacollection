#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define div shit

typedef long long ll;
typedef pair <int, int> pie;

const int table[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 3, 4 },
	{ 0, 2, -1, 4, -3 },
	{ 0, 3, -4, -1, 2 },
	{ 0, 4, 3, -2, -1 },
};


const string Map = " 1ijk";

int mul (int a, int b) {
	int res = table[abs(a)][abs(b)];
	if (a * b < 0) res *= -1;
	return res;
}

int div (int a, int b, bool inv = false) {
	for (int i = -4; i <= 4; i++) {
		if (!inv && mul (b, i) == a) return i;
		if ( inv && mul (i, b) == a) return i;
	}
	cerr << "shit" << endl; 
	exit(1);
}

void solve(stringstream &out) {
	int n, x; cin >> n >> x;
	string s; cin >> s;
	vector <int> partial (n + 1, 1);
	set <int> exist;
	exist.insert (1);
	for (int i = 1; i <= n; i++) {
		partial[i] = mul(partial[i - 1], Map.find (s[i - 1]));
		exist.insert (partial[i]);
	}
	int all = partial[n];
	for (int i = 0, A = 1; i < 4; i++, A = mul (A, all))
		for (int j = 0, B = 1; j < 4; j++, B = mul (B, all))
			for (int k = 0, C = 1; k < 4; k++, C = mul (C, all)) {
				int rem = x - i - j - k - 2, req;
				if (rem < 0 || rem % 4) continue;
				req = div (2, A);
				if (!exist.count (req)) continue;
				int OB = mul (div (all, req), B);
				req = div (3, OB);
				if (!exist.count (req)) continue;
				int OC = mul (div (all, req), C);
				if (OC != 4) continue;
				out << "YES"; return;
			}

	for (int i = 0, A = 1; i < 4; i++, A = mul (A, all))
		for (int k = 0, C = 1; k < 4; k++, C = mul (C, all)) {
			int rem = x - i - k - 1;
			if (rem < 0 || rem % 4) continue;
			int areq = div (2, A), creq = div (4, C, true), breq = mul (areq, 3);
			if (mul (breq, creq) != all) continue;
			for (int z = 0; z < n; z++) if (partial[z] == areq)
				for (int y = z + 1; y <= n; y++) if (partial[y] == breq) {
					out << "YES"; return;
				}
		}

	out << "NO";
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		cerr << "test " << o << endl;
		stringstream out;
		solve(out);
		cout << "Case #" << o << ": " << out.str() << endl; 
		// clean your things!
	}

	return 0;
}
