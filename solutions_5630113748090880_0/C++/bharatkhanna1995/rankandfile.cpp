#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
int ans[2500];
int freq[2505];
int main()
{
	freopen("B-small-attempt0(1).in","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,n,x;
	int t;
	sd(t);
	for(x=1;x<=t;x++)
	{
		for(i=0;i<=2500;i++)
			freq[i]=0;
		sd(n);
		for(i=0;i<2*n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				sd(k);
				freq[k]++;
			}
		}
		k=0;
		for(i=1;i<=2500;i++)
		{
			if(freq[i]%2!=0)
				ans[k++]=i;
		}
		printf("Case #%d: ", x);
		for(i=0;i<k;i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}