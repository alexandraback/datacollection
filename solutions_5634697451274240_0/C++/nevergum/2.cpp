#include <fstream>


int main()
{
	std::ifstream infile("infile.txt");
	std::ofstream outfile("outfile.txt");

	int T = 0;
	infile >> T;

	for (int t = 1; t <= T; ++t) {
		std::string s;
		infile >> s;

		int count = 0;
		bool flipped = false;
		for (int k = s.size() - 1; k >= 0; --k) {
			if ((s[k] == '-' && !flipped) || (s[k] == '+' && flipped)) {
				flipped = !flipped;
				++count;
			}
		}

		outfile << "Case #" << t << ": " << count << std::endl;
	}

	return 0;
}


