#include <bits/stdc++.h>

using namespace std;

int grid[4][4] = {{0, 1, 2, 3}, {1, -1, 3, -3}, {2, -4, -1, 1}, {3, 2, -2, -1}};
int g[200];

int mul(int a, int b) {
	bool neg = false;
	if (a < 0) a = -a - 1, neg = !neg;
	if (b < 0) b = -b - 1, neg = !neg;
	int c = grid[a][b];
	if (neg) c = -c - 1;
	return c;
}

int main() {
	g['i'] = 1;
	g['j'] = 2;
	g['k'] = 3;
	int T;
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		int l, x, n;
		string s;
		cin >> l >> x >> s;
		n = l*x;
		int r = 0;
		for (int i = 0; i < n; i++) r = mul(r, g[s[i%l]]);
		if (r != -1)
		{
			cout << "Case #" << C << ": NO\n";
			continue;
		}
		r = 0;
		int a = -1, b = -1;
		for (int i = 0; i < n; i++)
		{
			r = mul(r, g[s[i%l]]);
			if (r == 1){ a = i; break;}
		}
		r = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			r = mul(g[s[i%l]], r);
			if (r == 3){ b = i; break;}
		}
		if (a == -1) cout << "Case #" << C << ": NO\n";
		else if (b == -1) cout << "Case #" << C << ": NO\n";
		else if (a >= b - 1) cout << "Case #" << C << ": NO\n";
		else cout << "Case #" << C << ": YES\n";
	}
	return 0;
}
