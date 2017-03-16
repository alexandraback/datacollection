#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;

int n;
string s;
ll x;

void eval(int &val, bool &neg, char c)
{
	if (c == 'i')
	{
		if (val == 0)
			val = 1;
		else if (val == 1)
		{
			val = 0;
			neg ^= 1;
		}
		else
		{
			if (val == 2)
				neg ^= 1;
			val ^= 1;
		}
	}
	else if (c == 'j')
	{
		if (val == 0)
			val = 2;
		else if (val == 2)
		{
			val = 0;
			neg ^= 1;
		}
		else
		{
			if (val == 3)
				neg ^= 1;
			val ^= 2;
		}
	}
	else
	{
		if (val == 0)
			val = 3;
		else if (val == 3)
		{
			val = 0;
			neg ^= 1;
		}
		else
		{
			if (val == 1)
				neg ^= 1;
			val ^= 3;
		}
	}
	return;
}

bool solve()
{
	cin >> n >> x;
	cin >> s;
	int val = 0;
	bool neg = false;
	for (int i = 0; i < n; i++)
		eval(val, neg, s[i]);
	if (val == 0)
	{
		if (!neg) return false;
		if (x % 2 == 0) return false;
	}
	else
	{
		if (x % 4 != 2) return false;
	}
	s = s + s + s + s;
	int idx1 = -1;
	int idx2 = -1;
	val = 0;
	neg = false;
	for (int i = 0; i < 4 * n; i++)
	{
		eval(val, neg, s[i]);
		if (idx1 == -1 && val == 1 && !neg)
			idx1 = i + 1;
		if (val == 3 && neg)
			idx2 = 4 * n - (i + 1);
	}
//	printf("idx1 = %d, idx2 = %d\n", idx1, idx2);
	if (idx1 == -1 || idx2 == -1) return false;
	ll i2 = x * n - idx2;
	return ((ll)idx1 < i2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
