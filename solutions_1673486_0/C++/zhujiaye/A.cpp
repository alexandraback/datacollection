#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn (100005)
using namespace std;

int test,n,m;
double a[maxn];

int main(){
	freopen("i.txt","r",stdin);
	int cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
		a[0]=1.0;
		double ans=1e30,tmp;
		tmp=1.0;
		for (int i=1;i<=n;i++) tmp*=a[i];
		if (tmp*(m-n+1)+(1-tmp)*(m-n+1+m+1)<ans) ans=tmp*(m-n+1)+(1-tmp)*(m-n+1+m+1);
		if (m+2<ans) ans=m+2;
		tmp=1.0;
		for (int i=0;i<=n;i++){
			tmp*=a[i];
			if (tmp*(n-i+m-i+1)+(1-tmp)*(n-i+m-i+1+m+1)<ans) 
				ans=tmp*(n-i+m-i+1)+(1-tmp)*(n-i+m-i+1+m+1);
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
