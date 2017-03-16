#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T,i,j,l1,l2=0;
	string ans;
	char s[1005]={0};
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%s",s);
		printf("Case #%d: ",i);
		l1=strlen(s);
		for(j=0;j<l1;j++)
		{
			if(s[j]>=ans[0])
			{
				ans=s[j]+ans;
			}
			else
			{
				ans+=s[j];
			}
		}
		cout<<ans<<endl;
		ans.clear();
	}
}
