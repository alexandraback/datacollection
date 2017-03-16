#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		string s; cin >> s;
		int ans = 0;
		char cur = '+';
		for (int i = s.size()-1; i >= 0; i--)
		{
			if (s[i] != cur)
			{
				cur = s[i];
				ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
