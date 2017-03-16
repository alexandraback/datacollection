#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define POSSIBLE "POSSIBLE"
#define IMPOSSIBLE "IMPOSSIBLE"

int read() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int b;
long long m;

const long long MAX = (long long)1 << 62;

bool sol[55][55];

void reset() {
	b = 0;
	m = 0;

	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++)
			sol[i][j] = false;
}

void readInput() {
	cin >> b >> m;
}

long long sum() {
	long long dp[55];
	for (int i = 0; i < 55; i++) dp[i] = 0;

	dp[b - 1] = 1;
	for (int i = b - 2; i >= 0; i--) {
		for (int j = i; j < b; j++) {
			if (sol[i][j])
				dp[i] += dp[j];
		}
	}

	return dp[0];
}

int solve() {
	long long ways[55];
	ways[b - 1] = 1;

	for (int i = b - 2; i >= 0; i--) {
		ways[i] = 0;
		for (int j = i + 1; j < b; j++) {
			ways[i] += ways[j];
			if (ways[i] > MAX) {
				ways[i] = MAX;
				continue;
			}
		}
	}

	for (int i = 1; i < b; i++) {
		for (int j = i + 1; j < b; j++) {
			sol[i][j] = true;
		}
	}

	long long t = m;

	for (int i = 1; i < b; i++) {
		if (t >= ways[i]) {
			sol[0][i] = true;
			t -= ways[i];
		}
	}

	if (t > 0) {
		cout << IMPOSSIBLE << endl;
		return 0;
	}

	cout << POSSIBLE << endl;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			if (sol[i][j]) cout << "1"; 
			else cout << "0";
		}
		cout << endl;
	}

	return 0;
}

void printTestCaseHeader(int testIndex) {
	cout << "Case #" << testIndex << ": ";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int __T;
	scanf("%d", &__T);

	for (int i = 1; i <= __T; i++)
	{
		reset();
		readInput();
		printTestCaseHeader(i);
		solve();
		//cout << endl;
	}

	return 0;
}
