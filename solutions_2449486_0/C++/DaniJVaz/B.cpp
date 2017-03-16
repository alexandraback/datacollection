#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int n, m;
		scanf("%d %d", &n, &m);

		int desired[n][m], obtained[n][m];
		for (int i=0; i<n; i++) {
			fill(&obtained[i][0], &obtained[i][0] + m, 100);
			for (int j=0; j<m; j++)
				scanf("%d", &desired[i][j]);
		}

		for (int i=0; i<n; i++) {
			int maxH = desired[i][0];
			for (int j=0; j<m; j++)
				maxH = max(maxH, desired[i][j]);
			for (int j=0; j<m; j++)
				obtained[i][j] = min(obtained[i][j], maxH);
		}

		for (int j=0; j<m; j++) {
			int maxH = desired[0][j];
			for (int i=0; i<n; i++)
				maxH = max(maxH, desired[i][j]);
			for (int i=0; i<n; i++)
				obtained[i][j] = min(obtained[i][j], maxH);
		}

		bool possible = true;
		for (int i=0; i<n; i++)
			possible &= equal(&obtained[i][0], &obtained[i][0]+m, &desired[i][0]);

		printf("Case #%d: %s\n", iC, possible?"YES":"NO");
	}
	return 0;
}
