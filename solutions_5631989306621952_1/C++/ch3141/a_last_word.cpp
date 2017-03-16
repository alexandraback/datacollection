// cat input.in | ./a.out > output
#include <iostream>
#include <vector>
#include <string>
#include <deque>

typedef long long myint;

template <typename T>
std::vector<T> read_vector(int length, std::istream& in = std::cin) {
	std::vector<T> vector;
	for(; length>0; length--) {
		T item;
		in >> item;
		vector.push_back(item);
	}
	return vector;
}







// has to print everything except "Case #n: " and eol \n
// read from std::cin
void handle_case() {
	int l;
	std::string s;
	std::cin >> s;
	
	std::deque<char> q;
	
	auto it = s.begin();
	q.push_back(*it);
	it++;
	
	for(; it != s.end(); it++) {
		if(*it >= q.front()) q.push_front(*it);
		else q.push_back(*it);
	}
	
	for(char c: q)
		std::cout << c;
}


int main() {
	int num_cases;
	std::cin >> num_cases;
	for(int tcase = 1; tcase <= num_cases; tcase++) {
		std::cout << "Case #" << tcase << ": ";
		handle_case();
		std::cout << std::endl;
	}
}
