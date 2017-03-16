//Abhishek Paliwal
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<climits>
#include<map>

#define FOR(i,s,n) for(i=s;i<n;i++)
#define FORD(i,s,n) for(i=s;i>n;i--)
#define LL long long

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int k=0;
	while(k!=t)
	{
		k++;
		int a,n;
		scanf("%d%d",&a,&n);
		int arr[n];
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		if(a==1)
		{
			printf("Case #%d: %d\n",k,n);
			continue;
		}
		sort(arr,arr+n);
		int ans=INT_MAX,tmp=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]<a)
				a+=arr[i];
			else
			{
				ans=min(ans,tmp+(n-i));
				while(a<=arr[i])
				{
					a=a+a-1;
					tmp++;
				}
				a+=arr[i];
			}
		}
		ans=min(ans,tmp);
		printf("Case #%d: %d\n",k,ans);	
	}
	return 0;
}
