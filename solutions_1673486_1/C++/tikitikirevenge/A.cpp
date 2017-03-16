#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);

		int nAlready, nTot;
		scanf("%d %d ",&nAlready,&nTot);
		double bestKeyStrokes = nTot + 2.0;
		double prFine = 1.0;
		for (int i = 0; i <= nAlready; i++) {
			double exp = (nTot + nAlready - 2*i + 1);
			exp += (1.0-prFine)*(nTot+1);

			bestKeyStrokes = min(bestKeyStrokes, exp);
			if (nAlready == i) break;
			double curval;
			scanf("%lf ",&curval);
			prFine *= curval;
		}
		
		
		printf("Case #%d: %.6f\n",test,bestKeyStrokes);
	}
}
