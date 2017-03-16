#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <numeric>

#define all(x) x.begin(), x.end()
#define INF 0x7fffffff
#define PI acos(-1)

using namespace std;

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 1; t <= testcases; t++) {
		int N, M;
		int Rma[111] = {0};
		int Cma[111] = {0};
		int G[111][111] = {0};

		cin >> N >> M;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> G[i][j];
				Rma[i] = max(Rma[i], G[i][j]);
				Cma[j] = max(Cma[j], G[i][j]);
			}
		}

		bool good = true;
		for (int i=0; i<N && good; i++)
			for (int j=0; j<M && good; j++)
				if (G[i][j] != Rma[i] && G[i][j] != Cma[j])
					good = false;

		cout << "Case #" << t << ": " << (good ? "YES" : "NO") << endl;
	}
	return 0;
}
