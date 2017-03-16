//NTheo 2015

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int f(int c, int w)
{
	if (w >= (c / 2) + 1)
		return std::min(c, w + 1);
	else
		return 1 + f(c - w, w);
}
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
		std::ifstream input(inname);
		std::ofstream output(outname);
		int T;
		input >> T;
		for (int t = 0; t < T; t++)
		{
			int N, C, W;
			input >> N >> C >> W;
			int w = (N - 1)*(C / W) + f(C, W);
			output << "Case #" << (t + 1) << ": " << w << std::endl;
		}
		std::cout << "done" << std::endl;
	}
	return 0;
}