#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <unordered_set>
using namespace std;

string s[20][2];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int n, res = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> s[i][0] >> s[i][1];
		for (int i = 1; i < (1 << n); ++i)
		{
			int cnt = 0;
			unordered_set<string> s1, s2;
			bool check = true;
			for (int j = 0; j < n; ++j)
				if (((1 << j) & i) == 0)
				{
					s1.insert(s[j][0]);
					s2.insert(s[j][1]);
				}
			for (int j = 0; j < n; ++j)
				if ((1 << j) & i)
				{
					cnt++;
					if (s1.find(s[j][0]) == s1.end())
						check = false;
					if (s2.find(s[j][1]) == s2.end())
						check = false;
				}
			if (check)
				res = max(res, cnt);
		}
		
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
