#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	static int table[8][8] = {
		{ 0, 1, 2, 3, 4, 5, 6, 7 },
		{ 1, 4, 3, 6, 5, 0, 7, 2 },
		{ 2, 7, 4, 1, 6, 3, 0, 5 },
		{ 3, 2, 5, 4, 7, 6, 2, 0 },
		{ 4, 5, 6, 7, 0, 1, 2, 3 },
		{ 5, 0, 7, 2, 1, 4, 3, 6 },
		{ 6, 3, 0, 5, 2, 7, 4, 1 },
		{ 7, 6, 1, 0, 3, 2, 6, 4 },
	};

	for (int case_no = 1; case_no <= t; ++case_no)
	{
		cout << "Case #" << case_no << ": ";
		long long l, x;
		string line;
		cin >> l >> x >> line;
		x = min(x, x % 4 + 12);
		string s;
		for (int i = 0; i < x; ++i)
			s += line;
		vector<int> dp(s.size());
		dp[0] = s[0] - 'h';
		for (int i = 1; i < dp.size(); ++i)
			dp[i] = table[dp[i - 1]][s[i] - 'h'];
		if (dp.back() == 4)
		{
			bool flag = false;
			for (int i = 0; i < dp.size() - 2; ++i)
				if (dp[i] == 1)
				{
					for (int j = i + 1; j < dp.size() - 1; ++j)
						if (dp[j] == 3)
						{
							flag = true;
							break;
						}
					break;
				}
			if (flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}
}