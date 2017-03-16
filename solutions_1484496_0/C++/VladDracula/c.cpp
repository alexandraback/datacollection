#include <stdio.h>
#include <string.h>

int can[2<<21];
int data[24];
int n;
int sol1, sol2;

int rec(int i, int sum, int sol) {
	if (i==n) {
		if (can[sum]) {
			sol1 = can[sum];
			sol2 = sol;
			return 1;
		}
		can[sum]=sol;
		return 0;
	}
	if (rec(i+1, sum+data[i], sol | (1<<i))) return 1;
	if (rec(i+1, sum, sol)) return 1;	
	return 0;
}

void printSol(int sol, FILE *fo) {
	int num=0, curr=0;
	for (int i=0; i<n; i++)
		if (sol & (1<<i))
			num++;
	for (int i=0; i<n; i++)
		if (sol & (1<<i)) {
			curr++;
			fprintf(fo, "%d", data[i]);
			if (curr<num)
				fprintf(fo, " ");
			else
				fprintf(fo, "\n");
		}
}

int main() {
	FILE *fi = fopen("c.in", "r");
	FILE *fo = fopen("c.out", "w");

	int tests;
	fscanf(fi, "%d", &tests);
	for (int test=0; test<tests; test++) {
		memset(can, 0, sizeof(can));
		fscanf(fi, "%d", &n);
		for (int i=0; i<n; i++)
			fscanf(fi, "%d", data+i);
		fprintf(fo, "Case #%d:\n", test+1);
		if (rec(0, 0, 0)) {
			printSol(sol1, fo);
			printSol(sol2, fo);
		} else {
			fprintf(fo, "Impossible\n");
		}

	}

	fclose(fi);
	fclose(fo);
	return 0;
}
