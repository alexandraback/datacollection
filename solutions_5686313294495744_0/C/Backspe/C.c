#include <stdio.h>
#include <string.h>

typedef long long ll;

char c[2][1023][30];
int pt[2][1023];
int cnt[2][1023];
int color[2][1023];
int g[2][1023][1023];
int ccnt[2];
int clcnt;

void coloring(int fs, int t, int cl) {
	color[fs][t] = cl;
	ccnt[fs]++;
	int i;
	for(i = 0; i < cnt[fs][t]; i++) {
		if(color[1-fs][g[fs][t][i]] == -1) {
			coloring(1-fs, g[fs][t][i], cl);
		}
	}
}

int main() {
	int t, T;
	int i, j, flag, ans;
	int n, m1, m2, t1, t2;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d", &n);
		m1 = m2 = 0;
		clcnt = 0;
		ans = 0;
		for(i = 0; i < n; i++) {
			pt[0][i] = -1;
			cnt[0][i] = 0;
			color[0][i] = -1;
			for(j = 0; j < n; j++) {
				g[0][i][j] = -1;
				g[1][i][j] = -1;
			}
		}
		for(i = 0; i < n; i++) {
			scanf("%s %s", c[0][i], c[1][i]);
			t1 = t2 = -1;
			for(j = 0; j < i; j++) {
				if(strcmp(c[0][i], c[0][j]) == 0) {
					t1 = pt[0][j];
					pt[0][i] = pt[0][j];
					break;
				}
			}
			if(t1 == -1) {
				t1 = pt[0][i] = m1++;
			}
			for(j = 0; j < i; j++) {
				if(strcmp(c[1][i], c[1][j]) == 0) {
					t2 = pt[1][j];
					pt[1][i] = pt[1][j];
					break;
				}
			}
			if(t2 == -1) {
				t2 = pt[1][i] = m2++;
			}
			g[0][t1][cnt[0][t1]++] = t2;
			g[1][t2][cnt[1][t2]++] = t1;
		}
		//printf("%d %d\n", m1, m2);

		for(i = 0; i < m1; i++) {
			if(color[0][i] == -1) {
				ccnt[0] = ccnt[1] = 0;
				coloring(0, i, clcnt);
				clcnt++;
				//printf("%d %d\n", ccnt[0], ccnt[1]);
				ans += (ccnt[0]>ccnt[1])?ccnt[0]:ccnt[1];
			}
		}
		printf("Case #%d: ", t);
		printf("%d", n-ans);
		printf("\n");
	}
}
