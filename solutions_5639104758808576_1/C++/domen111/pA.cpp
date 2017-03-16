#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	int no=1;
	while(no<=T)
	{
		int n;
		string s;
		cin>>n>>s;
		int stand=0;
		int ans=0;
		for(int i=0;i<=n;i++)
		{
			if(stand<i)
			{
				ans+=i-stand;
				stand=i;
			}
			stand+=s[i]-'0';
		}
		printf("Case #%d: %d\n",no++,ans);
	}
}
