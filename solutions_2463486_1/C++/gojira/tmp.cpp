#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

bool isPalindrome(long long x)
{
	char s[30];
	sprintf(s, "%lld", x);
	int l;
	for(l = 0; s[l]; l++);
	for(int i = 0; i < l; i++)
		if (s[i] != s[l - i - 1])
			return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int> p;
	for(int x = 1; x <= (int)1e7; x++)
	{
		if (isPalindrome(x))
		{
			long long X = x;
			X *= x;
			if (isPalindrome(X))
				p.push_back(x);
		}
	}

	int T, i, j, k;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		long long a, b;
		cin >> a >> b;

		int cnt = 0;
		for(i = 0; i < p.size(); i++)
		{
			long long x = p[i];
			x *= x;
			if (a <= x && x <= b)
				++cnt;
		}
		printf("Case #%d: ", t);
		cout << cnt << endl;

	}

	return 0;
}