#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 2010

int n, mp[N][N], cnt[N][N], q[N], vis[N];
FILE *fw;
bool ok;

struct node {
	int n;
	int id[N];
}p[N];

void BFS(int x) {
	int i, l = 0, r = 1, tx;
	q[0] = x;
	memset(vis, 0, sizeof(vis));
	while(l < r) {
//		printf("q[%d]=%d\n", l, q[l]);
		tx = q[l];
		for(i = 0; i < n; ++i) {
			if(mp[tx][i] && !vis[i]) {
				q[r] = i;
				cnt[x][i]++;
				vis[i] = 1;
				++r;
			}
			else if(mp[tx][i] && vis[i]) {
				cnt[x][i]++;
				if(cnt[x][i] > 1) {
					ok = true;
					return;
				}
			}
		}
		++l;
	}
	puts("");
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	//	freopen("A-large.in", "r", stdin);
	fw = fopen("A_s0.txt", "w");
	int g = 1, cse, i, j;
	scanf("%d", &cse);
	while (cse--) {
		scanf("%d", &n);
		memset(mp, 0, sizeof(mp));
		memset(cnt, 0, sizeof(cnt));
		for(i = 0; i < n; ++i) {
			scanf("%d", &p[i].n);
			for(j = 0; j < p[i].n; ++j) {
				scanf("%d", &p[i].id[j]);
				mp[i][p[i].id[j] - 1] = 1;
			}
		}
//		for(i = 0; i < n; ++i) {
//			for(j = 0; j < n; ++j) {
//				printf("%d ", mp[i][j]);
//			}
//			puts("");
//		}
		ok = false;
		for(i = 0; !ok && i < n; ++i) {
			BFS(i);
		}
		if(ok) fprintf(fw, "Case #%d: Yes\n", g++);
		else
			fprintf(fw, "Case #%d: No\n", g++);
	}
	fclose(fw);
	return 0;
}
