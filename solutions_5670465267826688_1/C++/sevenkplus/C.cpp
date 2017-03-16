#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

ll n, m;
string s;

int mul(int x, int y) {
	if (x >= 4) return mul(x-4,y)^4;
	if (y >= 4) return mul(x,y-4)^4;
	if (x == 0) return y;
	if (y == 0) return x;
	if (x == y) return 4;
	if (x == 1 && y == 2) return 3;
	if (x == 2 && y == 3) return 1;
	if (x == 3 && y == 1) return 2;
	if (x == 1 && y == 3) return 2+4;
	if (x == 2 && y == 1) return 3+4;
	if (x == 3 && y == 2) return 1+4;
}

#define N 300010

int c[N];

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> m;
		if (m > 20) m = m%4+20;
		string t;
		cin >> t;
		s = string();
		for (int i = 0; i < m; i ++) s += t;
		n *= m;
		c[0] = 0;
		for (int i = 0; i < n; i ++) {
			int d = 0;
			if (s[i] == 'i') d = 1;
			if (s[i] == 'j') d = 2;
			if (s[i] == 'k') d = 3;
			c[i+1] = mul(c[i], d);
		}
		bool F = false;
		if (c[n] == 4) {
			int fi = -1;
			for (int i = 0; i < n; i ++) 
				if (c[i] == 1) {
					fi = i; break;
				}
			if (fi != -1) {
				int fj = -1;
				for (int i = fi+1; i < n; i ++) 
					if (c[i] == 3) {
						fj = i; break;
					}
				if (fj != -1) {
					F = true;
				}
			}
		}
		printf ("Case #%d: %s\n", __, F?"YES":"NO");
	}
	return 0;
}
