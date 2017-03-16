#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for (int tc = 1; tc <= t; ++tc)
	{
		string inp;
		cin>>inp;
		deque <char> ans;
		for (int i = 0; i < inp.length(); ++i)
			if(ans.empty() || inp[i] >= ans.front())
				ans.push_front(inp[i]);
			else
				ans.push_back(inp[i]);
		cout<<"Case #"<<tc<<": ";
		for (int i = 0; i < ans.size(); ++i)
			cout<<ans[i];
		cout<<"\n";
	}
	return 0;
}
