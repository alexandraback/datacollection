#include<bits/stdc++.h>
using namespace std;
long long arr[55][55];
long long hash[2550];
long long B[2550];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	int k=1;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		int h=0;
		for(i=0;i<=2500;i++)
		hash[i]=0;
		int n;
		scanf("%d",&n);
		int m=2*n-1;
		long long a,b,c;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%lld",&a);
				hash[a]++;
			}
		}
		for(i=1;i<=2500;i++)
		{
			if(hash[i]%2==1)
			{
				B[h++]=i;
			}
		}
		printf("Case #%d: ",k++);
		sort(B,B+h);
		for(i=0;i<h;i++)
		printf("%lld ",B[i]);
		printf("\n");
	}
	return 0;
}
