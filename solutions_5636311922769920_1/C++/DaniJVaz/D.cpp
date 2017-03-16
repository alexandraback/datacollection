#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int k, c, s;
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:", iC);

		// Each position in complexity c gives us information about c positions of the original string
		//In particular, if we look at position i= i_(c-1)*k^(c-1) + i_(c-2)*k^(c-2) + ... + i_0 (0-based),
		//we get information about positions i_0, ..., i_(c-1)
		//Anyway, if c*s < k, we can't get enough information
		if (c*s < k) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		// To get positions that give us a solution, we just do the opposite:
		//generate numbers that in base k have all the possible digits and convert
		//them back to decimal (and add 1, btw)
		for (int i=0; i<s; i++) {
			ll pos = 1, pot = 1;

			// So that we avoid repetitions
			if (c*i >= k)
				break;

			for (int j=c*i; j<c*(i+1); j++) {
				pos += pot * (j%k);
				pot *= k;
			}
			printf(" %I64d", pos);
		}
		printf("\n");
	}
	return 0;
}