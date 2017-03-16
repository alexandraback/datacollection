#define _CRT_SECURE_NO_WARNINGS
#define FOR(i, n) for (int i=0; i<n; i++)
#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

int cost[105], visited[100005], cnt, dcnt;
void g(int sum, int i, int v) {

	if (i >= dcnt) return;
	if (sum > v) return;
	
	g(sum, i + 1, v); visited[sum] = 1;
	g(sum + cost[i], i + 1, v); visited[sum + cost[i]] = 1;
}


int main(void) {

	freopen("c:\\input.txt", "r", stdin);
	freopen("c:\\output.txt", "w", stdout);
	int t; scanf("%d", &t);
	FOR(i, t) {
		int c, d, v; scanf("%d%d%d", &c, &d, &v);
		cnt = 0;
		FOR(j, d) scanf("%d", &cost[j]);
		FOR(j, v + 1) visited[j] = 0;

		dcnt = d;
		
		
		while (true) {
			int flag = 0;
			g(0, -1, v);
			for (int j = 1; j <= v; j++) {
				if (visited[j] == 0) {
					cost[dcnt++] = j;
					flag = 1;
					break;
				}
			}
			if (flag == 0) break;
		}
		printf("Case #%d: %d\n", i + 1, dcnt - d);
	}




	return 0;
}