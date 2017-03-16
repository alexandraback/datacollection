#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 2020

string w[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int t;
char S[NN];
int C[256];
int A[10];

void solve(int c, int d) {
	//printf("%c -> %d -> %s -> ", c, d, w[d].data());
	//for (int i = 'A'; i <= 'Z'; ++i) {
	//	printf("%c:%d ", i, C[i]);
	//}
	//printf("\n");
	if (C[c]) {
		int cnt = C[c];
		A[d] += cnt;
		for (char c1 : w[d]) {
			C[int(c1)] -= cnt;
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%s", S);
		string s(S);
		memset(C, 0, sizeof(C));
		memset(A, 0, sizeof(A));
		for (int c : s) {
			++C[c];
		}
		solve('Z', 0);
		solve('W', 2);
		solve('U', 4);
		solve('X', 6);
		solve('G', 8);
		solve('O', 1);
		solve('H', 3);
		solve('F', 5);
		solve('V', 7);
		solve('I', 9);
		string ans;
		for (int i = 0; i < 10; ++i) {
			ans.append(A[i], char(i + '0'));
		}
		printf("Case #%d: %s\n", ti+1, ans.data());
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
