#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 1010;

int n;
string s;
string empty = "";
string f[MAXN][MAXN];

string calc(int l, int r)
{
	if (l == r) return "";
	if (f[l][r].size() == 0)
	{
		char best = s[l];
		for (int i = l + 1; i < r; ++i)
		if (s[i] > best) best = s[i];
		//printf("%d, %d : %c\n", l, r, best);
		for (int i = l; i < r; ++i)
		if (s[i] == best)
		{
			string tmp = empty +  best + calc(l, i) + s.substr(i + 1, r - i - 1);
			if (f[l][r] == "" || tmp > f[l][r]) f[l][r] = tmp;
		}
		//printf("%s\n", f[l][r].c_str());
	}
	return f[l][r];
}

void solve()
{
	getline(cin, s);
	n = s.size();
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= n; ++j)
		f[i][j] = "";
	cout << calc(0, n) << endl;
}

int main()
{
	freopen("a.in", "r", stdin);
	int tt;
	scanf("%d\n", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}