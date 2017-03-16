#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

bool isDiamond(vector<int>* adjacent, int n, int cur)
{
	int* cnt = new int[n];
	memset(cnt, 0, n << 2);

	stack<int> S;
	S.push(cur);

	bool any = false;

	while (!S.empty())
	{
		int c = S.top(); S.pop();

		if (++cnt[c] == 2)
		{
			any = true;
			break;
		}

		int s = size(adjacent[c]);
		for (int i = 0; i < s; i++)
		{
			S.push(adjacent[c][i]);
		}
	}

	delete[] cnt;
	return any;
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d\n", &n);
		vector<int>* adjacent = new vector<int>[n];

		for (int i = 0; i < n; i++)
		{
			int m;
			scanf("%d\n", &m);
			for (int j = 0; j < m; j++)
			{
				int c;
				scanf("%d\n", &c);
				adjacent[i].push_back(c - 1);
			}
		}

		bool any = false;
		for (int i = 0; i < n; i++)
		{
			if (isDiamond(adjacent, n, i))
			{
				any = true;
				break;
			}
		}

		printf("Case #%d: %s\n", t + 1, any ? "Yes" : "No");
		delete[] adjacent;
	}

	return 0;
}