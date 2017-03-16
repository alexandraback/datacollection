#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r,y,  z, x, an,level;
LL b[200000];
double C[12000][12000], ans;

void NCRcalculation(){
	for (int i = 0; i < 12000; ++i){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
		for (int j = i + 1; j < 12000; ++j)
			C[i][j] = 0;
	}
}

int main(){
	b[0] = 0;
	b[1] = 1;
	for (LL i=2; i<100000; i++)
		b[i] = 4*(i-1) + 1 + b[i-1];
	NCRcalculation();
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		ans = 0;
		printf("Case #%lld: ", rr);
		scanf("%lld %lld %lld", &n, &x, &y);
		level = (abs(x)+y)/2 + 1;
//		printf("n = %lld b[level] = %lld\n", n, b[level]);
		if (n <= b[level-1]){
			printf("%lf\n", 0.0);
		}
		else if (n >= b[level]){
			printf("%lf\n", 1.0);
		}
		else {
			if (x == 0){
				printf("%lf\n", 0.0);
				continue;
			}
			if (n == b[level] - 1){
				printf("%lf\n", 1.0);
				continue;
			}
			for (LL i=y+1; i<=n-(b[level-1]); i++){
//				printf("%lld\n", i);
				ans += C[n-b[level-1]][i];				
			}
			for (LL i=max(((n-b[level-1])-(y+1)+1),((b[level] - b[level-1])+1)/2 + y); i<=n-(b[level-1]); i++){
//				printf("%lld\n", i);
				ans += C[n-b[level-1]][i];
			}
			ans /= pow(2, (n-b[level-1]));
			printf("%.20lf\n", ans);
		}
	}
	return 0;
}
