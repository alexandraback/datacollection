#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;
 
int n, m;
bool a[11][11];
bool used[11];
int cnt = 0;
void dfs(int v) {
	used[v] = 1;
	if (v == n - 1) {
		cnt++;
		used[v] = 0;
		return;    
	}
	for (int i = 0; i < n; i++) {
		if (a[v][i] == 1 && !used[i]) {
			dfs(i);
		}
	}
	used[v] = 0;
}
void go(int i, int j) {
	if (i == n - 1)
		return;
	if (i == n - 2 && j == n) {
		cnt = 0;
		dfs(0);
		if (cnt == m) {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << a[i][j];
				}
				cout << endl;
			}
		}
	}
	else {
		if (j == n) {
			i++;
			j = 0;
		}
		if (i != j) {
			a[i][j] = 1;
			go(i, j + 1);
			if (cnt == m) {
				a[i][j] = 0;
				return;
			}
		}
		a[i][j] = 0;
		go(i, j + 1);
	}
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d",&t);
	int number = 1;
	while (t-- > 0) {
		cnt = 0;
		cin >> n >> m;
		printf("Case #%d: ", number++);	
		go(0, 0);
		if (cnt != m) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}