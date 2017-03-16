#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 10;

int n;
std::vector<char> visit;
std::vector<int> adj[MAXN];

bool Check(int u)
{
	std::deque<int> q;
	q.push_back(u);
	visit.assign(n, 0);
	while(q.size() > 0)
	{
		u = q.front();
		q.pop_front();
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i];
			if(visit[v] == 1)
			{
				return true;
			}

			visit[v] = 1;
			q.push_back(v);
		}
	}

	return false;
}

int main(int argc, char * argv[])
{
	int v;
	int degree;
	int testCount;
	freopen("in.txt", "r", stdin);
	std::cin >> testCount;
	for(int test = 1; test <= testCount; test++)
	{
		std::cin >> n;
		for(int i = 0; i < MAXN; i++)
		{
			adj[i].clear();
		}

		for(int u = 0; u < n; u++)
		{
			std::cin >> degree;
			for(int j = 0; j < degree; j++)
			{
				std::cin >> v;
				adj[v - 1].push_back(u);
			}
		}

		bool found = false;
		for(int u = 0; u < n; u++)
		{
			if(Check(u))
			{
				found = true;
				break;
			}
		}

		std::cout << "Case #" << test << ": ";
		if(found)
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}

	return 0;
}