#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double a[1101],b[1101];
int i,j,k,n,tc,now,ans;
int main(){
	scanf("%d",&tc);
	for (now=1;now<=tc;now++){
		printf("Case #%d: ",now);
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%lf",&a[i]);
		for (i=1;i<=n;i++) scanf("%lf",&b[i]);
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		for (i=k=1,ans=0;i<=n;i++){
			if (a[i]>b[k]){
				k++;ans++;
			}
		}
		printf("%d ",ans);
		for (i=k=1,ans=n;i<=n&&k<=n;i++){
			for (;k<=n&&b[k]<a[i];k++);
			if (k>n) break;
			ans--;k++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
