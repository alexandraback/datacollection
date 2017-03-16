//Theophile Dalens (NTheo) 2015

#include <algorithm>
#include <fstream>
#include <vector>

//how many times do i have to pause to transform a plate with x pancakes
//into plates with at most h pancakes?
class F
{
	int pmax;
	std::vector<int> values;
public:
	F(int p) : pmax(p)
	{
		for (int x = 1; x <= pmax; x++)
		{
			for (int h = 1; h <= pmax; h++)
			{
				//setting value for values[(x-1)*pmax + (h-1)]
				values.push_back((x + h - 1) / h - 1);
			}
		}
	}
	inline int operator()(int x, int h) const
	{
		return values[(x - 1)*pmax + (h - 1)];
	}
};

int main(int, char**)
{
	int PiMax = 1000;
	F f(PiMax);
	std::ifstream input("B-large.in");
	std::ofstream output("B-large.out");
	int T;
	input >> T;
	for (int t = 0; t < T; t++)
	{
		int D;
		input >> D;
		std::vector<int> plates;
		plates.reserve(D);
		for (int d = 0; d < D; d++)
		{
			int pi;
			input >> pi;
			plates.push_back(pi);
		}
		//hSol[h] = score for split to h pancakes per plate max
		std::vector<int> hSol;
		hSol.reserve(PiMax);
		for (int h = 0; h < PiMax; h++)
		{
			hSol.push_back(h + 1);
			for (int d = 0; d < D; d++)
			{
				hSol.back() += f(plates[d], h + 1);
			}
		}
		int w = *std::min_element(hSol.begin(), hSol.end());
		output << "Case #" << (t + 1) << ": " << w << std::endl;
	}
	return 0;
}