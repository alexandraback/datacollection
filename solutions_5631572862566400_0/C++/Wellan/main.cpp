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

int N;
vector<int> bffs;
vector<vector<int>> bffsRev;

int longestPathReverse(int end, vector<bool>& visited)
{
	const vector<int>& paths = bffsRev[end];
	int m = 0;
	visited[end] = true;
	for (int prev : paths)
	{
		if (visited[prev])
			continue;

		int l = 1 + longestPathReverse(prev, visited);
		if (l > m)
			m = l;
	}
	return m;
}
tuple<int, bool, vector<bool>> findLongestFrom(int current, vector<bool> visited)
{
	const int start = current;

	int length = 0;
	int previous = -1;
	while (true)
	{
		visited[current] = true;
		length++;

		int next = bffs[current];
		if (next == previous)
		{
			// Repart d'un enfant ayant current pour BFF
			// => Longueur de la chaîne la plus longue arrivant à current en passant par des noeuds non visités
			visited[next] = true;
			int path = longestPathReverse(current, visited);
			return make_tuple(length + path, true, visited);
		}
		else if (next == start)
		{
			// Cycle OK : revenu au début
			return make_tuple(length, false, visited);
		}
		else if (visited[next])
		{
			// Noeud déjà visité et au milieu du cercle
			return make_tuple(-1, false, visited);
		}
		else
		{
			// Noeud pas encore visité : on le suit
			previous = current;
			current = next;
		}
	}
}
int findLongest()
{
	int res = 0;
	for (int j = 0; j < N; j++)
	{
		int m = 0;
		int cycleAdd = 0;
		vector<bool> cyclesVisited(N, false);
		for (int i2 = 0; i2 < N; i2++)
		{
			int i = (i2 + j) % N;
			if (cyclesVisited[i])
				continue;

			tuple<int, bool, vector<bool>> lengthAndCycle = findLongestFrom(i, cyclesVisited);
			if (get<1>(lengthAndCycle))
			{
				cycleAdd += get<0>(lengthAndCycle);
				for (int k = 0; k < N; k++)
				{
					if (get<2>(lengthAndCycle)[k])
						cyclesVisited[k] = true;
				}
			}
			else if (get<0>(lengthAndCycle) > m)
				m = get<0>(lengthAndCycle);
		}
		res = max(res, max(m, cycleAdd));
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
		cin >> N;

		bffs.clear();
		bffs.resize(N);
		bffsRev.clear();
		bffsRev.resize(N);

		for (int k = 0; k < N; k++)
		{
			int nb;
			cin >> nb;
			nb--;

			bffs[k] = nb;
			bffsRev[nb].push_back(k);
		}

		int rep = findLongest();
		cout << "Case #" << t + 1 << ": " << rep << endl;
	}

	return 0;
}
