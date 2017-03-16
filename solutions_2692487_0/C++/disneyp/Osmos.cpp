#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[110];
int b;
int ans;
void check(int ind,int n,int cnt)
{
	int temp=b;
	for(int i=1;i<ind;i++)
	{
		while(temp<=a[i])
		{
			temp+=temp-1;
			cnt++;
		}
		temp+=a[i];
	}
	//cout << "---" <<  ind << " " << cnt << endl;
	ans=min(ans,cnt);
	return;
}
main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	int n;
	cin >> t;
	for(int ll=0;ll<t;ll++)
	{
		ans=1000000000;
		scanf("%d %d",&b,&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(b==1)
		{
			printf("Case #%d: %d\n",ll+1,n);
			continue;
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n+1;i++)
		{
			check(i,n,n+1-i);
		}
		printf("Case #%d: %d\n",ll+1,ans);
		
		
		
	}
}
