#pragma comment(linker, "/STACK:500000000")
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define y0 y123
#define y1 y1234
#define ll long long
#define llu long long unsigned
#define boolean bool
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9
#define INF 2147483647

int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

int n, m, k;
char a[5][5];
boolean used[5][5];
boolean ans;
	
int xMove[] = {-1,-1,-1, 0,0, 1,1,1};
int yMove[] = {-1, 0, 1,-1,1,-1,0,1};

int cnt(int x, int y) {
	int res = 0;
	for (int i = 0; i < 8; i++) {
		int newX = x + xMove[i];
		int newY = y + yMove[i];
		if (newX >= 0 && newX < n && newY >= 0 && newY < m && a[newX][newY] == '*') {
			res++;
		}
	}
	return res;
}

void dfs(int x, int y) {
	used[x][y] = true;
	if (cnt(x,y) == 0) {
		for (int i = 0; i < 8; i++) {
			int newX = x + xMove[i];
			int newY = y + yMove[i];
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && a[newX][newY] == '.' && !used[newX][newY]) {
				dfs(newX, newY);
			}
		}
	}
}
	
int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int t = nextInt();
	for (int tt = 1; tt <= t; tt++) {
		n = nextInt();
		m = nextInt();
		k = nextInt();
		printf("Case #%d:\n", tt);
		if (k == n*m-1) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (i == 1 && j == 1) {
						printf("c");
					} else {
						printf("*");
					}
				}
				printf("\n");
			}
		} else {
			boolean ans = false;
			int N = n*m;
			for (int mask = 0; mask < (1<<N); mask++) {
				int M = 0;
				for (int i = 0; i < N; i++) {
					if ((mask & (1<<i)) != 0) {
						M++;
						a[i/m][i%m] = '*';
					} else {
						a[i/m][i%m] = '.';
					}
				}
				if (M == k) {
					int x0 = -1;
					int y0 = -1;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (a[i][j] == '.' && cnt(i,j) == 0) {
								x0 = i;
								y0 = j;
								for (int x = 0; x < n; x++) {
									for (int y = 0; y < m; y++) {
										used[x][y] = false;
									}
								}
								dfs(i,j);
								i = n;
								break;
							}
						}
					}
					if (x0 != -1) {
						boolean res = true;
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < m; j++) {
								if (a[i][j] == '.' && !used[i][j]) {
									res = false;
									i = n;
									break;
								}
							}
						}
						if (res == true) {
							a[x0][y0] = 'c';
							ans = true;
							break;
						}
					}
				}
			}				
			if (ans == true) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%c", a[i][j]);
					}
					printf("\n");
				}
			} else {
				printf("Impossible\n");
			}
		}
	}
	return 0;
}