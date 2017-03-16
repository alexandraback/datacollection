#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

int D;
std::vector<int> ls;
std::vector<int> ans;

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	std::ofstream out(argv[1] + std::string(".out"));
	//std::istream &in = std::cin;
	//std::ostream &out = std::cout;

	int T;
	in >> T;
	for (int x = 1; x <= T; ++x)
	{
		in >> D;
		ls.resize(D);
		std::copy_n(std::istream_iterator<int>(in), D, ls.begin());
		std::sort(ls.begin(), ls.end());

		ans.clear();
		for (int m = 1; m <= ls.back(); ++m)
		{
			int t = 0;
			int n = 0;
			for (auto it = ls.begin(); it != ls.end(); ++it)
			{
				int d = (*it + m - 1) / m;
				n = std::max(n, (*it + d - 1) / d);
				t += d - 1;
			}
			ans.push_back(t + n);
		}
		std::cout << "Case #" << x << ": ";
		std::copy(ans.cbegin(), ans.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n";

		out << "Case #" << x << ": " << *std::min_element(ans.cbegin(), ans.cend()) << "\n";
	}
}