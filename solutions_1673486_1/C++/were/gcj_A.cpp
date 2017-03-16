#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MaxN= 111111;
int A, B, T, case_cnt;
int main(){
	scanf("%d", &T);
	while(T --){
		scanf("%d%d", &A, &B);
		long double ans(2.0+B), now(1.0);
		double p;
		for(int i= 0;i< A;++ i){
			scanf("%lf", &p);
			now*= p;
			ans= min(ans, (long double)(A-i-1 + (B-i)*now + (2.0*B - i + 1.0)*(1.0-now)));
		}
		printf("Case #%d: %.6lf\n", ++ case_cnt, double(ans));
	}
//	system("pause");
	return 0;
}
