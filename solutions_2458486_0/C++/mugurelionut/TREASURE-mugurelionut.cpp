#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 211

int CNT[NMAX], o[NMAX], topen[NMAX], nkeys[NMAX], key[NMAX][NMAX], opened[NMAX];
int N, K;

void Open(int idx, int level) {
	int i;
	//fprintf(stderr, "   Open %d %d\n", idx, level);
	CNT[topen[idx]]--;
	if (CNT[topen[idx]] < 0) {
		fprintf(stderr, "Negative key count!\n");
		exit(1);
	}
	opened[idx] = level;
	for (i = 0; i < nkeys[idx]; i++)
		CNT[key[idx][i]]++;
}

void Close(int idx) {
	int i;
	//fprintf(stderr, "   Close %d\n", idx);
	opened[idx] = 0;
	CNT[topen[idx]]++;
	for (i = 0; i < nkeys[idx]; i++)
		CNT[key[idx][i]]--;
}

char visited[NMAX];
int q[NMAX], li, ls;
int needed[NMAX], level;

int BFS(int start) {
	int i, j, k, p;

	//fprintf(stderr, "start bfs %d\n", start);

	memset(visited, 0, sizeof(visited));
	visited[start] = 1;
	q[li = ls = 1] = start;
	
	while (li <= ls) {
		i = q[li];
		li++;
		
		for (j = 0; j < nkeys[i]; j++) {
			k = key[i][j];
			//fprintf(stderr, "   in bfs: i=%d j=%d k=%d\n", i, j, k);
			if (k == topen[start]) {
				//fprintf(stderr, "finish bfs: 1\n");
				return 1;
			}
			for (p = 1; p <= N; p++)
				if (!opened[p] && !visited[p] && topen[p] == k) {
					visited[p] = 1;
					ls++;
					q[ls] = p;
				}
		}
	}

	//fprintf(stderr, "finish bfs: 0\n");
	return 0;
}

int Solve() {
	int i, j, nclosed = 0, result;

	level++;
	
	memset(needed, 0, sizeof(needed));
	for (i = 1; i <= N; i++)
		if (!opened[i]) {
			nclosed++;
			needed[topen[i]]++;
		}

	if (nclosed == 0) {
		level--;
		return 1;
	}

	/*
	fprintf(stderr, "Solve level=%d\n", level);
	for (i = 1; i < NMAX; i++)
		if (CNT[i] >= 1 || needed[i] >= 1)
			fprintf(stderr, "key type %d: CNT=%d needed=%d\n", i, CNT[i], needed[i]);
	*/

	for (i = 1; i < NMAX; i++)
		if (CNT[i] >= needed[i] && needed[i] >= 1) {
			for (j = 1; j <= N; j++)
				if (!opened[j] && topen[j] == i)
					Open(j, level);
			
			result = Solve();
			
			for (j = 1; j <= N; j++)
				if (opened[j] == level && topen[j] == i)
					Close(j);
			level--;
			return result;
		}

	for (i = 1; i <= N; i++)
		if (!opened[i] && CNT[topen[i]] >= 1) {
			// Check if this is a good candidate to open.
			Open(i, level);
			if (BFS(i)) {
				result = Solve();
				Close(i);
				level--;
				return result;
			}
			Close(i);
		}
	
	level--;
	return 0;
}

int main() {
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D1.out", "w", stdout);

	int T, te, i, j;
	scanf("%d", &T);
	
	for (te = 1; te <= T; te++) {
		scanf("%d %d", &K, &N);

		memset(CNT, 0, sizeof(CNT));
		for (i = 1; i <= K; i++) {
			scanf("%d", &j);
			CNT[j]++;
		}

		for (i = 1; i <= N; i++) {
			scanf("%d %d", &(topen[i]), &(nkeys[i]));
			for (j = 0; j < nkeys[i]; j++)
				scanf("%d", &(key[i][j]));
			//fprintf(stderr, "i=%d nkeys=%d\n", i, nkeys[i]);
		}

		memset(opened, 0, sizeof(opened));
		level = 1;
		for (i = 1; i <= N; i++) {
			for (o[i] = 1; o[i] <= N; o[i]++)
				if (!opened[o[i]] && CNT[topen[o[i]]] >= 1) {
					//fprintf(stderr, "Testing i=%d: chest=%d\n", i, o[i]);
					Open(o[i], 1);
					if (Solve())
						break;
					Close(o[i]);
				}
			if (o[i] > N)
				break;
		}

		printf("Case #%d:", te);
		if (i <= N)
			printf(" IMPOSSIBLE\n");
		else {
			for (i = 1; i <= N; i++)
				printf(" %d", o[i]);
			printf("\n");
		}
	}
	
	return 0;
}
