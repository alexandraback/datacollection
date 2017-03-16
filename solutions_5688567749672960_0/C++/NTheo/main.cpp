//NTheo 2015

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

inline int rev(int n)
{
	std::string s = std::to_string(n);
	std::reverse(s.begin(), s.end());
	return std::stoi(s);
}
int main(int, char**)
{
	std::vector<int> sh;
	for (int i = 0; i <= 1000000; i++)
		sh.push_back(INT_MAX);
	std::queue<int> grey;
	sh[1] = 1;
	grey.push(1);
	while (!grey.empty())
	{
		int current = grey.front();
		//std::cout << current << std::endl;
		int next = current + 1;
		if (next <= 1000000 && sh[next]==INT_MAX)
		{
			sh[next] = sh[current] + 1;
			grey.push(next);
		}
		next = rev(current);
		if (next <= 1000000 && sh[next]==INT_MAX)
		{
			sh[next] = sh[current] + 1;
			grey.push(next);
		}
		grey.pop();
	}
	//for (int i = 1; i < 1001; i++)
	//	std::cout << sh[i] << std::endl;
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
			int x;
			input >> x;
			output << "Case #" << (t + 1) << ": " << sh[x] << std::endl;
		}
		std::cout << "done" << std::endl;
	}
	return 0;
}