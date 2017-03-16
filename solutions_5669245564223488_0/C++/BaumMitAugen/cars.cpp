#include <algorithm>
#include <cassert>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using std::size_t;

bool is_valid  (const std::vector<std::string>& x) {
	std::vector<int> res(256);

	char last = '0';
	for (size_t i = 0; i < x.size(); ++i)	{
		if (last != x[i][0])
			++res[static_cast<size_t>(x[i][0])];
		for (size_t j = 1; j < x[i].size(); ++j) {
			if (x[i][j] != x[i][j-1]) 
				++res[static_cast<size_t>(x[i][j])];
		}
		last = x[i].back();
	}
	return std::all_of(res.begin(),res.end(),
		[](const int c){return c <= 1;});
}

size_t solve (std::vector<std::string>& x) {
	std::sort(x.begin(),x.end());

	size_t res = 0;
	do {
		if (is_valid(x))
			++res;
	}
	while (std::next_permutation(x.begin(),x.end()));

	for (size_t i = 0; i < x.size(); ++i) {
		for (size_t j = i + 1; j < x.size(); ++j) {
			if (x[i] == x[j])
				res *= 2;
		}
	}

	return res % 1000000007;
}

int main (int argc, char* argv[]) {
	assert(argc==2);
	std::ifstream in {argv[1]};
	std::ofstream out {"outfile.out"};

	size_t num_cases;
	in >> num_cases;

	for (size_t i = 1; i <= num_cases; ++i) {
		size_t num_cars;
		in >> num_cars;
		std::vector<std::string> x;
		for (int j = 0; j < num_cars; ++j) {
			std::string temp;
			in >> temp;
			x.push_back(std::move(temp));
		}
		out << "Case #" << i << ": " << solve(x) << "\n";
	}
}
