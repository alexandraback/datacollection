#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,i,ans,val,cnt=1,n;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>s;
		ans=0;
		val=0;
		for(i=0;i<=n;i++)
		{
			if(val>=i)
			{
				val+=s[i]-48;
			}
			else
			{
				ans+=(i-val);
				val+=(i-val);
				val+=s[i]-48;
			}
		}
		printf("Case #%d: %d\n",cnt,ans);
		cnt++;
	}
	return 0;
}
