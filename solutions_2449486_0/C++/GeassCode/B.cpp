#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 110
int x[maxn],y[maxn];
int a[maxn][maxn];
int n,m;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int i,j,k;
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			x[i]=a[i][1];
		}
		for(i=1;i<=m;i++){
			y[i]=a[1][i];
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				x[i]=max(x[i],a[i][j]);
				y[j]=max(y[j],a[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i][j]!=min(x[i],y[j]))break;
			}
			if(j<=m)break;
		}
		if(i>n)printf("Case #%d: YES\n",cas);
		else printf("Case #%d: NO\n",cas);
	}
	return 0;
}
