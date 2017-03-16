#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

int main()
{
	std::ifstream input ("C:/Users/user/Desktop/input.txt" , std::ios::in);
	std::ofstream output("C:/Users/user/Desktop/output.txt", std::ios::out);

	size_t test_cases;

	input >> test_cases;

	for (size_t tc = 1; tc <= test_cases; ++tc)
	{
		size_t n;

		input >> n;

		vector<int> answer;
		answer.reserve(n);

		vector<int> mask(100500);

		vector<vector<int>> data(2 * n - 1, vector<int>(n));

		for (size_t i = 0; i < 2 * n - 1; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				input >> data[i][j];
				++mask[data[i][j]];
			}
		}

		for (size_t i = 0; i < 100500; ++i)
			if (mask[i] & 1)
				answer.push_back(i);

		output << "Case #" << tc << ": ";

		for (size_t i = 0; i < n; ++i)
			output << answer[i] << " ";

		output << endl;
	}

	input.close();
	output.close();
	
	return 0;
}