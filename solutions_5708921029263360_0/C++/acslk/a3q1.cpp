#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int T, J, P, S, K;
int jp[100], ps[100], js[100], jps[1000];

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {

		int total = 0;
		cin >> J >> P >> S >> K;
		memset(jp, 0, 100);
		memset(ps, 0, 100);
		memset(js, 0, 100);
		memset(jps, 0, 1000);

		for (int i = 0; i < J; i++) {
			for (int j = 0; j < P; j++) {
				for (int k = 0; k < S; k++) {
					if (jp[i * 10 + j] < K && ps[j * 10 + k] < K && js[i * 10 + k] < K) {
						jp[i * 10 + j]++;
						ps[j * 10 + k]++;
						js[i * 10 + k]++;
						jps[i * 100 + j * 10 + k] = 1;
						total++;
					}
				}
			}
		}

		printf("Case #%d: %d\n", t, total);
		for (int i = 0; i < J; i++) {
			for (int j = 0; j < P; j++) {
				for (int k = 0; k < S; k++) {
					if (jps[i * 100 + j * 10 + k] == 1)
						printf("%d %d %d\n", i + 1, j + 1, k + 1);
				}
			}
		}

	}
}