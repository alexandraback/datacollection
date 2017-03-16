#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double t[2010], x[2010];

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int tt=1; tt <= T; tt++){
		printf("Case #%d:\n", tt);
		int n, A;
		double D;
		scanf("%lf%d%d", &D, &n, &A);
		for(int i = 0;  i<n; i ++){
			scanf("%lf%lf", t+i, x+i);
		}
		double a;
		for(int i = 0; i < A; i ++){
			scanf("%lf", &a);
			double ans;
			if(n==1){
				ans = sqrt(2*D/a);

			}
			else{
				double v = (x[1]-x[0])/(t[1]-t[0]);
				ans = v + sqrt(v*v+2*a*x[0]);
				ans /= a;
				double s = a*ans*ans/2;
				if(s>D){
					ans = sqrt(2*D/a);
				}
				else{
					ans += (D-s)/v;
				}
				
			}
			printf("%lf\n", ans);
		}
	}
	return 0;
}
