#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int a, n;
		scanf("%d %d", &a, &n);

		int motes[n];
		for (int i=0; i<n; i++)
			scanf("%d", motes+i);
		sort(motes, motes+n);

		int sizeMoves[n+1][n+1];

		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
					sizeMoves[i][j] = -1;
		sizeMoves[0][0] = a;

		int moves;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (sizeMoves[i][j] == -1)
					continue;

				a = sizeMoves[i][j];
				if (motes[i] < a) {
					if (sizeMoves[i+1][j] == -1 or sizeMoves[i+1][j] < a+motes[i])
						sizeMoves[i+1][j] = a + motes[i];
				}
				else {
					if (sizeMoves[i+1][j+1] == -1 or sizeMoves[i+1][j+1] < a) // removal
						sizeMoves[i+1][j+1] = a;

					if (a-1 != 0) {
						moves = j;
						while (a <= motes[i]) {
							a += a-1;
							moves++;
						}
						a += motes[i];
						if (moves <= n and (sizeMoves[i+1][moves] == -1 or sizeMoves[i+1][moves] < a)) // add
							sizeMoves[i+1][moves] = a;
					}
				}
			}
		}

		for (moves = 0; moves <= n; moves++)
			if (sizeMoves[n][moves] != -1)
				break;

		/*for (int i=0; i<=n; i++, printf("\n"))
			for (int j=0; j<=n; j++)
				printf("%d ", sizeMoves[i][j]);*/

		printf("Case #%d: %d\n", iC, moves);
	}
	return 0;
}