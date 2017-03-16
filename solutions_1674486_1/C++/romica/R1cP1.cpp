#include <iostream>
#include <cmath>
using namespace std;
int **m;
int T, N, count;
int *viz;
int dive (int cur) {
	if (viz[cur] == 1) {
		return 1;
	}
	

	for (int i = 1; i <= m[cur][0]; ++i) {
		if (dive (m[cur][i]) == 1) {
			return 1;
		}
		viz[m[cur][i]] = 1;
	}
	viz[cur] = 1;
	return 0;
}


int solve() {
	viz = (int*) malloc((N + 1) * sizeof(int));
	int cur;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			viz[j] = 0;
		}
		if (dive(i) == 1) {
			return 1;
		}
	/*	for (int j = 1; j <= m[i][0]; ++j) {
			if (viz[m[i][j]] == 1) {
				return 1;
			}
			viz[m[i][j]] = 1;
			cur = i;
			while (m[m[cur][j]][0] != 0) {
				if (viz[m[cur][j]] == 1) {
					return 1;
				}
			}
		}
		*/
	}
	return 0;
}

int main() {
	FILE *fpin, *fpout;
	fpin = fopen("input.txt", "r");
	fpout = fopen("output.txt", "w");
	
	fscanf(fpin, "%d", &T);

	for (int nt = 1; nt <= T; ++nt) {
		fscanf(fpin, "%d", &N);
		m = (int**) malloc ((N + 1) * sizeof (int*));

		for (int i = 1; i <= N; ++i) {

			fscanf(fpin, "%d", &count);
			m[i] = (int*) malloc((count + 1)* sizeof (int));
			m[i][0] = count;
			for (int j = 1; j <= m[i][0]; ++j) {
				fscanf(fpin, "%d", &m[i][j]);
			}
		}

		fprintf(fpout, "Case #%d: ", nt);
		if (solve() == 1) {
			fprintf(fpout, "Yes");
		} else {
			fprintf(fpout, "No");
		}
		fprintf(fpout, "\n");
	}
	
	fclose(fpin);
	fclose(fpout);
	return 0;
}