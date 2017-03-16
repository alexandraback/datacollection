#include <cstdio>
#include <algorithm>
using namespace std;
const int c=256;
int t,ii;
int n;
double s[c];
double m[c];
double x;
int main() {
	scanf("%d",&t);
	int i,j,k;
	for (ii=1; ii<=t; ++ii) {
		scanf("%d",&n);
		for (i=1; i<=n; ++i) scanf("%lf",&s[i]);
		x=0;
		for (i=1; i<=n; ++i) x+=s[i];
		double sy;
		for (i=1; i<=n; ++i) {
			double lf=0,rg=1,md;
			for (j=0; j<100; ++j) {
				md=(lf+rg)/2;
				sy=0;
	            for (k=1; k<=n; ++k)
	            	sy+=max(0.0,(s[i]+x*md-s[k])/x);
	            if (sy>=1) rg=md; else lf=md;
			}
			md=(lf+rg)/2;
			m[i]=md*100;
		}
		printf("Case #%d: ",ii);
		for (i=1; i<=n; ++i) printf("%.6lf ",m[i]);
		printf("\n");
	}
	return 0;
}
