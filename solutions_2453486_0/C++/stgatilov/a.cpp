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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int n = 4;
char matr[16][16];
int hor[16], vert[16], sum[16], diff[16];

bool ok(char c, int p) {
	if (c == 'T') return true;
	return c == (p == 0 ? 'O' : 'X');
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		for (int i = 0; i<n; i++) scanf("%s", matr[i]);

		bool wins[2] = {false};
		for (int cc = 0; cc<2; cc++) {
			memset(hor, 0, sizeof(hor));
			memset(vert, 0, sizeof(vert));
			memset(sum, 0, sizeof(sum));
			memset(diff, 0, sizeof(diff));

			for (int i = 0; i<n; i++)
				for (int j = 0; j<n; j++) {
					int a = ok(matr[i][j], cc);
					hor[i] += a;
					vert[j] += a;
					sum[i+j] += a;
					diff[n+i-j] += a;
				}

			for (int i = 0; i<=2*n; i++)
				if (hor[i] == n || vert[i] == n || sum[i] == n || diff[n] == n)
					wins[cc] = true;
		}

		int freek = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				freek += (matr[i][j] == '.');


		printf("Case #%d: ", tt);
		if (wins[0]) printf("O won");
		else if (wins[1]) printf("X won");
		else if (!freek) printf("Draw");
		else printf("Game has not completed");
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
