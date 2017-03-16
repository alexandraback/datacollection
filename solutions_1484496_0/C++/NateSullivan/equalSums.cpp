#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int T, tt, n;
vector<int> numbers;
map<int, int> sums;

bool load() {
	if (tt == T) {
		return false;
	}
	tt++;
	numbers.clear();
	sums.clear();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		numbers.push_back(input);
	}
	return true;
}

int getSum(int mask) {
	int sum = 0;
	for (int i = 0; i < 20; i++) {
		bool included = mask % 2;
		if (included) {
			sum += numbers[i];
		}
		mask /= 2;
	}
	return sum;
}

void printMask(int mask) {
	bool first = true;
	for (int i = 0; i < 20; i++) {
		bool included = mask % 2;
		if (included) {
			printf("%s%d", first ? "" : " ", numbers[i]);
			first = false;
		}
		mask /= 2;
	}
	printf("\n");
}

int main() {
	cin >> T;
	tt = 0;
	while (load()) {
		printf("Case #%d:\n", tt);
		bool done = false;
		for (int mask = 1; mask < (1 << 20); mask++) {
			int sum = getSum(mask);
			if (sums.count(sum) > 0) {
				printMask(mask);
				printMask(sums[sum]);
				done = true;
				break;
			} else {
				sums[sum] = mask;
			}
		}
		if (!done) {
			printf("Impossible\n");
		}
	}
	return 0;
}
