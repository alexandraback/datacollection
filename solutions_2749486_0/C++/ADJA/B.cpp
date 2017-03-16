#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>

using namespace std;

const int maxmoves = 500;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int dir[] = {'S', 'W', 'N', 'E'};
const int maxn = 100;
const int pv = 200;

bool d[maxmoves + 5][400][400];
int reached[400][400];
vector <char> ans;
int ci, cj, ck;
int t, x, y;

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	d[0][pv][pv] = true;
	reached[pv][pv] = 0;

	for (int k = 1; k <= maxmoves; k++)
		for (int i = pv - maxn; i <= pv + maxn; i++)
			for (int j = pv - maxn; j <= pv + maxn; j++) {
				for (int l = 0; l < 4; l++) {
					ci = i + di[l] * k; cj = j + dj[l] * k;
					if (ci < pv - maxn || ci > pv + maxn || cj < pv - maxn || cj > pv + maxn)
						continue;
					if (d[k - 1][ci][cj] == true) {
						d[k][i][j] = true;
						//cout << k << " " << i << " " << j << endl;
						if (reached[i][j] == 0)
							reached[i][j] = k;
					}
				}
			}

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%d %d", &x, &y);
		x = pv + x; y = pv - y;

		ck = reached[y][x];
		ans.clear();

		while (y != pv || x != pv) {
			for (int l = 0; l < 4; l++) {
				ci = y + di[l] * ck; cj = x + dj[l] * ck;
				if (ci < pv - maxn || ci > pv + maxn || cj < pv - maxn || cj > pv + maxn)
					continue;
				if (d[ck - 1][ci][cj] == true) {
					ans.push_back(dir[l]);
					ck--; y = ci; x = cj;
				}
			}
		}

		reverse(ans.begin(), ans.end());

		printf("Case #%d: ", test);
		for (int i = 0; i < ans.size(); i++) 
			printf("%c", ans[i]);
		printf("\n");
	}

	return 0;
}