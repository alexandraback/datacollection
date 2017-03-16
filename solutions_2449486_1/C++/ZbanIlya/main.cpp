#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
int a[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tests;
    cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				cin >> a[i][j];

		bool ans = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				bool f1 = 1, f2 = 1;
				for (int k = 1; k <= m; k++)
					f1 &= a[i][j] >= a[i][k];
				for (int k = 1; k <= n; k++)
					f2 &= a[i][j] >= a[k][j];
				ans &= f1 || f2;
			}
		}

		cout << (ans ? "YES" : "NO");
		cout << endl;
	}

	return 0;
}