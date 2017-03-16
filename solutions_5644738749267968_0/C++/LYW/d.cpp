#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector < double > Naomi, Ken;

// Deceitful war
int getAns1(void) {
	int naomiIdx = N - 1;
	int point = 0;
	for (int j = N - 1; j >= 0; j--) {
		if (Naomi[naomiIdx] > Ken[j]) {
			point ++;
			naomiIdx--;
		}
	}
	return point;
}

// War
int getAns2(void) {
	int ret = N;
	vector < bool > used(N, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!used[j] && Naomi[i] < Ken[j]) {
				used[j] = true;
				ret --;
				break;
			}
		}
	}
	return ret;
}

int main(void) {
	int testNum;
	scanf("%d", &testNum);
	for (int testCase = 0; testCase < testNum; testCase++) {
		scanf("%d", &N);
		Naomi.clear();
		Ken.clear();

		for (int i = 0; i < N; i++) {
			double weight;
			scanf("%lf", &weight);
			Naomi.push_back(weight);
		}

		for (int i = 0; i < N; i++) {
			double weight;
			scanf("%lf", &weight);
			Ken.push_back(weight);
		}

		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());

		printf("Case #%d: %d %d\n", testCase + 1, getAns1(), getAns2());
	}
	return 0;
}
