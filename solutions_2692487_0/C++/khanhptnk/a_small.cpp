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

int ntest, n, m;
int a[110];
int f[110][11000];

void checkmin(int &a, int b) {
	if (b < a) a = b;
}

int main() {
	freopen("input_large.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);
	cin >> ntest;
	for (int test = 0; test < ntest; test++) {
		cin >> m >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= 10000; j++)
				f[i][j] = BIG;
		f[0][m] = 0;		
		for (int i = 0; i < n; i++) 
			for (int j = 0; j <= 10000; j++)
				if (f[i][j] != BIG) 
					if (j > a[i + 1]) {
						checkmin(f[i + 1][j + a[i + 1]], f[i][j]);
					}
					else {
						checkmin(f[i + 1][j], f[i][j] + 1);
						if (j > 1) {
							int k = 1;
							while (j + ((1 << k) - 1) * (j - 1) <= a[i + 1]) k++;
							checkmin(f[i + 1][j + ((1 << k) - 1) * (j - 1) + a[i + 1]], f[i][j] + k); 
						}
					}
		int ans = BIG;
		for (int j = 0; j <= 10000; j++) ans = min(ans, f[n][j]);
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
}
