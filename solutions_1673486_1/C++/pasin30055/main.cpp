#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define INF 1000000000
#define PA pair<int, int>
#define PA2 pair<PA, int>
#define MAX_N 100005

using namespace std;

int tests;
int a, b;
double cor[MAX_N];
double val[MAX_N];
double expected;
double answer;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &tests);
	for (int test = 1; test <= tests ; test ++) {
		scanf("%d %d", &a, &b);
		answer = INF;
		for (int i = 0 ; i < a ; i ++) {
			scanf("%lf", &val[i]);
			if (i == 0) cor[i] = val[i];
			else cor[i] = cor[i - 1] * val[i];
		}
		answer = 2 + b;
		for (int i = 0 ; i < a ; i ++) {
			// back to i
			expected = cor[i] * ((a - 1 - i) + (b - 1 - i) + 1) + (1 - cor[i]) * ((a - 1 - i) + (b - 1 - i) + 1 + b + 1);
			//printf("%d %d\n", (a - 1 - i) + (b - 1 - i) + 1, (a - 1 - i) + (b - 1 - i) + 1 + b);
			answer = min(answer, expected);
		}
		// back to zero
		expected = ((a) + (b) + 1);
		answer = min(answer, expected);
		printf("Case #%d: ", test);
		printf("%lf\n", answer);
	}
	return 0;
}