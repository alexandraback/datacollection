#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 100005

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		int A, B;
		scanf("%d %d", &A, &B);
		double prob[MAX];
		double mult = 1.0;
		for (int i = 0; i < A; i++){
			scanf("%lf", &prob[i]);
			mult *= prob[i];
		}
		double resp = B + 2;
		resp = min(resp, mult * (B-A+1) + (1-mult) * (2*B-A+2));

		mult = 1.0;

		for (int i = 0; i < A; i++){
			resp = min(resp, mult*(2*(A-i)+B-A+1) + (1-mult)*(2*(A-i)+B-A+1+B+1));
			mult *= prob[i];
		}

		printf("Case #%d: %.6f\n", t, resp);
	}
	return 0;
}
