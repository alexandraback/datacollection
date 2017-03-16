//mohit____the_____great______and_________powerful_______!!!
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first 
#define se second
#define pb push_back  
#define mp make_pair

int main()
{
	 freopen("inp.txt","r",stdin);
	 freopen("out.txt","w",stdout);
	long t, l;
	cin>>t;
	l=1;
	while(t--)
	{
		string s, ans;
		cin>>s;
		ans=s[0];
		for(int i=1;s[i]!='\0';i+=1)
		{
			if(s[i]>=ans[0])
				ans=s[i]+ans;
			else
				ans=ans+s[i];
		}
		cout<<"Case #"<<l<<": "<<ans<<endl;
		l+=1;
	}
}