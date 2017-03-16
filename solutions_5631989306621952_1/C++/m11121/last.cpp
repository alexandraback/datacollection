#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int t;cin>>t;
	for(int ic=1;ic<=t;++ic)
	{
		string s;
		cin>>s;
		string ans;
		int i=1;
		ans+=s[0];
		cout<<"Case #"<<ic<<": ";
		while(s[i])
		{
			if(s[i]>=ans[0]) ans=s[i]+ans;
			else ans+=s[i];
			++i;
		}
		cout<<ans<<endl;
	}
}
