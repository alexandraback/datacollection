#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define MOD 1000000007
string s;
char c;
string temp;
int main()
{
	ll t,n;
	ll z=1;
	cin>>t;
	while(t--)
	{
		cin>>s;
		n=s.length();
		c='A';
		for(int i=0;i<n;i++)
		{
			if(c>(char)s[i])
				c=s[i];
		}
		temp="";
		temp+=s[0];
		for(int i=1;i<n;i++)
		{
			if(s[i]>=temp[0])
			{
				temp=s[i]+temp;
			}
			else
			{
				temp+=s[i];
			}
		}
		cout<<"Case #"<<z<<": "<<temp<<endl;
		z++;
	}
	return 0;
}