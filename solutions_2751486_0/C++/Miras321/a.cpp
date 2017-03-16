#include <cstdio>
#include <iostream>

using namespace std;

string s;
int n, t;

bool check (char c)
{
	if (c == 'a' || c == 'o' || c == 'i' || c == 'u' || c == 'e')
		return 0;
	return 1;				
}

bool check2 (string s)
{
	if (s.length() < n)
		return 0;

	for (int i = 0; i < (int)s.length() - n + 1; ++i)
	{
		int ok = 1;
		for (int j = 0; j < n; ++j)
			if (!check (s[i + j]))
				ok = 0;
		if (ok)
			return 1;
	}

	return 0;
}

int main()
{
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d", &t);

	for (int i = 1; i <= t; ++i)
	{
		cin >> s >> n;

		int ans = 0;
		for (int l = 0; l < s.length(); ++l)
			for (int len = 1; l + len - 1 < s.length(); ++len)
				ans += check2 (s.substr (l, len));

		printf ("Case #%d: %d\n", i, ans);
	}
}
