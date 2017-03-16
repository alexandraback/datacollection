#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
string s,ans;
int T;
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		cin>>s;
		int len=s.size();
		//cout<<s<<endl;
		ans="";
		ans+=s[0];
		for(int j=1;j<len;j++)
		{
			if (ans+s[j]>s[j]+ans)
				ans=ans+s[j];
			else
				ans=s[j]+ans;
		}
		cout<<ans<<endl;
	}
}