#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long int ll;
const int inf = INT_MAX;
const int max_class = 1000;
int n_class;
int conn[max_class][max_class];
int yes;
void input(void)
{
	int i, j, k;
	scanf("%d\n", &n_class);
	for (i = 0; i < n_class; i++)
		for (j = 0; j < n_class; j++)
			conn[i][j] = -1;

	for (i = 0; i < n_class; i++) {
		int n;
		scanf("%d", &n);
		if (!n) continue;
		for (j = 0; j < n; j++) {
			int c;
			scanf("%d", &c);
			c--;
			conn[i][c] = 1;
		}
	}

	// for (i = 0; i < n_class; i++) {
	// 	for (j = 0; j < n_class; j++)
	// 		printf("%d ", conn[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
}

void output(int icase)
{
	int i, j, k;
	printf("Case #%d: %s", icase + 1, yes == 1 ? "Yes\n" : "No\n");
}

void solve(void)
{
	int i, j, k;
	for (k = 0; k < n_class; k++)
		for (i = 0; i < n_class; i++)
			for (j = 0; j < n_class; j++) {
				if (conn[i][k] == 1 && conn[k][j] == 1) {
					if (conn[i][j] == 1) {
						yes = 1;
						return;
					} else {
						conn[i][j] = 1;
					}
				}
			}
	yes = 0;
}

int main()
{
	int n_case;
	scanf("%d", &n_case);
	for (int i = 0; i < n_case; i++) {
		input();
		solve();
		output(i);
	}
	return 0;
}
