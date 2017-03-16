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

size_t n;
vector<int> data;
int max_cycle;
set<pair<int, int>> pairs;
set<int> s2;
set<int> s;
map<int, int> m;

int dfs(int x)
{
	vector<int> visited(n);
	++visited[x];

	int next = data[x];

	while (!visited[next])
	{
		++visited[next];
		next = data[next];
	}

	int last = next, count = 1;

	next = data[last];

	while (next != last)
	{
		++count;
		next = data[next];
	}

	if (count > 2)
	{
		max_cycle = max(max_cycle, count);
		s.insert(last);
	}
	else
	{
		pairs.insert(make_pair(min(next, data[next]), max(next, data[next])));
		s2.insert(next);
		s2.insert(data[next]);
		m[next] = 0;
		m[data[next]] = 0;
	}

	return count;
}

int dfs2(int x)
{
	int count = 0;
	while (true)
	{
		if (s.find(x) != s.end())
			break;

		if (s2.find(x) != s2.end())
		{
			m[x] = max(m[x], count);
			break;
		}

		x = data[x];
		++count;
	}

	return count;
}

int main()
{
	std::ifstream input ("C:/Users/user/Desktop/input.txt" , std::ios::in);
	std::ofstream output("C:/Users/user/Desktop/output.txt", std::ios::out);

	size_t test_cases;

	input >> test_cases;

	for (size_t tc = 1; tc <= test_cases; ++tc)
	{
		int answer = 0;

		max_cycle = 0;

		input >> n;

		data.clear();
		data.resize(n);

		s.clear();
		s2.clear();
		m.clear();
		pairs.clear();

		for (size_t i = 0; i < n; ++i)
		{
			input >> data[i];
			--data[i];
		}


		for (size_t i = 0; i < n; ++i)
		{
			dfs(i);
		}

		for (size_t i = 0; i < n; ++i)
		{
			dfs2(i);
		}

		int tmp = 0;

		for (auto p : pairs)
		{
			//cout << p.first << " " << p.second << " " << m[p.first] << " " << m[p.second] << endl;;
			int k = m[p.first] + m[p.second] + 2;
			tmp += k;
		}

		max_cycle = max(max_cycle, tmp);

		output << "Case #" << tc << ": " << max_cycle << endl;
	}

	input.close();
	output.close();
	
	return 0;
}