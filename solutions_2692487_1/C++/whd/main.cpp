
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long big;
const int N=202;
int A,n;
int a[N];
int main()
{
	int now,cas,cass,i,j,s,ans;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		printf("Case #%d: ",cass);
		scanf("%d%d",&A,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s=0;
		ans=n;
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			ans=min(ans,n-i+1+s);
			if(A==1&&a[i]>=A)break;
			while(A<=a[i])A+=A-1,s++;
			A+=a[i];
		}
		if(i>n)ans=min(ans,s);
		printf("%d\n",ans);
	}
}
