#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

bool HasBit(int mask, int pos)
{
	return (mask & (1 << pos)) > 0;
}

int main(int argc, char * argv[])
{

	freopen("in.txt", "r", stdin);
	int n;
	int testCount;
	std::cin >> testCount;
	std::vector<int> num;
	std::vector<std::pair<int, int> > subset;
	for(int test = 1; test <= testCount; test++)
	{
		std::cin >> n;
		num.assign(n, 0);
		for(int i = 0; i < n; i++)
		{
			std::cin >> num[i];
		}

		subset.clear();
		for(int i = 0; i < (1 << n); i++)
		{
			int nowSum = 0;
			for(int j = 0; j < n; j++)
			{
				if(HasBit(i, j))
				{
					nowSum += num[j];
				}
			}

			subset.push_back(std::make_pair(nowSum, i));
		}

		std::cout << "Case #" << test << ": ";
		std::sort(subset.begin(), subset.end());
		bool found = false;
		for(size_t i = 1; i < subset.size() - 1; i++)
		{
			if(subset[i + 1].first == subset[i].first)
			{
				found = true;
				std::cout << std::endl;
				for(int j = 0; j < n; j++)
				{
					if(HasBit(subset[i].second, j) && !HasBit(subset[i + 1].second, j))
					{
						std::cout << num[j] << ' ';
					}
				}

				std::cout << std::endl;
				for(int j = 0; j < n; j++)
				{
					if(!HasBit(subset[i].second, j) && HasBit(subset[i + 1].second, j))
					{
						std::cout << num[j] << ' ';
					}
				}
				std::cout << std::endl;

				break;
			}
		}

		if(!found)
		{
			std::cout << "Impossible" << std::endl;
		}
	}

	return 0;
}