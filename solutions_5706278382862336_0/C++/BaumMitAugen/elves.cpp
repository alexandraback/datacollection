#include <algorithm>
#include <cassert>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::size_t;

size_t gcd (size_t a, size_t b) {
	while (b != 0) {
		auto temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}



struct Rational {
	size_t zaehler, nenner;
	Rational (size_t a, size_t b)
		: zaehler{a}, nenner{b} {kuerze();}

	void kuerze () {
		auto x = gcd(zaehler,nenner);
		zaehler /= x;
		nenner /= x;
	}

};



int solve (Rational& x) {
	int ret=0, minus = 0;
	auto temp = x;
	while (x.nenner != 1) {
		if (x.nenner % 2 != 0)
			return -1;
		x.nenner /=2;
		++ret;
		if (x.zaehler >= 2) {
			x.zaehler /= 2;
			++minus;
		}
	}
	return ret - minus;
}



int main (int argc, char* argv[]) {
	assert(argc==2);
	std::ifstream in {argv[1]};
	std::ofstream out {"outfile.out"};

	size_t num_cases;
	in >> num_cases;

	for (size_t i = 1; i <= num_cases; ++i) {
		size_t zaehler, nenner;
		char toss;
		in >> zaehler >> toss  >> nenner;
		Rational x {zaehler,nenner};
		auto solu = solve(x);
		if (solu == -1) {
			out << "Case #" << i << ": impossible\n";
		}
		else {
			out << "Case #" << i << ": " << solu << '\n';
		}
	}
}
