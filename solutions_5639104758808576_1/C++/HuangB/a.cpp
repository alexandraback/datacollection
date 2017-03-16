#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int sum,ans;
int test,n;
char ch;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
	scanf("%d",&test);
	for (int t=1;t<=test;++t)
	{
		scanf("%d",&n);
		sum=ans=0;
		scanf("%c",&ch);
		scanf("%c",&ch);
		sum=ch-'0';
		for (int i=1;i<=n;++i)
		{
			if (sum<i) 
			{
				ans+=i-sum;
				sum=i;
			}
			scanf("%c",&ch);
			sum+=ch-'0';			
		}
		printf("Case #%d: %d\n",t,ans);
	}
   return 0;
}
