#include <bits/stdc++.h>
using namespace std;

deque<char > dq;
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;
	cin >> t;
	for (int tt = 1;tt <= t;tt++)
	{
		string s;
		cin >> s;
		dq.push_back(s[0]);
		for (int i = 1;i < s.size();i++)
		{
			char top = dq.front();
			if (top <= s[i])
				dq.push_front(s[i]);
			else
				dq.push_back(s[i]);
		}
		string ans = "";
		while (!dq.empty())
		{
			ans += dq.front();
			dq.pop_front();
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}