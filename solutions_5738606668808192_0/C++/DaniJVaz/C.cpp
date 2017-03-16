#include <cstdio>
#include <algorithm>
#include <vector>
#include <assert.h>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		// We know a lot about the testcases, so let's make life easier for us by exploiting it
		//In particular, we assume that N is even, and that J <= 2^((N-2)/2) (because that's the number of coinjams we get)
		int N,J;
		scanf("%d %d", &N, &J);
		assert ( (N%2 == 0)  &&  ( J <= ( 1LL << ((N-2)/2) ) ) );

		// As long as we keep the number of 1's balanced in odd and even positions,
		//the number we get when interpreted in base b is divisible by b+1
		printf("Case #%d:\n", iC);
		for (int i=0; i<J; i++) {
			char coin[N+1];
			coin[N] = '\0';

			fill(coin, coin+N, '0');
			coin[0] = coin[N-1] = '1';

			for (int l=0; l<(N-2)/2; l++) {
				if ( (i & (1LL<<l)) > 0 )
					coin[2*l+1] = coin[N-1-(2*l+1)] = '1';
			}

			printf("%s 3 4 5 6 7 8 9 10 11\n", coin);
		}

	}
	return 0;
}
