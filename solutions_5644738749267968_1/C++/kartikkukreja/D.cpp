#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, N, t, i, left, right, scoreD, scoreW;
	double Naomi[1005], Ken[1005];
	
	freopen("D-large.in", "r", stdin);
	freopen("D.txt", "w", stdout);
	
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%lf", &Naomi[i]);
		for (i = 0; i < N; i++)
			scanf("%lf", &Ken[i]);
		sort (Naomi, Naomi + N);
		sort (Ken, Ken + N);
		
		for (i = left = scoreD = 0; i < N; i++) {
			if (Naomi[i] > Ken[left]) {
				scoreD++;
				left++;
			}
		}
		for (i = right = N-1, scoreW = 0; i >= 0; i--) {
			if (Naomi[i] > Ken[right])
				scoreW++;
			else
				right--;
		}
		printf("Case #%d: %d %d\n", t, scoreD, scoreW);
	}
	
	return 0;
}
