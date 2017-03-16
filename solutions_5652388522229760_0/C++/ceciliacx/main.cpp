/**
 * Problem: Counting Sheep.
 * Author: Xi Chen (ceciexi@gmail.com)
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

int solve(int N) {
	int curN = N;
	bool v[10] = { 0 }; // visited mark
	int count = 0;
	while (count < 10) {
		// get all digits in N
		int tmpN = curN;
		while (tmpN) {
			int d = tmpN % 10; // digit
			tmpN /= 10;
			count += !v[d];
			v[d] = 1;
		}
		if (count == 10)
			return curN;
		curN += N;
		if (curN > 100 * N || curN == N)
			return 0;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	std::cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		int n;
		std::cin >> n;
		int s = solve(n);
		if (s)
			std::cout << "Case #" << prob << ": " << s << std::endl;
		else
			std::cout << "Case #" << prob << ": " << "INSOMNIA" << std::endl;
	}
	return 0;
}