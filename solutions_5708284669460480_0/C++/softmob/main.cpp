
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <stdint.h>
#include <iomanip>
using namespace std;

class Solution
{
public:
	void run(int test)
	{
		int k, l, s;
		cin >> k >> l >> s;
		string key, str;
		cin >> key >> str;
		map<char, int> q;
		for (int i = 0; i < key.size(); ++i)
		{
			++q[key[i]];
		}
		cout << "Case #" << test << ": ";
		for (int i = 0; i < str.size(); ++i)
		{
			if (!q.count(str[i]))
			{
				printf("%.6f\n", 0.0);
				return;
			}
		}
		double ans = 1.0;

		for (int i = 0; i < str.size(); ++i)
		{
			ans *= (1.0 * q[str[i]]) / k;
		}
		int mx = 0;
		string ost;
		for (int i = 1; i < str.size(); ++i)
		{
			string tmp = str.substr(i);
			string tmp2 = str.substr(0, tmp.size());		
			if (tmp == tmp2)
			{
				mx = i;
				//ost = tmp;
				break;
			}
		}
		double cur = s / l;
		if (mx)
		{
			int r = str.size();
			cur = 1;
			while (r <= s)
			{
				r += ost.size();
				++cur;
			}
		}
		ans *= cur;
		ans = cur - ans;
		printf("%.6f\n", ans);
	}
private:

};

int main(void)
{
#if 1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution test;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		test.run(i);
	}
	return 0;
}