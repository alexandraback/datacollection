#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 2000;
char str[MAXN];
int len;

int getResult() {
	int result = 0;
	int curr = str[0] - '0';

	for (int i = 1; str[i]; i++) {
		result = max(result, i - curr);
		curr += str[i] - '0';
	}

	return result;
}

int main() {
	freopen("a-large.in", "r", stdin);
	freopen("a-large.out", "w", stdout);

	int nCases;
	cin >> nCases;

	for (int cnt = 1; cnt <= nCases; cnt++) {
		cin >> len >> str;
		cout << "Case #" << cnt << ": " << getResult() << endl;
	}

	return 0;
}
