#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;
int casenum,T,num;
long long a,b,x;
long long f[1000];
bool flag;
stringstream ss;
string s;
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	num=0;
	for (long long i=1;i<=10000000;i++)
	{
		x=i*i;
		ss.clear();
		ss<<x;
		ss>>s;
		flag=true;
		for (int j=0;j<s.size();j++)
			if (s[j]!=s[s.size()-1-j]) flag=false;
		ss.clear();
		ss<<i;
		ss>>s;
		for (int j=0;j<s.size();j++)
			if (s[j]!=s[s.size()-1-j]) flag=false;
		if (flag)
		{
			num++;
			//cout<<x<<endl;
			f[num]=x;
		}
	}
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		cin>>a>>b;
		int ans=0;
		for (int i=1;i<=num;i++)
			if (a<=f[i]&&f[i]<=b) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
