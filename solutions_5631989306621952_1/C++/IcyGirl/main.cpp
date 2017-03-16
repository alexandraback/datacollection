#include <bits/stdc++.h>
using namespace std;

int T,cas;
string s,res;

int main()
{
	freopen("In","r",stdin);
	freopen("out","w",stdout);
	for(cin>>T;T--;)
	{
		cin>>s; res="";
		for(int i=0;s[i];i++)
			res=max(s[i]+res,res+s[i]);
		cout<<"Case #"<<++cas<<": "<<res<<endl;

	}
	return 0;
}
