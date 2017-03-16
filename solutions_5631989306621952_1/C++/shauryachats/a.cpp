#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		string s;
		cin>>s;
		string wins;
		wins.insert(wins.end(), s[0]);
		for (int i = 1; i < s.length(); ++i)
		{
			string si = s.substr(i,1);
			if (s[i] >= wins[0])
			{

				wins.insert(0, si);
			}
			else
			{
				wins.insert(wins.end(), s[i]);
			}
		}
		cout<<"Case #"<<t<<": "<<wins<<'\n';

	}
}