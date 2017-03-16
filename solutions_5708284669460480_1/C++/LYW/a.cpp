#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	char keys[101];
	char target[101];
	char targets[101][102];
	for (int testcase = 1; testcase <= testnum; testcase++) {
		int K, L, S;
		scanf("%d %d %d", &K, &L, &S);
		scanf("%s", keys);
		scanf("%s", target);

		for (int i = 0; i <= L; i++) {
			for (int j = 0; j < i; j++)
				targets[i][j] = target[j];
			targets[i][i] = 0;
		}

		map <string, int> prefixes;
		for (int i = 1; i <= L; i++) {
			prefixes[(string)targets[i]] = i;
		}

		int transition[101][101];
		for (int i = 0; i <= L; i++)
			for (int j = 0; j < K; j++)
				transition[i][j] = 0;
		for (int i = 0; i < K; i++) {
			string temp;
			temp.push_back(keys[i]);
			for (int j = 0; j <= L; j++) {
				string new_word = (string)targets[j] + temp;
				for (int k = 0; k <= j; k++) {
					string new_word_part = new_word.substr(k);
					if (prefixes.count(new_word_part)) {
						transition[j][i] = prefixes[new_word_part];
						break;
					}
				}
			}
		}

		double ans1 = 0;
		int max_overlap = 0;
		for (int i = 1; i < L; i++) {
			bool is_overlap = true;
			for (int j = 0; j < L - i; j++) {
				if (target[j] != target[j + i])
					is_overlap = false;
			}
			if (is_overlap) {
				max_overlap = L - i;
				break;
			}
		}
		if (max_overlap == 0)
			ans1 = S / L;
		else
			ans1 = max(S / L, (S - L) / (L - max_overlap) + 1);


		double ans2 = 0;
		double prob[101];
		for (int i = 0; i <= L; i++)
			prob[i] = 0;
		prob[0] = 1;

		for (int i = 0; i < S; i++) {
			double temp_prob[101];
			for (int j = 0; j <= L; j++)
				temp_prob[j] = 0;
			for (int j = 0; j <= L; j++) {
				if (prob[j] == 0) 
					continue;
				for (int k = 0; k < K; k++) {
					temp_prob[transition[j][k]] += prob[j] / K;
				}
			}
			for (int j = 0; j <= L; j++)
				prob[j] = temp_prob[j];
			ans2 += prob[L];
		}

		if (ans2 == 0)
			ans1 = 0;

		fprintf(stderr, "ans1 = %lf ans2 = %lf\n", ans1, ans2);
		if (ans1 - ans2 < 0)
			printf("Case #%d: 0\n", testcase);
		else
			printf("Case #%d: %lf\n", testcase, ans1 - ans2);
	}
	return 0;
}
