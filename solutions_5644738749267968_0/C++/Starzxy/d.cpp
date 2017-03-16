#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int t,n;
double a[1010],b[1010];

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	
	scanf("%d%",&t);
	
	for(int t1=1;t1<=t;t1++)
	{
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		for(int i=1;i<=n;i++)
			cin>>b[i];
		
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		
		int h=1,t=n,ans1=0,ans2=0;
		
		for(int i=1;i<=n;i++)
			if(a[i]>b[h])
				ans1++,h++;
			else
				t--;
		
		h=1,t=n;
		
		for(int i=n;i>=1;i--)
			if(a[i]>b[t])
				ans2++,h++;
			else
				t--;
			
		printf("Case #%d: %d %d\n",t1,ans1,ans2);
	}
	
	return 0;
}
