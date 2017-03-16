#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <list>

#define SZ(a) (int(a.size()))
#define MEM(a, val) memset(a, val, sizeof(a))

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;

using namespace std;

const int inf = 1000000001;

int C[109][109];
int F[109][109];
int T[109][109];
int H, N, M;

priority_queue<pair<int, pair<int, int> > > Q;

const int ui[] = {1, -1, 0, 0};
const int uj[] = {0, 0, 1, -1};

inline bool good(int i, int j, int ni, int nj) {
	if (ni >= 1 && ni <= N && nj >= 1 && nj <= M) {
		return (min(C[i][j], C[ni][nj]) - max(F[i][j], F[ni][nj])) >= 50;
	}
	else
		return false;
}

void dejc() {
	while (!Q.empty()) {
		int d = -Q.top().first;
		int i = Q.top().second.first;
		int j = Q.top().second.second;
		Q.pop();
		if (d == T[i][j]) {
			for (int k = 0; k < 4; ++k) {
				int ni = i + ui[k];
				int nj = j + uj[k];
				if (good(i, j, ni, nj)) {
					// min(C[i][j], C[ni][nj]) - 50  ,  H - T[i][j]
					int pH = min(min(C[i][j], C[ni][nj]) - 50  ,  H - T[i][j]);
					int plus = 100;
					if (pH - F[i][j] >= 20)
						plus = 10;
					if (pH == H)
						plus = 0;
					if (min(C[i][j], C[ni][nj]) - 50  <  H - T[i][j]) {
						plus += (H - T[i][j]) - (min(C[i][j], C[ni][nj]) - 50);
					}
					if (T[i][j] + plus < T[ni][nj]) {
						T[ni][nj] = T[i][j] + plus;
						Q.push(make_pair(-T[ni][nj], make_pair(ni, nj)));
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int TT;
	cin >> TT;
	for (int I = 1; I <= TT; ++I) {
		cin >> H >> N >> M;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				cin >> C[i][j];
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				cin >> F[i][j];
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				T[i][j] = inf;
			}
		}

		T[1][1] = 0;
		Q.push(make_pair(0, make_pair(1, 1)));
		dejc();
		printf("Case #%d: %0.9lf\n", I, double(dbl(T[N][M]) / 10.0));
	}
	return 0;
}