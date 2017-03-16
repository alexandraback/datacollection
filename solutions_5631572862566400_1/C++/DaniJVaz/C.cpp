#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int countStepsTo(int * prefs, int N, int from, int to) {
	int count = 1;
	int j = prefs[from];

	while (j != to) {
		j = prefs[j];
		count++;
		if (count > N)
			break;
	}
	return count;
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int N;
		scanf("%d", &N);

		int prefs[N];
		for (int i=0; i<N; i++) {
			scanf("%d", prefs+i);
			prefs[i]--;
		}

		int maxCycle = 0;
		for (int i=0; i<N; i++) {
			int steps = countStepsTo(prefs, N, i, i);

			if (steps <= N and steps > maxCycle) {
				maxCycle = steps;
			}
		}

		int pairForestSize = 0;
		bool inCircle[N];
		fill(inCircle, inCircle+N, false);

		for (int i=0; i<N; i++) {
			if (inCircle[i] == true)
				continue;
			if (prefs[prefs[i]] != i)
				continue;
			//printf("%d %d\n", i, prefs[i]);
			inCircle[i] = inCircle[prefs[i]] = true;

			pairForestSize +=2;

			int maxA = 0, maxB = 0;
			for (int j=0; j<N; j++) {
				if (inCircle[j] == true)
					continue;
				int stepsA = countStepsTo(prefs, N, j, i);
				int stepsB = countStepsTo(prefs, N, j, prefs[i]);
				//printf("%d %d %d\n", j, stepsA, stepsB);

				if (stepsA > N or stepsB > N)
					continue;

				if (stepsA < stepsB and stepsA > maxA)
					maxA = stepsA;
				else if (stepsA > stepsB and stepsB > maxB)
					maxB = stepsB;
			}
			pairForestSize += maxA + maxB;
		}

		printf("Case #%d: %d\n", iC, max(maxCycle, pairForestSize));
	}
	return 0;
}