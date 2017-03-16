#include <stdio.h>
#include <algorithm>

using namespace std;

int en;
int bff[1000];
int num_circle;
int cid[10001];
int csize[10001];
char node_status[1000];

int check_circle(int n) {
	//printf("%d %c %d %c\n", n, node_status[n], bff[n], node_status[bff[n]]);
	if (node_status[n] == 'x')
		return -1;
	else if (node_status[bff[n]] == 'x') {
		node_status[n] = 'x';
		return -1;
	}
	else if (node_status[bff[n]] == '?') {
		node_status[n] = 'x';
		return bff[n];
	}
	else {
		node_status[n] = '?';
		int t = check_circle(bff[n]);
		node_status[n] = 'x';
		return t;
	}
}

void mark_circle(int n) {
	num_circle++;
	cid[n] = num_circle;
	//printf("m\n");
	int cnt = 1;
	while (cid[bff[n]] != num_circle) {
		n = bff[n];
		//printf("d %d\n", n);
		cid[n] = num_circle;
		cnt++;
	}
	csize[num_circle] = cnt;
}

int get_chain_length(int n) {
	int max = 0;
	//printf("gl %d\n", n);
	for (int i = 0; i < en; i++) {
		//printf("explore %d\n", i);
		if (cid[i] == 0 && bff[i] == n) {
			int t = get_chain_length(i);
			if (t > max)
				max = t;
		}
	}
	//printf("get_max %d %d\n", n, 1 + max);
	return 1 + max;
}

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		scanf("%d", &en);
		for (int i = 0; i < en; i++) {
			scanf("%d", &bff[i]);
			bff[i]--;
		}

		for (int i = 0; i < en; i++) {
			node_status[i] = '.';
			cid[i] = 0;
		}
		num_circle = 0;
		for (int i = 0; i < en; i++) {
			int re = check_circle(i);
			if (re >= 0) {
				//printf("%d\n", re);
				mark_circle(re);
			}
		}

		//for (int i = 0; i < en; i++)
		//	printf("%d\n", cid[i]);
		//printf("\n");

		int ans = 1;
		for (int i = 1; i <= num_circle; i++) {
			int t = csize[i];
			//printf("i=%d, size=%d\n", i, t);
			if (t == 2) {
				//printf("find l2-circle\n");
				for (int j = 0; j < en; j++)
					if (cid[j] == i) {
						//printf("ch of %d (i=%d)\n", j, i);
						t += get_chain_length(j) - 1;
					}
			}
			if (t > ans)
				ans = t;
		}

		printf("Case #%d: %d\n", ecount, ans);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
