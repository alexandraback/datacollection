#include <iostream>
using namespace std;
int mul[8][8] = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 4, 3, 6, 5, 0, 7, 2},
	{2, 7, 4, 1, 6, 3, 0, 5},
	{3, 2, 5, 4, 7, 6, 1, 0},
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4}
};
int f(char c)
{
	if (c == 'i')
		return 1;
	if (c == 'j')
		return 2;
	return 3;
}
int main()
{
	ios::sync_with_stdio(false);
	int tt;
	cin >> tt;
	for (int _ = 1; _ <= tt; _++)
	{
		long long l, x;
		cin >> l >> x;
		if (x >= 64)
			x = x % 64 + 64;
		string t;
		cin >> t;
		string s = "";
		for (int i = 0; i < x; i++)
			s += t;
		int c = 0, m = 0;
		for (int i = 0; i < s.size(); i++)
		{
			m = mul[m][f(s[i])];
			if (c == 0)
			{
				if (m == 1)
					c++;
			}
			else if (c == 1)
			{
				if (m == 3)
					c++;
			}
		}
		if (c == 2 && m == 4)
			c++;
		if (c == 3)
			cout << "Case #" << _ << ": YES\n";
		else
			cout << "Case #" << _ << ": NO\n";
	}
	return 0;
}
