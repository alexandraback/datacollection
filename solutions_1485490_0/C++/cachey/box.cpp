#include <cstdio>
#include <algorithm>
using namespace std;

FILE* inputFile;
FILE* outputFile;
int n, m;
int t;
struct order {
	long long number;
	long long type;
} toys[105], boxes[105];
long long cache[105][105];
long long dp(int a, int b) { 
	if (cache[a][b] != -1) return cache[a][b];
	if (a > n || b > m) {
		return 0;
	}
	if (toys[a].type == boxes[b].type) {
		cache[a][b] = min(toys[a].number, boxes[b].number);
		toys[a].number -= cache[a][b];
		boxes[b].number -= cache[a][b];
		cache[a][b] += max(dp(a+1, b), dp(a, b+1));
	} else {
		cache[a][b] = max(dp(a+1, b), dp(a, b+1));
	}
	return cache[a][b];
}
void clean() {
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			cache[i][j] = -1;
		}
		toys[i].number = 0;
		toys[i].type = 0;
		boxes[i].number = 0;
		boxes[i].type = 0;
	}
	m = 0;
	n = 0;
}

int main() {
	inputFile = fopen("c.in", "r");
	outputFile = fopen("c.out", "w");
	fscanf(inputFile, "%d", &t);
	for (int obs = 0; obs < t; obs++) { 
		clean();
		fscanf(inputFile, "%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			fscanf(inputFile, "%lld %lld", &toys[i].number, &toys[i].type);
		}
		for (int i = 0; i < m; i++) {
			fscanf(inputFile, "%lld %lld", &boxes[i].number, &boxes[i].type);
		}
		fprintf(outputFile, "Case #%d: %lld\n", obs+1, dp(0, 0));
	}
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

