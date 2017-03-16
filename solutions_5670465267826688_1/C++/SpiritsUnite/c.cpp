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
		long long l, x;
		string s;
		cin >> l >> x >> s;
		int r = 0, lr;
		for (int i = 0; i < l; i++) r = mul(r, g[s[i]]);
		if ((x % 2 == 1 && r == -1) || (x % 4 == 2 && r != 0 && r != -1))
		{
			lr = r;
			r = 0;
			long long a = 1ll<<62, b = -1;
			for (long long i = 0; i < l; i++)
			{
				r = mul(r, g[s[i]]);
				if (r == 1) a = min(a, i);
				else if (x > 1 && mul(lr, r) == 1) a = min(a, i + l);
				else if (x > 2 && mul(mul(lr, lr), r) == 1) a = min(a, i + l + l);
				else if (x > 3 && mul(mul(mul(lr, lr), lr), r) == 1) a = min(a, i + l + l + l);
				else if (x > 4 && mul(mul(mul(mul(lr, lr), lr), lr), r) == 1) a = min(a, i + 4*l);
			}
			r = 0;
			for (long long i = l - 1; i >= 0; i--)
			{
				r = mul(g[s[i]], r);
				if (r == 3) b = max(b, l*(x-1) + i);
				else if (x > 1 && mul(r, lr) == 3) b = max(b, l*(x-2) + i);
				else if (x > 1 && mul(r, mul(lr, lr)) == 3) b = max(b, l*(x-3) + i);
				else if (x > 1 && mul(r, mul(lr, mul(lr, lr))) == 3) b = max(b, l*(x-4) + i);
			}
			if (a >= b - 1) cout << "Case #" << C << ": NO\n";
			else cout << "Case #" << C << ": YES\n";
		}
		else cout << "Case #" << C << ": NO\n";
	}
	return 0;
}
