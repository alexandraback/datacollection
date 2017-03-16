#include <cstdio>
#include <vector>

using namespace std;



void run() {
	long val;
	scanf("%ld", &val);

	//if (val <= 20L) {
	//	printf("%ld\n", val);
	//} else {
		// steps needed
		// currently N=10
		long x = 10L;

		// p = smallest power of 10 <= val
		long p = 10L;
		while (val >= p*10L) {
			// N=p too small -> go to next pot p*10
			// count to N=p+9
			x += 9;
			// N=1_9 -> swap
			x++;
			// 9_1 -> count to p*10
			x += p - 1L;

			p *= 10L;
		}

		// -> p=N=1_ with length equal to val
		if (val <= 2*p) {
			// 2*N < val
			x += val - p;
		} else if ((val%p) == 0) {
			// f0_0 == val
			// -> count (f-1) times -> N=1_(f-1)
			x += (val/p) - 1;
			// swap -> N=(f-1)_1
			x++;
			// count by (p-1) to f0_0
			x += p - 1;
		} else {
			// f_ == val
			// -> f times -> N=1_f
			x += val / p;
			// swap -> N=f_1 <= val
			x++;
			// count by val-N
			x += val - ((val/p) * p + 1L);
		}

		printf("%ld\n", x);
	//}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int TC=1 ; TC<=T ; TC++) {
		printf("Case #%d: ", TC);

		run();
	}
}