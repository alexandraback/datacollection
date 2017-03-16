#include <iostream>
using namespace std;

int bff[10000];
int longesttomutual[10000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> bff[i];
			bff[i]--;
			longesttomutual[i] = 0;
		}

		int longestcycle = 0;
		for (int i = 0; i < N; i++) {
			int cur = i;
			for (int j = 0; j <= 2 * N; j++) {
				if (bff[bff[cur]] == cur) {
					longesttomutual[cur] = max(longesttomutual[cur], j+1);
					break;
				}
				if (j > 0 && cur == i) {
					longestcycle = max(longestcycle, j);
					break;
				}
				cur = bff[cur];
			}
		}
		int mutualpaths = 0;
		for (int i = 0; i < N; i++) mutualpaths += longesttomutual[i];
		cout << "Case #" << t << ": " << max(longestcycle, mutualpaths) << '\n';
	}

	return 0;
}
