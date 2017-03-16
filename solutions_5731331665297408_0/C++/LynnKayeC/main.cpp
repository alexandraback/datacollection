/*
 * main.cpp
 *
 *  Created on: May 3, 2014
 *      Author: blding
 */


#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 8;

int caseNum;
FILE * fin;
FILE * fout;

int n, m;
char zips[MAXN][6];
int outbound[MAXN][MAXN];
int ans[MAXN];
int visited[MAXN];
int path[MAXN];
int inbound[MAXN][2];
int used[MAXN];
int zipValue[MAXN];

void sortZips()
{
	for (int i = 0; i < n; ++i) {
		zipValue[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (strcmp(zips[zipValue[i]], zips[zipValue[j]]) > 0) {
				int tmp = zipValue[i];
				zipValue[i] = zipValue[j];
				zipValue[j] = tmp;
			}
		}
	}
//	for (int i = 0; i < n; ++i) {
//		fprintf(stdout, "%d ", zipValue[i]);
//	}
//	fprintf(stdout, "\n");
}

bool isSmaller()
{
	if (ans[0] == n)
		return true;
	for (int i = 0; i < n; ++i) {
		int cmp = strcmp(zips[ans[i]], zips[path[i]]);
		if (cmp < 0)
			return false;
		if (cmp > 0)
			return true;
	}
	return false;
}

void search(int cur, int cityCnt, int inLeft)
{
	//fprintf(stdout, "search %d %d %d\n", cur, cityCnt, inLeft);

	if (cityCnt == n && inLeft == 0) {
		if (isSmaller()) {
//			for (int i = 0; i < n; ++i) {
//				fprintf(stdout, "%d ", path[i]);
//			}
//			fprintf(stdout, "\n");

			for (int i = 0; i < n; ++i)
				ans[i] = path[i];
		}
	} else {
		// select outbound
		if (cityCnt < n) {
			for (int i = 0; i < n; ++i) {
				if (visited[i] == 0 && outbound[cur][i]) {
					visited[i] = 1;
					inbound[cityCnt - 1][0] = i;
					inbound[cityCnt - 1][1] = cur;
					used[cityCnt - 1] = 0;
					path[cityCnt] = i;
					search(i, cityCnt + 1, inLeft + 1);
					visited[i] = 0;
				}
			}
		}
		// select inbound
		if (inLeft > 0) {
			for (int i = 0; i < cityCnt - 1; ++i) {
				if (used[i] == 0 && inbound[i][0] == cur) {
					used[i] = 1;
					search(inbound[i][1], cityCnt, inLeft - 1);
					used[i] = 0;
				}
			}
		}
	}
}

void work(int caseId)
{
	for (int i = 0; i < n; ++i) {
		ans[i] = n;
		visited[i] = 0;
		used[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		//fprintf(stdout, "start with %d\n", zipValue[i]);
		visited[zipValue[i]] = 1;
		path[0] = zipValue[i];
		search(zipValue[i], 1, 0);
		visited[zipValue[i]] = 0;
		if (ans[0] != n)
			break;
	}
	fprintf(fout, "Case #%d: ", caseId);
	for (int i = 0; i < n; ++i) {
		fprintf(fout, "%s", zips[ans[i]]);
	}
	fprintf(fout, "\n");
}


int main()
{
	fin = fopen("../input", "r");
	fout = fopen("../output", "w");
	fscanf(fin, "%d ", &caseNum);
	for (int caseId = 1; caseId <= caseNum; ++caseId) {
		fscanf(fin, "%d %d ", &n, &m);
		for (int i = 0; i < n; ++i) {
			fscanf(fin, "%s ", zips[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				outbound[i][j] = 0;
			}
		}

		for (int i = 0; i < m; ++i) {
			int a, b;
			fscanf(fin, "%d %d ", &a, &b);
			outbound[a - 1][b - 1] = outbound[b - 1][a - 1] = 1;
		}

		sortZips();
		work(caseId);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

