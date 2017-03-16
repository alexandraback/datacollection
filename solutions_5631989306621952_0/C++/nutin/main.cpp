#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
//	ofstream fout("out.txt");
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		string s;
		cin >> s;
		string ans;
		ans = s[0];
		for (int j = 1; j < s.size(); ++j)
		{
			if (ans[0] <= s[j])
			{
				ans = s[j] + ans;
			}
			else
			{
				ans = ans + s[j];
			}
		}
		printf("Case #%d: %s\n", i + 1, ans.c_str());
	}
	return 0;
}

