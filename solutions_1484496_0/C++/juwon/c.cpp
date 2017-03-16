#include <cstdio>
#include <vector>

using namespace std;

int n;
int a[500];
vector<int> chk[1000000];

void recur(int cnt, int sum, int state) {
	if (cnt == n) return;
	recur(cnt + 1, sum, state);
	if (sum + a[cnt] < 1000000) {
		chk[sum + a[cnt]].push_back(state + (1 << cnt));
	}
	recur(cnt + 1, sum + a[cnt], state + (1 << cnt));
}

int main() {
	int r;
	int x, y;
	int cs = 0;
	scanf("%d", &r);
	while (r--) {
		scanf("%d", &n);
		for (int i = 0; i < 1000000; ++i) chk[i].clear();
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		recur(0, 0, 0);
		
		int flag = 0;
		for (int i = 1; i < 1000000; ++i) {
			for (int j = 0; j < chk[i].size(); ++j)
				for (int k = j + 1; k < chk[i].size(); ++k) {
					if ((chk[i][j] & chk[i][k]) == 0) {
						flag = 1;
						x = chk[i][j];
						y = chk[i][k];
						break;
					}
				if (flag) break;
			}
			if (flag) break;
		}
		printf("Case #%d:\n", ++cs);
		if (!flag) printf("Impossible\n");
		else {
			vector<int> p ,q;
			for (int i = 0; i < n; ++i) {
				if (x & (1 << i)) p.push_back(a[i]);
				if (y & (1 << i)) q.push_back(a[i]);
			}
			for (int i = 0; i < p.size(); ++i) {
				if (i != 0) printf(" ");
				printf("%d", p[i]);
			}
			printf("\n");
			for (int i = 0; i < q.size(); ++i) {
				if (i != 0) printf(" ");
				printf("%d", q[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
