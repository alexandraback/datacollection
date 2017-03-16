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
		string S;
		cin >> S;

#if 0
		multiset<char> s(S.begin(), S.end());

		deque<char> r;
		for (char c : S)
		{
			if (c == *s.rbegin())
			{
				r.push_front(c);
			}
			else
			{
				r.push_back(c);
			}
			s.erase(s.find(c));
		}
#else
		deque<char> r;
		for (char c : S)
		{
			if (r.empty())
			{
				r.push_back(c);
				continue;
			}

			if (c >= r[0])
				r.push_front(c);
			else
				r.push_back(c);
		}
#endif

		string res(r.begin(), r.end());

		cout << "Case #" << t + 1 << ": " << res << endl;
	}

	return 0;
}
