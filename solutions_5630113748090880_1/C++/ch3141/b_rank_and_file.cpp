// cat input.in | ./a.out > output
#include <iostream>
#include <vector>


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
	int n;
	std::cin >> n;
	
	int num_occurences[2501] = {};
	
	for(int num_inputs = (2*n-1)*n; num_inputs > 0; num_inputs--) {
		int in;
		std::cin >> in;
		num_occurences[in]++;
	}
	
	for(int i=1; i<=2500; i++) {
		if(num_occurences[i] % 2 == 1) {
			std::cout << " " << i;
		}
	}
}


int main() {
	int num_cases;
	std::cin >> num_cases;
	for(int tcase = 1; tcase <= num_cases; tcase++) {
		std::cout << "Case #" << tcase << ":";
		handle_case();
		std::cout << std::endl;
	}
}
