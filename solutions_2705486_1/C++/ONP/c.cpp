#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

char s[100000];
int total, g[1200000][30], danger[1200000];
int f[2][1200000][7], bl[2][1200000][7];
int main()
{
	memset(g, -1, sizeof g);
	FILE *fin = fopen("dict.txt", "r");
	freopen("c.out", "w", stdout);
	while (fscanf(fin, " %s", s) == 1) {
		int now = 0, len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (g[now][s[i] - 'a'] == -1)
				g[now][s[i] - 'a'] = ++total;
			now = g[now][s[i] - 'a'];
		}
		danger[now] = 1;
	}
	fclose(stdin);
/*	Q.push(0);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		if (father[x] == 0)
			suffix[x] = 0;
		else
			suffix[x] = g[suffix[father[x]]][use[x]];
		danger[x] |= danger[suffix[x]];
		for (int i = 0; i < 26; i++)
			if (g[x][i] == -1) {
				g[x][i] = g[suffix[x]][i];
				if (g[x][i] == -1)
					g[x][i] = 0;
			} else {
				Q.push(g[x][i]);
			}
	}
	*/
	freopen("c.in", "r", stdin);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf(" %s", s);
		int len = strlen(s);
		queue <int> Q[2];
		int flip = 0;
		Q[flip].push(0); Q[flip].push(0);
		memset(f, -1, sizeof f);
		memset(bl, -1, sizeof bl);
		f[flip][0][0] = 0;
		bl[flip][0][0] = 0;
		int tim = 0;
		for (int i = 0; i < len; i++) {
			tim++;
			while (!Q[flip].empty()) {
				int x = Q[flip].front(); Q[flip].pop();
				int y = Q[flip].front(); Q[flip].pop();
				int z = f[flip][x][y];
//				cout << i << ' ' << x << ' ' << y << ' ' << z << endl;
				if (y == 0)
					for (int j = 0; j < 26; j++) {
						if (g[x][j] == 0) continue;
						if (g[x][j] == -1) continue;
						if (bl[flip ^ 1][g[x][j]][4] < tim || f[flip ^ 1][g[x][j]][4] > z + 1) {
							f[flip ^ 1][g[x][j]][4] = z + 1;
							if (bl[flip ^ 1][g[x][j]][4] < tim) {
								Q[flip ^ 1].push(g[x][j]);
								Q[flip ^ 1].push(4);
							}
							bl[flip ^ 1][g[x][j]][4] = tim;
							if (danger[g[x][j]]) {
								if (bl[flip ^ 1][0][4] < tim || f[flip ^ 1][0][4] > z + 1) {
									if (bl[flip ^ 1][0][4] < tim) {
										Q[flip ^ 1].push(0);
										Q[flip ^ 1].push(4);
									}
									bl[flip ^ 1][0][4] = tim;
									f[flip ^ 1][0][4] = z + 1;
								}
							}
						}
					}
				if (g[x][s[i] - 'a'] != 0 && g[x][s[i] - 'a'] != -1) {
					if (bl[flip ^ 1][g[x][s[i] - 'a']][max(0, y - 1)] < tim || f[flip ^ 1][g[x][s[i] - 'a']][max(0, y - 1)] > z) {
						if (bl[flip ^ 1][g[x][s[i] - 'a']][max(0, y - 1)] < tim) {
							Q[flip ^ 1].push(g[x][s[i] - 'a']);
							Q[flip ^ 1].push(max(0, y - 1));
						}
						bl[flip ^ 1][g[x][s[i] - 'a']][max(0, y - 1)] = tim;
						f[flip ^ 1][g[x][s[i] - 'a']][max(0, y - 1)] = z;
						if (danger[g[x][s[i] - 'a']]) {
							if (bl[flip ^ 1][0][max(0, y - 1)] < tim || f[flip ^ 1][0][max(0, y - 1)] > z) {
								if (bl[flip ^ 1][0][max(0, y - 1)] < tim) {
									Q[flip ^ 1].push(0);
									Q[flip ^ 1].push(max(0, y - 1));
								}
								bl[flip ^ 1][0][max(0, y - 1)] = tim;
								f[flip ^ 1][0][max(0, y - 1)] = z;
							}
						}
					}
				}
			}
			flip ^= 1;
		}
		int ans = 192837465;
		while (!Q[flip].empty()) {
			int x = Q[flip].front(); Q[flip].pop();
			int y = Q[flip].front(); Q[flip].pop();
			int z = f[flip][x][y];
			if (x == 0)
				ans = min(ans, z);
		}
		printf("Case #%d: %d\n", ++ca, ans);
	}
}
