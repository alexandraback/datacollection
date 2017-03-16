#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
    freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	int b = 0;
	while (T--) {
		vector<int> score;
		int N, s, t, p;
		scanf("%d%d%d", &N, &s, &p);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &t);
			score.push_back(t);
		}

		sort(score.begin(), score.end());

		int ret = 0;
		for (int i = score.size() - 1; i >= 0; --i) {
			int avg = (score[i] + 1) / 3;
			int a = avg;
			int b = avg;
			int c = score[i] - a - b;
			// x x x - 1 -> x + 1 x - 1 x - 1
			// x x x -> x + 1 x x - 1
			// x x x + 1
			int mm = max(a, c);
			if (mm >= p) {
				++ret;
			} else if (s > 0) {
				if (a == c && a > 0) {
					mm = a + 1;
				} else if (a > c && b > 0) {
					mm = a + 1;
				}
				if (mm >= p) {
					++ret;
					--s;
				}
			}
		} 
		printf("Case #%d: %d\n", ++b, ret);
	}
	return 0;
}

