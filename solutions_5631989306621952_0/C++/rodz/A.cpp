#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T, cnt = 0;
	cin >> T;
	while(T--)
	{
		string s, ans;
		deque<char> d;
		cin >> s;
		d.push_back(s[0]);
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] >= d.front())
				d.push_front(s[i]);
			else
				d.push_back(s[i]);
		}
		for (int i = 0; i < d.size(); i++)
			ans.push_back(d[i]);	

		cout << "Case #" << ++cnt << ": " << ans << '\n';
	}
	return 0;
}
