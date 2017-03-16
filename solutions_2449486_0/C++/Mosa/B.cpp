#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

int n, m;
int grid[111][111];

bool ok(int i, int j) {

	bool a = 0, b = 0;
	for(int k = 1; k + j < m; ++k) if(grid[i][k + j] > grid[i][j]) {
		a = 1; break;
	}
	for(int k = 1; j - k >= 0; ++k) if(grid[i][j - k] > grid[i][j]) {
		a = 1; break;
	}
	for(int k = 1; k + i < n; ++k) if(grid[i + k][j] > grid[i][j]) {
		b = 1; break;
	}
	for(int k = 1; i - k >= 0; ++k) if(grid[i - k][j] > grid[i][j]) {
		b = 1; break;
	}
	return !(a && b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	
	int t;
	bool flag;
	scanf("%d", &t);
	for(int tst = 1; tst <= t; ++tst) {
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &grid[i][j]);
		flag = true;
		for(int i = 0; i < n && flag; ++i)
			for(int j = 0; j < m; ++j) if(!ok(i, j)) {
				flag = false;
				break;
			}
		printf("Case #%d: %s\n", tst, (flag) ? "YES" : "NO");
	}

	return 0;
}
