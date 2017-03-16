#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;

int T, n, M;
int B[2501];

int main(){
	cin >> T;
	for (int v = 0; v < T; v++) {
		cout << "Case #" << v + 1 << ":";
		cin >> n;
		memset(B, 0, sizeof(B));
		for (int i = 0; i < n + n - 1; ++i) {
			int x;
			for (int j = 0; j < n; ++j) {
				cin >> x;
				B[x]++;
			}
		}

		for (int i = 0; i <= 2500; ++i)
			if (B[i] % 2) cout << ' ' << i;
		cout << endl;
	}
}
