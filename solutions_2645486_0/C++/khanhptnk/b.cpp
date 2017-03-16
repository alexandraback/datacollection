#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define BIG 1000000000
using namespace std;

int ntest;
int e, r, n;
int v[110];
int f[110][110];


int main() {
	//freopen("input.txt", "r", stdin);
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);
	cin >> ntest;
	for (int test = 0; test < ntest; test++) {
		cin >> e >> r >> n;
		for (int i = 1; i <= n; i++) cin >> v[i];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= e; j++) f[i][j] = -BIG;
		f[0][e] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= e; j++)
				if (f[i][j] != -BIG)
					for (int k = 0; k <= j; k++)
						f[i + 1][min(e, j - k + r)] = max(f[i + 1][min(e, j - k + r)], f[i][j] + k * v[i + 1]);
		int ans = -BIG;
		for (int i = 0; i <= e; i++)
			ans = max(ans, f[n][i]);
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
}
