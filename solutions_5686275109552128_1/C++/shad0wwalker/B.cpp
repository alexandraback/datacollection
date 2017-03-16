#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	//freopen("B-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,k,n,i,j,ans,div,a[1010],m;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		m=0;ans=0x7fffffff;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			m=max(m,a[i]);
		}
		for(i=1;i<=m;i++){
			div=0;
			for(j=1;j<=n;j++)
				div+=(a[j]-1)/i;
			ans=min(ans,div+i);
		}
		printf("Case #%d: %d\n",k,ans);
	}
 return 0;
}

