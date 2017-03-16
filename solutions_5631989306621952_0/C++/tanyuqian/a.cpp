#include <bits/stdc++.h>

std::string str;

void init() {
	std::cin >> str;
}

void work() {
	std::string answer;
	for (int i = 0; i < (int)str.length(); i ++) {
		answer = std::max(answer + str[i], str[i] + answer);
	}
	std::cout << answer << std::endl;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a1.out", "w", stdout);
	
	int testCnt;
	std::cin >> testCnt;
	for (int i = 1; i <= testCnt; i ++) {
		printf("Case #%d: ", i);
		init();
		work();
	}
	
	return 0;
}
