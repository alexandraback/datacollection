#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;
		vector<char> v;
		for (int i = 0; i < s.size(); i++)
		{
			if (v.empty() || v[0] <= s[i])
				v.insert(v.begin(),s[i]);
			else
				v.push_back(s[i]);
		}
		printf("Case #%d: ", t);
		for (auto i : v) cout << i;
		cout << endl;
	}
}
