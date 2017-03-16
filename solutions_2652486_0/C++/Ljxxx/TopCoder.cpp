#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int num[64][3], n, sum[12];
int R, N, M, K;

void input() {
	scanf("%d%d%d%d", &R, &N, &M, &K);
}

void solve() {
	srand(time(NULL));

	for(int i = 0;i < K;i ++) scanf("%d", &sum[i]);

	n = 0;
	for(int i = 2;i <= M;i ++) for(int j = i;j <= M;j ++) for(int k = j;k <= M;k ++) {
		num[n][0] = i;
		num[n][1] = j;
		num[n][2] = k;
		++ n;
	}

	for(int i = 0;i < K;i ++) {
		for(int ii = 0;ii < n;ii ++) {
			int find = 0;
			for(int j = 0;j <= 7&&!find;j ++) {
				int tmp = 1;
				for(int k = 0;k < 3;k ++) if(j&(1<<k)) tmp *= num[ii][k];
				if(tmp == sum[i]) find = 1;
			}

			if(!find) {
				num[ii][0] = num[n-1][0];
				num[ii][1] = num[n-1][1];
				num[ii][2] = num[n-1][2];
				-- n;
				-- ii;
			}
		}
	}

	//for(int i = 0;i < n;i ++) printf("%d %d %d\n", num[i][0], num[i][1], num[i][2]);

	if(n == 1) printf("%d%d%d\n", num[0][0], num[0][1], num[0][2]);
	else {
		int i = rand()%n;
		printf("%d%d%d\n", num[i][0], num[i][1], num[i][2]);
	}
}

int main() {
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	input();
	printf("Case #1:\n");
	t = R;
	for(int cas = 1;cas <= t;cas ++) {
		solve();
	}
	return 0;
}