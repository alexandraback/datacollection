#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,u=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector <int> v(n+1);
		v[0]=s[0]-'0';
		int ans=0;
		for(int i=1;i<s.length();i++)
		{
			if(v[i-1]<i)
			{
				ans+=i-v[i-1];
				v[i]=i+s[i]-'0';
			}
			else
			{
				v[i]=v[i-1]+s[i]-'0';
			}
		}
		cout<<"Case #"<<u++<<": "<<ans<<endl;
	}
	return 0;
}