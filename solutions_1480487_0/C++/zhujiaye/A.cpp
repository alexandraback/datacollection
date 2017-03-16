#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn (205)
#define eps (1e-10)
using namespace std;

int test,n;
double a[maxn],tot;

bool can(int i,double m){
	double x=a[i]+m*tot;
	double t=0;
	for (int j=0;j<n;j++) if (j!=i){
		double l=(x-a[j])/tot;
		if (x<=a[j]) l=0;
		t+=l;
	}
	if (t>=(1-m)) return true;
	return false;
}
int main(){
	freopen("i.txt","r",stdin);
	int cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d",&n);
		tot=0;
		for (int i=0;i<n;i++){
			scanf("%lf",&a[i]);
			tot+=a[i];
		}
		for (int i=0;i<n;i++){
			double l=0,r=1;
			while (r-l>eps){
				double m=(l+r)/2.0;
				if (can(i,m)) r=m;
					else l=m;
			}
			printf("%.6lf ",l*100);
		}
		puts("");
	}
	return 0;
}
