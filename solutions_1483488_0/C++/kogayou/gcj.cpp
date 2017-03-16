#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
stringstream ss;
string s,s1,s2;
int main()
{
	freopen("gcj.out","w",stdout);
	int T;
	cin>>T;
	for (int casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		int st,ed;
		int ans=0;
		cin>>st>>ed;
		for (int i=st;i<=ed;i++)
		{
			ss.clear();
			ss<<i;
			ss>>s;
			s1=s;
			while (1)
			{
				s2=s1.substr(1)+s1.substr(0,1);
				if (s2==s) break;
				ss.clear();
				ss<<s2;
				int j;
				ss>>j;
				if (st<=j&&j<=ed) ans++;
				s1=s2;
			}
		}
		cout<<ans/2<<endl;
	}
}
