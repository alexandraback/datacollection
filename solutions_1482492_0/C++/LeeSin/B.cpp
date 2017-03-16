#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 3
#define eps 1e-11
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;

int T, n, a;
double d, t[N], x[N], ac;

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-outnew.txt", "w", stdout);
	scanf("%d", &T);
	
	FI(z, 1, T){
		printf("Case #%d:\n", z);
		
		scanf("%lf %d %d", &d, &n, &a);
		
		FI(i, 1, n) scanf("%lf %lf", &t[i], &x[i]);
		if(n == 2){
			if(x[1] + eps > d) n = 1;
			else t[2] = (d - x[1]) / ((x[2] - x[1]) / (t[2] - t[1])) + t[1];
		}
		
		while(a--){
			scanf("%lf", &ac);
			
			if(n == 1){
				printf("%lf\n", sqrt(2.0 * d / ac));
			}else{
				double dd = t[2] * t[2] * ac / 2.0;
				if(dd > d) printf("%lf\n", t[2]);
				else printf("%lf\n", sqrt(2.0 * d / ac));
			}
		}
	}
	
	scanf("\n");
}
