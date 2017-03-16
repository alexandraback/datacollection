#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int small(int arr[], int n)
{
   int res = 1;
   for (int i = 0; i < n && arr[i] <= res; i++)
       res = res + arr[i];
 
   return res;
}

int main()
{
	int t,T,c,d,v,i,j,ans,tp;
	int a[101];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		ans=0;
		scanf("%d %d %d",&c,&d,&v);
		for(i=0;i<d;i++)
			scanf("%d",&a[i]);
		
		tp=small(a,d);
		while(tp<=v)
		{
			a[d++]=tp;
			sort(a,a+d);
			ans++;
			tp=small(a,d);
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
