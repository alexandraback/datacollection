#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T, A, B;
vector<double> p;
int main(){
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; ++ testcase){
		scanf("%d%d", &A, &B);
		p.resize(A);
		for (int i = 0; i < A; ++ i)
			scanf("%lf", &p[i]);
		double ans = B + 2, prob;
		double P = 1;
		for (int k = 0; k < A; ++ k){
			P *= p[k];
			int cnt1 = (A - k - 1 + B - k);
			int cnt2 = (cnt1 + B + 1);
			prob = P * cnt1 + (1 - P) * cnt2;
			ans = min(ans, prob);
			//printf ("k = %d, corr = %d, incorr = %d -- %lf\n", k, cnt1, cnt2, prob);
		}
		printf("Case #%d: %.7lf\n", testcase + 1, ans);
	}
	return 0;
}