#include <bits/stdc++.h>

using namespace std;
int t;
string s;

bool check(string& s)
{
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='-')
		{
			return false;
		}
	}
	return true;
}

int compute(string& s)
{
	int cnt=1;
	int n = s.length();
	for(int i=1;i<n;++i)
	{
		if(s[i]!=s[i-1])
		{
			cnt++;
		}
	}
	if(s[0]=='+')
	{
		if(cnt%2==0)
			return cnt;
		else
			return cnt-1;
	}
	else if(s[0]=='-')
	{
		if(cnt%2==0)
			return cnt-1;
		else
			return cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>s;
		cout<<"Case #"<<c<<": "<<compute(s)<<endl;
	}
	return 0;
}