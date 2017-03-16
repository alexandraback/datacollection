#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <ctime>

using namespace std;

const int inf = 1000000;
const int maxN = 110;
int d[maxN][2];

void solve(int test) {
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < maxN; ++i) {
		d[i][0] = d[i][1] = inf;
	}

	d[0][0] = d[0][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; i + j <= n; ++j) {
			int color = 0;
			for (int k = i; k < i + j; ++k) {
				if (s[k] == '+') {
					color |= 1;
				}
				if (s[k] == '-') {
					color |= 2;
				}
			}
			if (color == 3) {
				break;
			}

			--color;
			d[i + j][color] = min(d[i + j][color], d[i][color]);
			d[i + j][1 - color] = min(d[i + j][1 - color], d[i][color] + 1);
			d[i + j][color] = min(d[i + j][color], d[i][1 - color] + 2);
			d[i + j][1 - color] = min(d[i + j][1 - color], d[i][1 - color] + 2);
		}
	}
	printf("Case #%d: %d\n", test, d[n][0]);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
		cerr << i + 1 << ": " << clock() << endl;
	}
	return 0;
}