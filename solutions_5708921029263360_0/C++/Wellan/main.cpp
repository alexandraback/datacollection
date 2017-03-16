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

struct Outfit
{
	int j, p, s;

	Outfit(int j, int p, int s) : j(j), p(p), s(s)
	{ }
};

vector<Outfit> bruteforce(int J, int P, int S, int K)
{
	vector<Outfit> res;
	vector<vector<vector<bool>>> jps(J, vector<vector<bool>>(P, vector<bool>(S, 0)));
	vector<vector<int>> jp(J, vector<int>(P, 0));
	vector<vector<int>> ps(P, vector<int>(S, 0));
	vector<vector<int>> js(J, vector<int>(S, 0));

	for (int j = 0; j < J; j++)
	{
		for (int p = 0; p < P; p++)
		{
			if (jp[j][p] >= K)
				continue;
			for (int s = 0; s < S; s++)
			{
				if (!jps[j][p][s] && ps[p][s] < K && js[j][s] < K)
				{
					res.push_back(Outfit(j + 1, p + 1, s + 1));
					jps[j][p][s] = true;
					jp[j][p]++;
					ps[p][s]++;
					js[j][s]++;
				}
				if (jp[j][p] >= K)
					break;
			}
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int J, P, S, K;
		cin >> J >> P >> S >> K;

		vector<Outfit> res = bruteforce(J, P, S, K);
		cout << "Case #" << t + 1 << ": " << res.size() << endl;
		for (const Outfit& outfit : res)
		{
			cout << outfit.j << ' ' << outfit.p << ' ' << outfit.s << endl;
		}
	}

	return 0;
}
