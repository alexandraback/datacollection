//by allenlyh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <complex>

using namespace std;

typedef long long LL;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define sqr(x) (x)*(x)
#define sign(x) ((x)<-eps)?-1:(x)>eps;
#define foreach(ite,s) for (__typeof(s.begin()) ite=s.begin();ite!=s.end();ite++)
#define lowbit(x) ((x) & (-(x)))
const double eps=1e-9;
const int INF=0x3f3f3f3f;

const int maxn=50+5;
int n,m,cnt;
char grp[maxn][maxn];

void print(bool flag) {
	grp[n-1][m-1] = 'c';
	if (flag) {
		for (int i=n-1;i>=0;i--) {
			for (int j=m-1;j>=0;j--) {
				printf("%c", grp[i][j]);
			}
			puts("");
		}
	} else puts("Impossible");
}

void work() {
	scanf("%d%d%d", &n, &m, &cnt);
	memset(grp, 0, sizeof(grp));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			grp[i][j] = '.';
	if (cnt == 0) {
		print(1);
		return;
	}
	if (cnt == n*m-1) {
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				grp[i][j] = '*';
	} else if (n == 1) {
		for (int i=0;i<cnt;i++) grp[0][i] = '*';
	} else if (m == 1) {
		for (int i=0;i<cnt;i++) grp[i][0] = '*';
	} else if (n == 2) {
		if (cnt & 1 || cnt == n*m-2) {
			print(0);
			return;
		}
		for (int i=0;i<cnt/2;i++) grp[0][i] = grp[1][i] = '*';
	} else if (m == 2) {
		if (cnt & 1 || cnt == n*m-2) {
			print(0);
			return;
		}
		for (int i=0;i<cnt/2;i++) grp[i][0] = grp[i][1] = '*';
	} else if (cnt <= (n-2)*m) {
		if (cnt == n*m-7) {
			print(0);
			return;
		}
		int bot=0;
		int tmp=cnt;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				grp[i][j] = '*';
				cnt--;
				if (cnt == 0) break;
			}
			bot = i;
			if (cnt == 0) break;
		}
		if ((tmp % m) == (m-1)) {
			grp[bot][m-2] = '.';grp[bot+1][0] = '*';
			if (bot == n - 3) {
				grp[bot][m-3] = '.';
				grp[bot+2][0] = '*';
			}
		}
	} else if ((n*m - cnt) & 1){
		if (cnt == n*m-7 ||cnt == n*m-5 || cnt > n*m - 4) {
			print(0);
			return;
		}
		for (int i=0;i<n-3;i++) {
			for (int j=0;j<m;j++) {
				grp[i][j] = '*';
				cnt--;
			}
		}
		for (int j=0;j<m-3;j++) {
			grp[n-3][j] = '*';
			cnt--;
		}
		for (int i=0;i<cnt/2;i++) {
			grp[n-2][i] = grp[n-1][i] = '*';
		}
	} else {
		if (cnt > n*m-4) {
			print(0);
			return;
		}
		for (int i=0;i<n-2;i++) {
			for (int j=0;j<m;j++) {
				grp[i][j] = '*';
				cnt--;
			}
		}
		for (int i=0;i<cnt/2;i++) {
			grp[n-2][i] = grp[n-1][i] = '*';
		}
	}
	print(1);
}

int main() {
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d:\n", ++cas);
		work();
	}
	return 0;
}
