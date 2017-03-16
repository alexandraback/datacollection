#include<bits/stdc++.h>
#define ll long long
using namespace std;

int cnts[1005];
int main()
{
	int t,i,ans,val,cnt=1,n,k,pre,m1,j;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=1000;i++)
		{
			cnts[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			cnts[k]++;
		}
		ans=100000;
		pre=0;
		for(i=1;i<=1000;i++)
		{
			if(cnts[i]!=0)
			{
				pre=i;
			}
			m1=0;
			for(j=i+1;j<=1000;j++)
			{
				if(cnts[j]==0) continue;
				val=j/i;
				if(j%i==0)
				{
					val--;
				}
				m1+=(val*cnts[j]);
			}
			if(m1==0)
			{
				m1=pre;
			}
			else
			{
				m1=i+m1;
			}
			ans=min(ans,m1);
		}
		printf("Case #%d: %d\n",cnt,ans);
		cnt++;
	}
	return 0;
}
