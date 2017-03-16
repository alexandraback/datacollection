#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	cin >> T;
	for(int tk = 0; tk < T; ++tk)
	{
		int S; cin >> S;
		string s;
		cin >> s;
		int tot = 0, ans = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '0') continue;
			if(tot < i)
			{
				ans += i - tot;
				tot = i;
			}
			tot += s[i] - '0';
		}
		printf("Case #%d: %d\n", tk + 1, ans);	
	}
}
