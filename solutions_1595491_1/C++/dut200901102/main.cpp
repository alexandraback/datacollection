#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n,s,p;

void solve()
{
	int ans=0;
	cin>>n>>s>>p;
	for(int i=0,a;i<n;++i)
	{
		cin>>a;
		if(a==0)
		{
			if(p==0)ans++;
			continue;
		}
		int tem=a%3;
		if(tem==0)
		{
			if(a/3>=p)ans++;
			else if(a/3+1>=p && s)ans++,s--;
		}
		if(tem==1)
		{
			if((a-1)/3+1>=p)ans++;
		}
		if(tem==2)
		{
			if((a+1)/3>=p)ans++;
			else if((a-2)/3+2>=p && s)ans++,s--;
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
