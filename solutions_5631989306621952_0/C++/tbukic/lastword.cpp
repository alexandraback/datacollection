#include <iostream>
#include <string>
#include <deque>

int main() {
	int t;
	std::cin >> t;
	
	std::string s;
	size_t size;
	char front;
	
	for (int i = 0; i < t; ++i) {
	
		std::cin >> s;
		
		size = s.size();
		std::deque<char> last_word(size);

		front = s[0];
		last_word.push_back(front);
		for (size_t elem = 1; elem < size; ++elem) {
			if (s[elem] >= front) {
				last_word.push_front(s[elem]);
				front = s[elem];
			} else {
				last_word.push_back(s[elem]);
			}
		}
		
		std::cout << "Case #" << i + 1 << ": ";
		for (char c : last_word) {
			std::cout << c;
		}
		std::cout << std::endl;
	}

	return 0;
}
