#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

void solve(int test)
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int64_t ans = 0;
	int64_t sum = 0;
	for (int i = 0; i <= n; ++i)
	{
		int64_t cur = i;
		if (sum >= cur)
		{
			sum += (str[i] - '0');
		}
		else
		{
			ans += cur - sum;
			sum += (cur - sum) + (str[i] - '0');
		}
	}
	cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i+1);
	}
	return 0;
}