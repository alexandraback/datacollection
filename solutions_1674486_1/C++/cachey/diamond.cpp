#include <cstdio>
using namespace std;

FILE* inputFile;
FILE* outputFile;
int n, t;
bool seen[1005];
bool adjmat[1005][1005];
bool dfs(int node) {
	if (seen[node]) return true;
	for (int i = 0; i < 1005; i++) {
		if (adjmat[node][i]) {
			//printf("Got to node %d\n", node);
			if (dfs(i)) {
				return true;
			}
			seen[i] = true;
		}
	}
	return false;
}

void clean() {
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; +j++) {
			adjmat[i][j] = false;
		}
		seen[i] = false;
	}
	n = 0;
}

void wipe() {
	for (int i = 0; i < 1005; i++) {
		seen[i] = false;
	}
}
int main() {
	inputFile = fopen("a.in", "r");
	outputFile = fopen("a.out", "w");
	fscanf(inputFile, "%d", &t);
	for (int i = 0; i < t; i++) {
		clean();
		fscanf(inputFile, "%d", &n);
		for (int j = 1; j <= n; j++) {
			int temp, tempy;
			fscanf(inputFile, "%d", &temp);
			for (int k = 0; k < temp; k++) {
				fscanf(inputFile, "%d", &tempy);
				adjmat[tempy][j] = true;
			}
		}
		bool ok = false;
		for (int j = 1; j <= n; j++) {
			wipe();
			if (dfs(j)) {
				ok = true;
				break;
			}
		}
		if (ok) fprintf(outputFile, "Case #%d: Yes\n", i+1);
		else fprintf(outputFile, "Case #%d: No\n", i+1);
	}
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

