#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T,no=0;
	cin>>T;
	while(T--)
	{
		cin>>s;
		list<char> res;
		res.push_back(s[0]);
		for(int i=1;i<s.size();i++)
			if(s[i]>=res.front())
				res.push_front(s[i]);
			else
				res.push_back(s[i]);
		string ans;
		for(char c:res) ans.push_back(c);
		cout<<"Case #"<<++no<<": "<<ans<<'\n';
	}
}