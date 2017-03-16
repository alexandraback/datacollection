#include<bits/stdc++.h>
using namespace std;
int arr[10005];
int brr[10005];
int crr[10005];
int n;
int func(int h)
{
	int coo=0;
	int co=0;
	do {
		co=0;
		for(int i=0;i<h;i++)
		{
			if(i!=0&&i!=(h-1))
			{
				if(arr[brr[i]]==brr[i-1]||arr[brr[i]]==brr[i+1])
				co++;
				else
				{
					co=0;
					break;
				}
			}
			else if(i==0)
			{
				if(arr[brr[i]]==brr[i+1]||arr[brr[i]]==brr[h-1])
				co++;
				else
				{
					co=0;
					break;
				}
			}
			else
			{
				if(arr[brr[i]]==brr[i-1]||arr[brr[i]]==brr[0])
				co++;
				else
				{
					co=0;
					break;
				}
			}
		}
		
		coo=max(coo,co);
	} while ( std::next_permutation(brr,brr+h) );
	return coo;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	int k=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i,j;
		int ans=0;
		for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
		for(i=0;i<(1<<n);i++)
		{
			int h=0;
			//if(__builtin_popcount(i)<3)
			//continue;
			for(j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					brr[h++]=j+1;
				}
			}
			int d=func(h);
			ans=max(ans,d);
		}
		printf("Case #%d: %d\n",k++,ans);
	}
	return 0;
}
