#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll toLong(string s)
{
	ll x = 0;
	for(int i=0; i<s.length(); i++)
	{
		x = x*10 + (s[i]-'0');
	}
	return x;
}
bool match(string gen, string giv)
{
	int x = gen.length();
	if(x!=giv.length())
		return false;
	for(int i=0; i<x; i++)
	{
		if(giv[i]=='?')
			continue;
		if(giv[i]!=gen[i])
			return false;
	}
	return true;
}
string toString(int v, int l)
{
	string s1="",s2="";
	while(v)
	{
		s2.push_back(v%10 + '0');
		v/=10;
	}
	reverse(s2.begin(),s2.end());
	if(l<s2.length())
	{
		for(int i=0; i<l; i++)
			s1.push_back('X');
		return s1;
	}
	while(l>s2.length())
	{
		l--;
		s1.push_back('0');
	}
	for(int i=0; i<l; i++)
		s1.push_back(s2[i]);
	return s1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	string s1,s2,g1,g2;
	for(int tc = 1; tc <= T; tc++)
	{
		cout<<"Case #"<<tc<<": ";
		cin>>s1>>s2;
		ll mindif=1e18;
		string cs, js;
		for(int i=0; i<1000; i++)
		{
			g1 = toString(i,s1.length());
			if(!match(g1,s1))
				continue;
			for(int j=0; j<1000; j++)
			{
				g2 = toString(j,s2.length());
				if(match(g2,s2))
				{
					ll dif = abs(i-j);
					if(dif<mindif)
					{
						mindif=dif;
						cs=g1;
						js=g2;
					}
				}
			}
		}
		cout<<cs<<" "<<js<<"\n";
	}
}