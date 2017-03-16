#include <iostream>
#include <string>
#include <iomanip>

int T, K, L, S;
std::string k, w;

int num_ways;
int largest_score;
int total_score; // average * ways

// occurances of sub in str
int count(std::string str, std::string sub) {
	int c = 0;
	if (str.size() >= sub.size()) {
		for (unsigned int i = 0; i < str.size() - sub.size() + 1; ++i) {
			if (str.substr(i, sub.size()) == sub) {
				++c;
			}
		}
	}
	return c;
}

void f(std::string s) {
	if (s.size() == (unsigned int)S) {
		// test
		int c = count(s, w);
		largest_score = std::max(largest_score, c);
		total_score += c;
		++num_ways;
	} else {
		for (char c : k) {
			f(s + c);
		}
	}
}

int main() {
	// std::cout << count("Hello", "Hello") << '\n';
	// std::cout << count("HeyHey", "Hey") << '\n';
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> K >> L >> S >> k >> w;
		num_ways = 0;
		largest_score = 0;
		total_score = 0;
		f("");
		// std::cout << largest_score << ' ' << total_score << ' ' << num_ways << '\n';
		double fin = (double)largest_score - ((double)total_score / (double)num_ways);
		std::cout << "Case #" << t + 1 << ": " << std::setprecision(7) << fin << '\n';
	}
}