#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n, i, j;
		scanf("%d", &n);

		double naomi[n], ken[n];
		for (i=0; i<n; i++)
			scanf("%lf", naomi+i);
		for (i=0; i<n; i++)
			scanf("%lf", ken+i);

		sort(naomi, naomi+n);
		sort(ken, ken+n);

		// War
		int kenWar = 0;
		i = j = n-1;
		while (i>=0 and j>=0) {
			if (naomi[i] < ken[j]) {
				kenWar++;
				--i; --j;
			}
			else {
				--i;
			}
		}

		// Deceitful War
		int jmin=0, jmax=n-1;
		int naomiDecWar = 0;
		for (i=0; i<n; i++) {
			if (naomi[i] > ken[jmin]) { 	// Then naomi will bluff and say it is really high, 
									  		// so that ken plays ken[jmin] and naomi wins
				++naomiDecWar;
				++jmin;
			}
			else {							// Naomi says its just below ken[jmax] so that ken will use that
				--jmax;
			}
		}

		printf("Case #%d: %d %d\n", iC, naomiDecWar, n-kenWar);
	}
	return 0;
}