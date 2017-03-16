#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//*
int m = 0, n = 0;
char res[300];
int flight[60][60];
int visited[60];
int canvisit[60];
char zip[60][10];
int minIndex = 0;

int noother(int index) {
	for (int i = 0; i < n; i++) {
		if (flight[index][i] && !visited[i]) return 0;
	}

	return 1;
}

void visit(int index) {
	// Find min
	int ff = -1;
	minIndex = -1;
	int findex = index - 1;
	for (int i = 0; i < n; i++) {
		if (canvisit[i] == findex) {
			if (noother(i)) ff = 1;
			if (minIndex == -1) minIndex = i;
			else if (strcmp(zip[i], zip[minIndex]) < 0) minIndex = i;
		}
	}

	if (ff == -1) {
		for (int i = 0; i < n; i++) {
			if (canvisit[i]) {
				if (minIndex == -1) minIndex = i;
				else if (strcmp(zip[i], zip[minIndex]) < 0) minIndex = i;
			}
		}
	}

	// Visit
	visited[minIndex] = 1;
	canvisit[minIndex] = 0;
	strcat(res, zip[minIndex]);

	// Extent canvisit
	for (int i = 0; i < n; i++) {
		if (flight[minIndex][i]) {
			if (!visited[i]) canvisit[i] = index;
		}
	}
}

int main(void) {
	FILE * fp = NULL;
	FILE * fout = NULL;
	int t = 0;
	

	if (fopen_s(&fp, "C-small-attempt1.in", "r") != NULL) return -1;
	if (fopen_s(&fout, "C-large.out", "w") != NULL) return -1;

	int startc, endc;
	fscanf(fp, "%d", &t);
	for (int caseIndex = 1; caseIndex <= t; caseIndex++) {
		res[0] = '\0';
		memset(flight, 0, sizeof(flight));
		memset(visited, 0, sizeof(visited));
		memset(canvisit, 0, sizeof(canvisit));

		fscanf(fp, "%d%d", &n, &m);
		minIndex = 0;
		fscanf(fp, "%s", zip[0]);
		for (int i = 1; i < n; i++) {
			fscanf(fp, "%s", zip[i]);
			if (strcmp(zip[i], zip[minIndex]) < 0) minIndex = i;
		}
		for (int i = 0; i < m; i++) {
			fscanf(fp, "%d%d", &startc, &endc);
			startc--;
			endc--;
			flight[startc][endc] = flight[endc][startc] = 1;
		}

		int left = n;
		canvisit[minIndex] = 1;
		while (left > 0) {
			visit(n - left + 1);
			left--;
		}
		

		fprintf(fout, "Case #%d: %s\n", caseIndex, res);
	}

	fclose(fout);
	fclose(fp);

	return 0;
}
//*/