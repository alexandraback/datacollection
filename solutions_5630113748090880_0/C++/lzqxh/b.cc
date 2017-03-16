//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cassert>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 110
#define MOD 1000000007

int n;
int a[2*N][N];
int mat[N][N], ans[N][2];
int mark[N];

int main() {
	int cas, tt = 0;
	cin >> cas;
	while (cas --) {
		cin >> n;
		Rep(i, n*2-1) Rep(j, n) 
			cin >> a[i][j];
		memset(mark, false, sizeof mark);
		memset(mat, -1, sizeof mat);
		Rep(i, n) {
			int tmp = 1<<30, x = -1, y = -1;
			Rep(k, 2 * n - 1) {
				if (mark[k]) continue;
				if (a[k][i] < tmp) {
					x = k; y = -1; tmp = a[k][i];
				} else if (a[k][i] == tmp) y = k;
			}
			ans[i][0] = x;
			mark[x] = true;
			ans[i][1] = y;
			if (y != -1) mark[y] = true; 
		}

		memset(mark, 0, sizeof mark);
		Rep(t, n) {
			int i = -1;
			Rep(k, n) if (mark[k] == 1) { i = k; break; }
			if (i == -1) {
				Rep(k, n) if (mark[k] == 0) { i = k; break; }
			}
//			printf("%d\n", i);
			mark[i] = 2;
			if (ans[i][0] != -1) {
				int k = ans[i][0];
				Rep(j, n) mat[i][j] = a[k][j];
			}
			if (ans[i][1] != -1) {
				int k = ans[i][1];
				Rep(j, n) mat[j][i] = a[k][j];
			}
//			printf("!%d %d\n", ans[i][0], ans[i][1]);
//			Rep(i, n) Rep(j, n) printf("%2d%c", mat[i][j], j == n - 1 ? '\n' : ' ');

			Rep(j, n) {
				if (mat[i][j] != -1 && mat[j][i] != -1 && mat[i][j] != mat[j][i] ||
					ans[j][0] != -1 && ans[j][1] != -1 && a[ans[j][0]][i] != a[ans[j][1]][i]) {
					bool flag = false;
					if (ans[j][1] != -1 && a[ans[j][1]][i] == mat[j][i] ||
						ans[j][0] != -1 && a[ans[j][0]][i] == mat[i][j]) 
						flag = true;
//					printf("j %d\n", j);
					if (flag) {
						assert(mark[j] == 0);
						swap(ans[j][0], ans[j][1]);
					}
					if (mark[j] == 0) mark[j] = 1; 
				}
			}
		}
		printf("Case #%d:", ++tt);
		Rep(k, n) Rep(t, 2)	
			if (ans[k][t] == -1) {
				Rep(j, n) {
					int val = t == 0 ? mat[k][j] : mat[j][k];
					if (j == k) val = a[ans[k][t^1]][k];
					printf(" %d", val);
				}
			}
		puts("");
	}
	return 0;
}
