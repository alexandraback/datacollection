#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

int T, N;
int cnt[255];
int x[15];

int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);
		
		string S;
		cin >> S;

		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < S.length(); i++) {
			cnt[S[i]]++;
		}

		memset(x, 0, sizeof x);
		x[0] = cnt['Z'];
		x[2] = cnt['W'];
		x[4] = cnt['U'];
		x[6] = cnt['X'];
		x[8] = cnt['G'];
		x[1] = cnt['O'] - x[4] - x[0] - x[2];
		x[3] = cnt['T'] - x[8] - x[2];
		x[5] = cnt['F'] - x[4];
		x[7] = cnt['V'] - x[5];
		x[9] = cnt['I'] - x[5] - x[6] - x[8];

		for (int i = 0; i < 10; i++)
			for (int k = 0; k < x[i]; k++)
				putchar(i + '0');

		puts("");
	}
	return 0;
}
