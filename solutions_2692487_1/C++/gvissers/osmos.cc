#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>

template <typename Container>
void readN(std::istream& is, Container& cont, size_t n)
{
	std::copy_n(std::istream_iterator<typename Container::value_type>(is), n,
		std::inserter(cont, cont.end()));
}

int nrOps(unsigned long A, std::vector<unsigned long>::iterator begin,
	std::vector<unsigned long>::iterator end)
{
//std::cerr<< "A = " << A << '\n';
	while (begin != end)
	{
		if (A > *begin)
		{
			A += *begin;
//std::cerr << "eat " << *begin << ", A = " << A << '\n';
			++begin;
		}
		else if (A <= 1)
		{
			return end-begin;
		}
		else
		{
			int c1 = 1 + nrOps(A+A-1, begin, end);
			int c2 = end-begin; //nrOps(A, begin, end-1);
			return std::min(c1, c2);
		}
	}

	return 0;
}

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input-file>\n";
		return 1;
	}

	std::ifstream is(argv[1]);
	if (!is.good())
	{
		std::cerr << "Unable to open input file " << argv[1] << "\n";
		return 1;
	}

	int nr_cases;
	is >> nr_cases;
	if (!is.good())
	{
		std::cerr << "Failed to read number of test cases\n";
		return 1;
	}

	std::vector<unsigned long> Ms;
	for (int icase = 1; icase <= nr_cases; ++icase)
	{
		unsigned long A, N;
		is >> A >> N;
		Ms.clear();
		readN(is, Ms, N);
		std::sort(Ms.begin(), Ms.end());

		std::cout << "Case #" << icase << ": " << nrOps(A, Ms.begin(), Ms.end()) << '\n';
	}

	return 0;
}
