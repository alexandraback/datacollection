#include<iostream>
#include<string>
using namespace std;

int a[100][50];
bool big(int *a, int *b, int N) {
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i])return true;
		else if (a[i] < b[i])return false;
	}
	return false;
}

void sort(int N) {
	int max = 0;
	for (int i = 0; i < 2*N - 1; i++) {
		max = i;
		for (int j = i + 1; j < 2*N-1; j++) {
			if (big(a[max], a[j], N))max = j;
		}
		if (max != i) {
			for (int k = 0; k < N; k++) {
				int t = a[max][k];
				a[max][k] = a[i][k];
				a[i][k] = t;
			}
		}
	}
}

int main() {
	FILE *fpi, *fpo;
	fpi = fopen("B-small-attempt3.in", "r");
	fpo = fopen("smallB.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	for (int co = 1; co <= re; co++) {
		int N;
		fscanf(fpi, "%d", &N);
		int ne[2501];
		for (int i = 0; i <=2500; i++) {
			ne[i] = 0;
		}
		for (int j = 0; j < 2 * N - 1; j++) {
			for (int i = 0; i < N; i++) {
				fscanf(fpi, "%d", &a[j][i]);
				ne[a[j][i]]++;
			}
		}
		int ne2[50];
		int j = 0;
		for (int i = 0; i <= 2500; i++) {
			if (ne[i] & 1)ne2[j++] = i;
			if (j == N)break;
		}

		fprintf(fpo, "Case #%d:", co);
		for (int i = 0; i < N; i++)
			fprintf(fpo, " %d", ne2[i]);
		fprintf(fpo, "\n");

	}
	fclose(fpi);
	fclose(fpo);
}