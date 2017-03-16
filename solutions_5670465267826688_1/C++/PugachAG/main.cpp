#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <map>
#include <cctype>

using namespace std;

int mult(int a, int b)
{
	if (a == 1 || b == 1)
		return a * b;
	int sign = (abs(a) / a) * (abs(b) / b);
	a = abs(a);
	b = abs(b);
	if (sign < 0)
		return -1 * mult(a, b);
	if (a == b)
		return -1;
	if (a == 2 && b == 3)
		return 4;
	if (a == 2 && b == 4)
		return -3;
	if (a == 3 && b == 4)
		return 2;
	return -mult(b, a);
}

int ch_int(char ch)
{
	if (ch == 'i')
		return 2;
	if (ch == 'j')
		return 3;
	if (ch == 'k')
		return 4;
}

bool solve(string &str)
{
	bool f1 = false;
	bool f2 = false;
	int cur = 1;
	for (char ch : str)
	{
		int n = ch_int(ch);
		cur = mult(cur, n);
		if (f1 && cur == 4)
			f2 = true;
		if (cur == 2)
			f1 = true;
	}
	return f1 && f2 && (cur == -1);
}

int main()
{
	freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
	long long t, l, x;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> l >> x;
		long long tmp_x = x % 100ll;
		string s, str, str2;
		cin >> s;
		while (tmp_x--)
			str2 += s;
		bool res = solve(str2);
		cout << "Case #" << i + 1 << ": " << (res ? "YES" : "NO") << endl;
	}
}