#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair

using namespace std;

typedef long long ll;

const int INF = 0x60000000;
const int MINF = -1000000000;
const ll mod = 1000000007;
const int cons = 50000001;
const double pi = 3.141592653589793;

int jp[11][11], ps[11][11], js[11][11];

vector < pair < pair <int, int>, int> > Set;

int bincnt(int n)
{
	int ret = 0;

	while (n)
	{
		if (n & 1)ret++;

		n >>= 1;
	}

	return ret;
}

bool isPossible(int n, int k)
{
	memset(jp, 0, sizeof(jp));
	memset(ps, 0, sizeof(ps));
	memset(js, 0, sizeof(js));

	for (int i = 0; n; i++)
	{
		if (n & 1)
		{
			jp[Set[i].A.A][Set[i].A.B]++;
			ps[Set[i].A.B][Set[i].B]++;
			js[Set[i].A.A][Set[i].B]++;
		}
		n >>= 1;
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (jp[i][j] > k || ps[i][j] > k || js[i][j] > k)return false;
		}
	}

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testCases;
	scanf("%d", &testCases);

	for (int testNum = 1; testNum <= testCases; testNum++)
	{
		printf("Case #%d: ", testNum);
		
		int j, p, s, k;
		scanf("%d%d%d%d", &j, &p, &s, &k);

		Set.clear();
		
		for (int i = 1; i <= j; i++)
		{
			for (int q = 1; q <= p; q++)
			{
				for (int r = 1; r <= s; r++)
				{
					Set.push_back(MP(MP(i, q), r));
				}
			}
		}

		int lim = 1 << Set.size();

		vector < pair <pair <int, int>, int> > ans;

		for (int i = 0; i < lim; i++)
		{
			int cnt = bincnt(i);
			if (cnt <= ans.size())continue;

			if (isPossible(i, k))
			{
				int tmp = i;
				ans.clear();

				for (int j = 0; tmp; j++)
				{
					if (tmp & 1)
					{
						ans.push_back(Set[j]);
					}
					tmp >>= 1;
				}
			}
		}

		printf("%d\n", ans.size());

		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d %d %d\n", ans[i].A.A, ans[i].A.B, ans[i].B);
		}
	}

	return 0;
}