#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	
	scanf("%d", &t);
	
	for(int time = 1; time <= t; ++time) {
		
		int a, b;
		vector<double> p;
		vector<double> r;
		
		scanf("%d%d", &a, &b);
		p.resize(a);
		r.resize(a + 1);
		for(int i = 0; i < a; ++i)
			scanf("%lf", &p[i]);
		
		r[0] = 1;
		for(int i = 0; i < a; ++i)
			r[i + 1] = r[i] * p[i];
			
		double ans = b + 2;
		
		for(int i = 0; i <= a; ++i) {
			
			double wrong = 1 - r[i];
			double right = r[i];
			
			double expect = 0;
			
			int remain = (b - i) + 1;
			int clear = (b) + 1;
			int bs = (a - i);
			
			expect += wrong * (double)(bs + remain + clear);
			expect += right * (double)(bs + remain);
			
			ans = min(ans, expect);
		}
		
		printf("Case #%d: %f\n", time, ans);
	}
	
	return 0;
}