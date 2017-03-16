#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct score
{
	ll c, j;

	bool operator < (const score & r) const
	{
		ll x = c < j ? j - c : c - j;
		ll y = r.c < r.j ? r.j - r.c : r.c - r.j;
		if (x != y)
			return x < y;
		if (c != r.c)
			return c < r.c;
		return j < r.j;
	}

	score(ll a = 0, ll b = 0):
		c(a), j(b)
	{
	}
};

int main()
{
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		string a, b; cin >> a >> b;
		size_t n = a.size();

		score X(0, LLONG_MAX);

		auto report = [&]() {
			score x(stoll(a), stoll(b));
			if (x < X)
				X = x;
		};

		function<void(size_t, int)> dfs;
		dfs = [&](size_t i, int s) {
			char p = a[i], q = b[i];
			if (s == 0) {
				if (a[i] == '?' && b[i] == '?') {
					a[i] = b[i] = '0';
					if (i + 1 < n) {
						dfs(i + 1, 0);
						a[i] = '1'; b[i] = '0';
						dfs(i + 1, 1);
						a[i] = '0'; b[i] = '1';
						dfs(i + 1, -1);
					}
					else
						report();
				}
				else if (a[i] == '?' && b[i] != '?') {
					a[i] = b[i];
					if (i + 1 < n) {
						dfs(i + 1, 0);
						if (b[i] >= '1') {
							a[i] = b[i] - 1;
							dfs(i + 1, -1);
						}
						if (b[i] <= '8') {
							a[i] = b[i] + 1;
							dfs(i + 1, 1);
						}
					}
				    else
						report();
				}
				else if (a[i] != '?' && b[i] == '?') {
					b[i] = a[i];
					if (i + 1 < n) {
						dfs(i + 1, 0);
						if (a[i] >= '1') {
							b[i] = a[i] - 1;
							dfs(i + 1, 1);
						}
						if (a[i] <= '8') {
							b[i] = a[i] + 1;
							dfs(i + 1, -1);
						}
					}
				    else
						report();
				}
				else {
					if (i + 1 < n) {
						if (a[i] == b[i])
							dfs(i + 1, 0);
						else
							dfs(i + 1, a[i] < b[i] ? -1 : 1);
					}
				    else
						report();
				}
			}
			else {
				if (a[i] == '?')
					a[i] = s < 0 ? '9' : '0';
				if (b[i] == '?')
					b[i] = s < 0 ? '0' : '9';
				if (i + 1 < n)
					dfs(i + 1, s);
			    else
						report();
			}
			a[i] = p; b[i] = q;
		};

		dfs(0, 0);
	    
		cout << "Case #" << (_ + 1) << ": ";
		cout << setw(n) << setfill('0') << X.c << " ";
		cout << setw(n) << setfill('0') << X.j << endl;
	}
	return 0;
}
