#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool win(double score, vector<int> &others, double audience) {
	double consume = 0.0;
	for (int i = 0; i < others.size(); i++) {
		consume += max(score - others[i], 0.0);
	}
	if (audience < consume) return false;
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	int N;
	int s[256], s2[256];
	for (int case_x = 1; case_x <= T; case_x++) {
		printf("Case #%d:", case_x);
		scanf("%d", &N);
		double sum = 0.0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		for (int i = 0; i < N; i++) {
			vector<int> others;
			for (int j = 0; j < N; j++) {
				if (i != j) others.push_back(s[j]);
			}
			sort(others.begin(), others.end());
			double lower = 0.0, upper = sum;
			for (int j = 0; j < 50; j++) {
				double mean = (lower + upper) / 2.0;
				if (win(s[i] + mean, others, sum - mean)) {
					lower = mean;
				} else {
					upper = mean;
				}
			}
			printf(" %f", (lower + upper) / 2.0 / sum * 100.0);
		}
		puts("");
	}
}
