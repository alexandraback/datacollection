#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
double a[1100],b[1100];
bool f[1100];
int main(){
//	freopen("D-small-attempt0","r",stdin);
	freopen("dsmall.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%lf",&a[i]);
		for (int i=0;i<n;i++)
			scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int ans1=0,ans2=0;
		memset(f,0,sizeof(f));
		for (int i=0;i<n;i++){
			bool ff=0;
			for (int j=0;j<n;j++)
				if (!f[j]&&b[j]>a[i]){
					f[j]=1;ff=1;break;
				}
			if (!ff) ans1++;
		}
		int s=0;
		int head=0;
		for (int i=0;i<n;i++)
			if (a[i]>b[head]) ans2++,head++;
		printf("Case #%d: %d %d\n",t,ans2,ans1);
	}
	return 0;
}
