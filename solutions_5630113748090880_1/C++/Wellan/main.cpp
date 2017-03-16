#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		std::map<int, int> occurrences;
		for (int i = 0; i < 2 * N - 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int val;
				cin >> val;
				occurrences[val]++;
			}
		}

		std::vector<int> rep;
		for (auto p : occurrences)
			if (p.second % 2 != 0)
				rep.push_back(p.first);

		cout << "Case #" << t + 1 << ':';
		for (int i : rep)
			cout << ' ' << i;
		cout << endl;
	}

	return 0;
}
