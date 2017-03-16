#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int B;
long long M;
long long sum[50];

void run_case(int tc) {
    cin >> B >> M;
	memset(sum, 0, sizeof(sum));
	sum[0] = 1;
	for (int i = 1; i < B; i++)
		for (int j = 0; j < i; j++)
			sum[i] += sum[j];
	if (sum[B-1] < M) {
		cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
	} else {
		cout << "Case #" << tc << ": POSSIBLE" << endl;
		bool used[50] = {false};
		for (int i = B-2; i >= 0; i--) {
			if (M >= sum[i]) {
				M -= sum[i];
				used[i] = true;
			}
		}
		for (int i = B - 1; i >= 0; i--)
			if (used[i])
				cout << '1';
			else
				cout << '0';
		cout << endl;
		for (int i = B - 2; i >= 0; i--) {
			for (int j = B - 1; j >= 0; j--)
				if (i > j)
					cout << '1';
				else
					cout << '0';
			cout << endl;
		}
	}
}

int main() {
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		run_case(i);
	}
	return 0;
}