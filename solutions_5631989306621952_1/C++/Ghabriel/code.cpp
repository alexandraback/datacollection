#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string parse(std::string S){
	std::string buffer;
	for (char c : S) {
		if (c < buffer[0]) {
			buffer += c;
		} else {
			buffer = c + buffer;
		}
	}
	return buffer;
}

int main(){
	unsigned T, i = 0;
	std::string S;

	std::cin >> T;
	for (unsigned i = 0; i < T; i++) {
		std::cin >> S;
		auto r = parse(S);
		std::cout << "Case #" << (i+1) << ": " << r << std::endl;
	}
}