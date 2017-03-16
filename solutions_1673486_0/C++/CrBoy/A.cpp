#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
{
	int T, A, B;
	int casen = 0;
	double min_expect, expect, prob, all_prob;

	scanf("%d", &T);
	while(casen<T){
		scanf("%d%d", &A, &B);
		min_expect = B+2; // drop and retype
		all_prob = 1;
		for(int i = 1; i <= A; i++){
			expect = 0;
			int keys = A+B+1-2*i;
			scanf("%lf", &prob);
			all_prob *= prob;
			expect = all_prob*keys + (1-all_prob)*(keys+B+1);
			if(expect < min_expect)
				min_expect = expect;
		}
		printf("Case #%d: %lf\n", ++casen, min_expect);
	}
	
	return 0;
}
