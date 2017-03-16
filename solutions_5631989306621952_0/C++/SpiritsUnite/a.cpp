#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		string s;
		deque<char> d;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (d.empty() || s[i] >= d[0])
				d.push_front(s[i]);
			else
				d.push_back(s[i]);
		}
		cout << "Case #" << C << ": ";
		for (int i = 0; i < d.size(); i++)
			cout << d[i];
		cout << '\n';
	}
	return 0;
}
