////// GCJ 2013.05.12 1C --- B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 10000000

int bx, by, l, r, ok;
FILE *fp, *fw;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int q[N][2], stp[N], di[N], pre[N], vis[1010][1010];

void BFS() {
	int i, tx, ty;
	q[0][0] = q[0][1] = 0;
	stp[0] = 1;
	l = 0; r = 1;
	memset(vis, 0, sizeof(vis));
	vis[500][500] = 1;
	while(l < r) {
		if(stp[l] >= 500) break;
		for(i = 0; i < 4; ++i) {
			q[r][0] = q[l][0] + stp[l] * d[i][0];
			q[r][1] = q[l][1] + stp[l] * d[i][1];
			if(q[r][0] <= 500 && q[r][0] >= -500 && q[r][1] <= 500 && q[r][1] >= -500 && !vis[q[r][0] + 500][q[r][1] + 500]) {
				//printf("%d %d %d %d %d %d\n", tx, ty, d[i][0], d[i][1], stp[l], l);
				stp[r] = stp[l] + 1;
				di[r] = i;
				pre[r] = l;
				vis[q[r][0] + 500][q[r][1] + 500] = 1;
				if(q[r][0] == bx && q[r][1] == by) return;
				r++;
			}
		}
		++l;
	}
}

int main() {
	int i, cse, dd[510], g = 1, tp;
//	fp = fopen("/home/uriel/workspace/A.txt", "r");
	fp = fopen("/home/uriel/workspace/B-small-attempt3.in", "r");
	fw = fopen("/home/uriel/workspace/outB.txt", "w");
	fscanf(fp, "%d", &cse);
	while(cse--) {
		fscanf(fp, "%d %d", &bx, &by);
		//		printf("%d %d\n", bx, by);
		memset(stp, 0, sizeof(stp));
		BFS();
		tp = r;
		i = 0;
		memset(dd, -1, sizeof(dd));
//		printf("stp=%d\n", stp[l]);
		while(tp != 0) {
//			printf("~%d %d\n", q[tp][0], q[tp][1]);
			dd[i++] = di[tp];
			tp = pre[tp];

		}
//		printf("~%d %d\n", q[tp][0], q[tp][1]);
		fprintf(fw, "Case #%d: ", g++);
		for(; i >= 0; --i) {
			if(dd[i] == 0) fprintf(fw, "W");
			if(dd[i] == 1) fprintf(fw, "E");
			if(dd[i] == 2) fprintf(fw, "S");
			if(dd[i] == 3) fprintf(fw, "N");
		}
		fprintf(fw, "\n");
//		puts("");
	}
	fclose(fp);
	fclose(fw);
	return 0;
}
