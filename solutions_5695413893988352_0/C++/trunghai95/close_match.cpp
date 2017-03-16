//brute-force 1000^2
#include <bits/stdc++.h>

using namespace std;

int test;
char C[20], J[20], len;

bool valid(int c, int j)
{
	for (int i = len - 1; i >= 0; --i)
	{
		if (C[i] != '?' && C[i] - '0' != (c % 10))
			return false;
		if (J[i] != '?' && J[i] - '0' != (j % 10))
			return false;
		j /= 10;
		c /= 10;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> test;

	for (int tt = 1; tt <= test; ++tt)
	{
		cin >> C >> J;
		len = strlen(C);
		int mx = 1;
		for (int i = 0; i < len; ++i)
			mx *= 10;
		mx -= 1;

		int res = 1e9, resc = 0, resj = 0;
		for (int c = 0; c <= mx; ++c)
		for (int j = 0; j <= mx; ++j)
		if (valid(c, j) && abs(c-j) < res)
		{
			res = abs(c-j);
			resc = c, resj = j;
		}

		cout << "Case #" << tt << ": ";
		cout << setfill('0') << setw(len) << resc << ' ' << setw(len) << resj << '\n';
	}
	return 0;
}