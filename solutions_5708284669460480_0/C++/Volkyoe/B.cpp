#include"stdio.h"
#include"stdlib.h"
#include"algorithm"
#include"vector"
using namespace std;
int t, T, K, L, S, Max;
double prob[26], ans;
char kb[200], word[200], want[200];
vector<int> list;
void dfs(int depth, double pr) {
	if (depth == S) {
		int count = 0;
		for (int i = 0; i <= depth - L; i++) {
			int match = 1;
			for (int j = i; j < i + L; j++) {
				if (word[j] != want[j-i]) {
					match = 0;
					break;
				}
			}
			if (match) count++;
		}
		Max = max(Max, count);
		ans += (pr * count);
		return;
	}
	for (int i = 0; i < list.size(); i++) {
		word[depth] = list[i] + 'A';
		dfs(depth + 1, pr * prob[list[i]]);
	}
}
void solveSmall() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.txt", "w", stdout);
	scanf("%d", &T);
	while (t < T) {
		ans = Max = 0;
		list.clear();
		for (int i = 0; i < 26; i++) prob[i] = 0;
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s%s", kb, want);
		for (int i = 0; kb[i]; i++) prob[kb[i] - 'A'] += 1.0;
		for (int i = 0; i < 26; i++) {
			if (prob[i] > 0) list.push_back(i);
			prob[i] /= K;
			//printf("[%c:%.2lf] ", i+'A', prob[i]);
		}
		//printf("\n"); for (int i = 0; i < list.size(); i++) printf("%c", list[i]+'A'); printf("\n");
		dfs(0, 1.);
		printf("Case #%d: %lf\n", ++t, Max - ans);
	}
}
void solveLarge() {
	//freopen(".in", "r", stdin);
	//freopen(".txt", "w", stdout);
}
int main() {
	solveSmall();
	//solveLarge();
}
