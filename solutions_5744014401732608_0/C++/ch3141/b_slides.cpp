// cat input.in | ./a.out > output
#include <iostream>
#include <vector>
#include <algorithm>


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




std::string binary(myint i, int num_digits) {
	std::string s;
	while(num_digits>0) {
		s += (i&1) ? "1" : "0";
		i = i>>1;
		num_digits--;
	}
	std::reverse(s.begin(), s.end());
	return s;
}


// has to print everything except "Case #n: " and eol \n
// read from std::cin
void handle_case() {
	int b;
	std::cin >> b;
	myint m;
	std::cin >> m;
	
	if(m > (1<<(b-2))) {
		std::cout << "IMPOSSIBLE" << std::endl;
		return;
	}
	
	std::cout << "POSSIBLE" << std::endl;
	
	if(m == (1<<(b-2)))
		std::cout << binary(m-1, b-1) << "1" << std::endl;
	else
		std::cout << binary(m,b-1) << "0" << std::endl;
	
	for(int b2=2; b2<=b; b2++) {
		for(int i=1; i<=b; i++) {
			if(i<=b2) std::cout << "0";
			else std::cout << "1";
		}
		std::cout << std::endl;
	}
}


int main() {
	int num_cases;
	std::cin >> num_cases;
	for(int tcase = 1; tcase <= num_cases; tcase++) {
		std::cout << "Case #" << tcase << ": ";
		handle_case();
	}
}
