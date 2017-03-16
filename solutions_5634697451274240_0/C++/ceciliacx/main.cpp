/**
 * Problem: Revenge of the Pancakes
 * Author: Xi Chen (ceciexi@gmail.com)
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

int solve(char* arr) {
	int last = arr[0];
	int count = 0;
	int i = 0;
	while (arr[++i]) {
		if (arr[i] != last)
			++count;
		last = arr[i];
	}
	if (arr[i-1] == '-')
		++count;
	return count;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	std::cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		char pancake[100];
		std::cin >> pancake;
		int s = solve(pancake);
		std::cout << "Case #" << prob << ": " << s << std::endl;
	}
	return 0;
}