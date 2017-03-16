#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Cruise Control

static int graph[50][50];
static int lane[50];

bool dfs(int index, int l, int N)
{
	if (lane[index] != 0) {
		return (lane[index] == l);
	}
	lane[index] = l;
	for (int i = 0; i < N; i++) {
		if (i != index && graph[index][i]) {
			if (!dfs(i, -l, N)) {
				return false;
			}
		}
	}
	return true;
}

bool check(double t, vector <int> &S, vector <int> &P)
{
	int N = S.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i] < S[j]) {
				double b = (double)(P[i] - P[j] - 5) / (S[j] - S[i]);
				double e = (double)(P[i] - P[j] + 5) / (S[j] - S[i]);
				if (b <= t && t < e) {
					graph[i][j] = graph[j][i] = 1;
				} else {
					graph[i][j] = graph[j][i] = 0;
				}
			} else if (S[i] == S[j]) {
				if (abs(P[i] - P[j]) < 5) {
					graph[i][j] = graph[j][i] = 1;
				} else {
					graph[i][j] = graph[j][i] = 0;
				}
			}
		}
	}
	memset(lane, 0, sizeof(lane));
	for (int i = 0; i < N; i++) {
		if (lane[i] == 0) {
			if (!dfs(i, 1, N)) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N;
		cin >> N;
		vector <char> C(N);
		vector <int> S(N);
		vector <int> P(N);
		for (int i = 0; i < N; i++) {
			cin >> C[i] >> S[i] >> P[i];
		}
		double ret = 1e100;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (S[i] < S[j]) {
					double b = (double)(P[i] - P[j] - 5) / (S[j] - S[i]);
					double e = (double)(P[i] - P[j] + 5) / (S[j] - S[i]);
					b = max(b, 0.0);
					if (e >= 0 && check(b, S, P)) {
						ret = min(ret, b);
					}
				}
			}
		}
		if (ret == 1e100) {
			printf("Case #%d: Possible\n", caseno);
		} else {
			printf("Case #%d: %.9f\n", caseno, ret);
		}
	}

	return 0;
}
