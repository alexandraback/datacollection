#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int A,B;

string getBit(int x)
{
	string ret;
	while(x)
	{
		ret+=x%10+'0',x/=10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int getNum(const string &x)
{
	int ret=0;
	for(int i=0;i<x.length();++i)
		ret=ret*10+x[i]-'0';
	return ret;
}
void solve()
{
	int ans=0;
	cin>>A>>B;
	for(int i=A;i<=B;++i)
	{
		string bit=getBit(i);
		set<int> hash;
		for(int j=1;j<bit.length();++j)
			if(bit[j]!='0')
			{
				string tmp=bit.substr(j)+bit.substr(0,j);
				int ret=getNum(tmp);
				if(A<=ret && ret<=B && ret>i)
				{
					if(hash.count(ret))continue;
					hash.insert(ret);
					ans++;
				}
			}
	}
	printf("%d\n",ans);
}
int main()
{
	int t,cases=1;
	for(cin>>t;t--;)
	{
		printf("Case #%d: ",cases++);
		solve();
	}
	return 0;
}
