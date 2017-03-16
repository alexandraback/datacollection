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

struct Pair
{
	string p1;
	string p2;
};

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		vector<Pair> strs(N);
		for (int i = 0; i < N; i++)
		{
			cin >> strs[i].p1;
			cin >> strs[i].p2;
		}

		set<string> left;
		set<string> right;
		vector<Pair>::iterator it;
		while ((it = find_if(strs.begin(), strs.end(), [&](const Pair& p)
			{
				return (left.find(p.p1) == left.end() && right.find(p.p2) == right.end());
			})) != strs.end())
		{
			left.insert(it->p1);
			right.insert(it->p2);
			strs.erase(it);
		}
		while ((it = find_if(strs.begin(), strs.end(), [&](const Pair& p)
			{
				return (left.find(p.p1) == left.end() || right.find(p.p2) == right.end());
			})) != strs.end())
		{
			left.insert(it->p1);
			right.insert(it->p2);
			strs.erase(it);
		}

		cout << "Case #" << t + 1 << ": " << strs.size() << endl;
	}

	return 0;
}
