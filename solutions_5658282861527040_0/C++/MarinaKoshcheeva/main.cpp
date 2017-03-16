#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

int a, b, k;

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	cin >> a >> b >> k;

	int result = 0;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j) {
			if ((i & j) < k)
				result++;
		}

	cout << result << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
