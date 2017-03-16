#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <map>
#include <set>
#define ll long long
using namespace std;
#define problem "c"

int was[2000010], a, b;

void load()
{
	scanf("%d%d", &a, &b);
}

void solve(int test_number)
{
	cerr << "Case #" << test_number << "\n";

	ll result = 0;
	string s;
	for (int i = a; i <= b; i++)
	{
		if (was[i]) continue;
		int x = i;
		s = "";
		int p = 1;
		while (x)
		{
			s += '0' + (x % 10);
			x /= 10;
			p *= 10;
		}
		reverse(s.begin(), s.end());
		int left = 0;
		int right = i;
		int q = 1;
		int cnt = 0;
		p /= 10;
		for (int i = 0; i < s.size(); i++)
		{
			int n = left + q * right;  //2498454
			if (s[i] != '0' && a <= n && n <= b && !was[n])
			{
				cnt++;
				was[n] = 1;
			}
			right -= p * (s[i] - '0');
			left = left * 10 + (s[i] - '0');
			q *= 10;
			p /= 10;
		}
		result += cnt * (cnt - 1) / 2;
	}
	memset(was + a, 0, sizeof(int) * (b - a + 2));
	cout << "Case #" << test_number << ": " << result << "\n";
}

int main()
{
	freopen(problem ".in", "rt", stdin);
	freopen(problem ".out", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
	return 0;
}

