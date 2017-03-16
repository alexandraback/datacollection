#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	while(test--) {
		static int testCount = 0;
		printf("Case #%d: ", ++ testCount);
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		double ans = 1e100;
		double rate = 2, cur = 0;
		for( ; ; ) {
			double tAns = cur + x / rate;
			if (tAns < ans) {
				ans = tAns;
			} else {
				break;
			}
			cur += c / rate;
			rate += f;
		}
		printf("%.7f\n", ans);
	}	
} 
