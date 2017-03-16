#include <fstream>
#include <set>


void initDigitSet(std::set<int>& s)
{
	for (int i = 0; i < 10; ++i) {
		s.insert(i);
	}
}

void removeDigit(int a, std::set<int>& s)
{
	while (a > 0) {
		int b = a % 10;
		s.erase(b);
		a /= 10;
	}
}

int main()
{
	std::ifstream infile("infile.txt");
	std::ofstream outfile("outfile.txt");

	int T = 0;
	infile >> T;

	for (int t = 1; t <= T; ++t) {
		int N = 0;
		infile >> N;

		if (N == 0) {
			outfile << "Case #" << t << ": INSOMNIA" << std::endl;
			continue;
		}

		std::set<int> d;
		initDigitSet(d);

		int k = 0;
		int M = 0;
		while (!d.empty()) {
			++k;
			M += N;
			removeDigit(M, d);
		}

		outfile << "Case #" << t << ": " << M << std::endl;
	}

	return 0;
}

