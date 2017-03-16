#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string str;
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		cout<<"Case #"<<ti<<": ";
		cin>>str;
		str+="+";
		int ans=0;
		for(int i=0;i<str.length()-1;i++)
			if(str[i]!=str[i+1])ans++;
		cout<<ans<<endl;	
	}
	return 0;
}
