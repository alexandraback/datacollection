#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <set>
#include <string>

using namespace std;

int n, m;
char code[100][8];
char mt[100][100];
int cused[100];
int nused = 0;
int ord[100];
char ans[100 * 5];

void solve(int v) {
	if (!cused[v])
	{
		ord[nused++] = v;
	}
	cused[v]++;
	if (nused == n) {
		int eqI = -1, eqC = -1;
		bool ended = false, less;
		for (int i = 0; i < n && !ended; i++) {
			for (int c = 0; c < 5; c++) {
				if (code[ord[i]][c] != ans[i * 5 + c]) {
					ended = true;
					eqI = i;
					eqC = c;
					break;
				}
			}
		}
		less = code[ord[eqI]][eqC] < ans[eqI * 5 + eqC];
		if (less) {
			for (int i = 0; i < n; i++) {
				for (int c = 0; c < 5; c++) {
					ans[i * 5 + c] = code[ord[i]][c];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!cused[i] && mt[v][i] == 'p') {
			mt[v][i] = 'g';
			mt[i][v] = 'r';
			solve(i);
			mt[v][i] = 'p';
			mt[i][v] = 'p';
		} else if (mt[v][i] == 'r' && nused < n) {
			solve(i);
		}
	}
	if (cused[v] == 1)
		nused--;
	cused[v]--;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tcase = 1; tcase <= t; tcase++)
	{
		printf("Case #%d: ", tcase);
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> code[i];
		for (int i = 0; i < n; i++)
		{
			cused[i] = 0;
			for (int j = 0; j < 5; j++)
				ans[i * 5 + j] = '9';
			ans[n * 5] = 0;
			for (int j = 0; j < n; j++)
				mt[i][j] = '-';
			mt[i][n] = 0;
		}

		for (int i = 0; i < m; i++) {
			int fr, to;
			cin >> fr >> to;
			--fr, --to;
			mt[fr][to] = 'p';
			mt[to][fr] = 'p';
		}
		nused = 0;


		for (int i = 0; i < n; i++)
			solve(i);

		printf("%s\n", ans);
		continue;
	}
}