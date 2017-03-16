#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int test=1;test<=t;++test)
	{
		string s;
		cin >> s;
		cout << "Case #" << test << ": ";
		while(s.size() and s[s.size()-1]=='+')
			s = s.substr(0,s.size()-1);
		if(s.size()==0)
			cout << 0 << endl;
		else
		{
			int cnt = 1;
			for(int i=1;i<s.size();++i)
				if(s[i]!=s[i-1])
					++cnt;
			cout << cnt << endl;
		}
	}
	return 0;
}
