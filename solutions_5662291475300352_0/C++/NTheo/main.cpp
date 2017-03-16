//NTheo 2015

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int, char**)
{
	for (;;)
	{
		std::string inname;
		std::string outname;
		std::cout << "input file?" << std::endl;
		std::cin >> inname;
		std::cout << "output file?" << std::endl;
		std::cin >> outname;
		if (outname.empty())
			outname = inname.substr(0, inname.length() - 3) +
			std::string(".out");
		std::ifstream input(inname);
		std::ofstream output(outname);
		int T;
		input >> T;
		for (int t = 0; t < T; t++)
		{
			int w;
			int N;
			long long x1, f1, x2, f2;
			input >> N;
			int trash;
			if (N == 1)
			{
				int k;
				input >> x1;
				input >> k;
				input >> f2;
				if (k == 1)
				{
					w = 0;
					output << "Case #" << (t + 1) << ": " << w << std::endl;
					break;
				}
				x2 = x1;
				f1 = f2 + 1;
			}
			else
			{
				input >> x1 >> trash >> f1 >> x2 >> trash >> f2;
				if (f1 == f2)
				{
					w = 0;
					output << "Case #" << (t + 1) << ": " << w << std::endl;
					break;
				}
				else if (f1 < f2)
				{
					std::swap(x1, x2);
					std::swap(f1, f2);
				}
			}
			double tinter = (x1 - x2 + 360ll) / double(360ll * (1 / double(f2) - 1 / double(f1)));
			double x1f = 360 * tinter / double(f1) + x1;
			double epsilon = 10000*DBL_EPSILON;
			w = x1f < (360. + epsilon) ? 1 : 0;
			output << "Case #" << (t + 1) << ": " << w << std::endl;
		}
		std::cout << "done" << std::endl;
	}
	return 0;
}