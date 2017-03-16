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

long long A, N;
int M[1000011];

int solve(long long A, int N, int M[]) {
	int res = 0, i = 0;
	while (i < N) {
		if (M[i] < A) {
			A += M[i];
			i++;
		} else {
			long long p2 = 2;
			int tres = 1;
			while (p2 * A - (p2 - 1) <= M[i]) {
				tres++;
				p2 *= 2;
			}

			if (tres < N - i) {
				A = p2 * A - (p2 - 1);
				res += tres;
			} else {
				res  += N - i;
				break;
			}
		}
	}
	return res;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 1; t <= testcases; t++) {
		cin >> A >> N;
		
		for (int i=0; i < N; i++) cin >> M[i];
		sort(M, M + N);

		if (A == 1) {
			cout << "Case #" << t << ": " << N << endl;;
			continue;
		}

		long long res = N;
		for (int i = 1; i <= N; i++) {
			res = min(res,  solve(A, i, M) + N - i);
		}

		cout << "Case #" << t << ": " << res << endl;;
	}
	return 0;
}
