#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void init();
void runCase();

int main()
{
	init();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
	}
}

// algorithms
int K, L, S;
char keys[101];
int keycnt[26];
char target[101];

void init() {
}

void initKeycnt()
{
	for (int i = 0; i < 26; i++) {
		keycnt[i] = 0;
	}
	for (int i = 0; i < K; i++) {
		keycnt[keys[i] - 'A']++;
	}
}

char tests[101];
int totalCnt;
int maxCnt;
int numTests;

void check()
{
	int cnt = 0;
	for (int i = 0, n = S - L + 1; i < n; i++) {
		char* cur = &tests[i];
		bool matched = true;
		for (int j = 0; j < L; j++) {
			if (target[j] != cur[j]) {
				matched = false;
				break;
			}
		}
		if (matched) {
			cnt++;
		}
	}
	totalCnt += cnt;
	if (maxCnt < cnt) {
		maxCnt = cnt;
	}
	numTests++;
}

void getAll(int depth)
{
	if (depth == S) {
		check();
		return;
	}
	for (int i = 0; i < K; i++) {
		tests[depth] = keys[i];
		getAll(depth + 1);
	}
}

void runCase()
{
	scanf("%d %d %d", &K, &L, &S);
	scanf("%s", keys);
	scanf("%s", target);

	maxCnt = 0;
	totalCnt = 0;
	numTests = 0;
	getAll(0);

	double avgCnt = (double)totalCnt / numTests;
	printf("%.9llf\n", (double)maxCnt - avgCnt);
}
