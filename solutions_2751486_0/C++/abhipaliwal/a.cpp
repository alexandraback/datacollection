#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
char a[1000010];

int main()
{
	int t;
	scanf("%d",&t);
	int T=0;
	while(T!=t)
	{
		T++;
		int n;
		cin>>a>>n;
		long long int ans=0;
		long long int p = 0,cur=0;
		long long int i,l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o' && a[i]!='u' )
			{
				if(cur<n)
				{
					cur++;
				}

				if(cur==n)
				{
					ans+=(i-p-n+2)*(l-i);
					p=i-n+2;
				}
			}
			else
			{
				cur=0;
			}
		}
		printf("Case #%d: %lld\n",T,ans);
	}
	return 0;
}
