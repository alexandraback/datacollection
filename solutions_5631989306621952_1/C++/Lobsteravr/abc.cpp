#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long



main() {
freopen("linp.txt","r",stdin);
	freopen("louts.txt","w",stdout);

    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        string s;
        cin>>s;
        deque<char> ans;
		for(int i=0;i<s.length();i++)
		{
			if(ans.size()==0)
				ans.push_back(s[i]);
			else
			{
				if(ans[0]<=s[i])
					ans.push_front(s[i]);
				else ans.push_back(s[i]);
					
			}
		}
		cout<<"Case #"<<z<<": ";
		for(int i=0;i<ans.size();i++)
			cout<<ans[i];
		cout<<endl;
    }

	return 0;
}
