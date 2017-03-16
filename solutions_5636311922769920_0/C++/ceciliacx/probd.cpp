/**
* Problem: Revenge of the Pancakes
* Author: Xi Chen (ceciexi@gmail.com)
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>


long long getNextIndex(long long lastLevelIndex, int lastOrgIndex, int orgLevelLength, int curLevel, int maxLevel) {
	if (curLevel > maxLevel)
		return lastLevelIndex;
	if (lastOrgIndex < orgLevelLength)
		lastOrgIndex++;
	long long curIndex = orgLevelLength * (lastLevelIndex - 1) + lastOrgIndex;
	if (curLevel == maxLevel)
		return curIndex;
	else return getNextIndex(curIndex, lastOrgIndex, orgLevelLength, curLevel + 1, maxLevel);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	std::cin >> N;
	for (int prob = 1; prob <= N; prob++) {
		int K, C, S;
		std::cin >> K >> C >> S;
		int minS = K%C ? K / C + 1 : K / C;
		std::cout << "Case #" << prob << ":";
		if (S < minS) {
			std::cout << " IMPOSSIBLE" << std::endl;
			continue;
		}
		for (int i = 0; i < minS; i++) {
			int startIndex = 1 + i * C;
			std::cout << " " << getNextIndex(startIndex, startIndex, K, 2, C);
		}
		std::cout << std::endl;
	}
	return 0;
}
