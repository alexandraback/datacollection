#include<bits/stdc++.h>
using namespace std;
long long p,q;
void input()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='/')
			s[i]=' ';
	istringstream iss(s);
	iss>>p>>q;
	long long gcd=__gcd(p,q);
	p/=gcd;
	q/=gcd;
}
bool checkQ(long long n)
{
	while(n!=0)
	{
		if(n!=1 && n&1!=0)
			return false;
		n>>=1;
	}
	return true;
}
int main()
{
	int T;
	cin>>T;
	for(int no=1;no<=T;no++)
	{
		input();
		if(!checkQ(q))
		{
			printf("Case #%d: impossible\n",no);
			continue;
		}
		int ans=1;
		while(q/2>p)
		{
			q/=2;
			ans++;
		}
		printf("Case #%d: %d\n",no,ans);
	}
}

