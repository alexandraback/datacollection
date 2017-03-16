#include <iostream>
#include <cstdio>
using namespace std;
char c[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	freopen("gcj.out","w",stdout);
	int T;
	cin>>T;
	string s;
	getline(cin,s);
	for (int casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";

		getline(cin,s);
		for (int i=0;i<s.size();i++)
		{
			if (s[i]==' ') continue;
			s[i]=c[s[i]-'a'];
		}
		cout<<s<<endl;
	}
}
