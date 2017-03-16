#include <algorithm>
#include <cstddef>
#include <fstream>
#include <vector>

using std::size_t;

size_t result (size_t old_max, size_t new_max, size_t bought) {
	size_t res = 0;
	for (size_t i = 0; i < old_max; ++i) {
		for (size_t j = 0; j < new_max; ++j) {
			if (bought > (i&j))
				++res;
		}
	}
	return res;
}

int main (int argc, char* argv[]) {
	std::ifstream in {argv[1]};
	std::ofstream out {"outfile.out"};

	size_t num_cases;
	in >>  num_cases;

	for (size_t i = 1; i <= num_cases; ++i) {
		size_t old_max, new_max, bought;
		in >> old_max >> new_max >> bought;
		out << "Case #" << i << ": " 
			<< result(old_max,new_max,bought) << '\n';
	}
}