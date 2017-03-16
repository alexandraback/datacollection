#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int depth;
int rret;
int aa[11], cc[11];

void backtr2(int k, const vector<int>& a)
{
	if (rret == depth)
		return;

	if (k == depth)
	{
		bool isok = true;
		for (int i = 0; i < k; ++i)
		{
			if (aa[(i + 1) % k] == a[aa[i]] || aa[(i + k - 1) % k] == a[aa[i]]); else isok = false;
		}
		if (isok)
		{
			rret = max(rret, k);
		}
		return;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		if (cc[i] == 0)
		{
			cc[i] = 1;
			aa[k] = i;
			backtr2(k + 1, a);
			cc[i] = 0;
		}
	}
}

int backtr(const vector<int>& a)
{
	rret = 0;
	for (depth = 2; depth <= a.size(); ++depth)
	{
		backtr2(0, a);
	}
	return rret;
}

int main()
{
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		int N;
		cin >> N;
		vector<int> a(N);
		vector<int> in_degree(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> a[i];
			a[i]--;
			in_degree[a[i]]++;
		}

		vector<pair<int, int>> in_cycle(N);

		// cycle check
		int ret = 0;
		for (int i = 0; i < N; ++i)
		{
			vector<int> c(N);
			int cur = i, dpt = 0;
			while (true)
			{
				if (c[cur] == 1)
				{
					if (cur != i) break; // this is not a cycle

					int cur2 = cur;
					for (int j = 0; j < dpt; ++j)
					{
						in_cycle[cur2] = make_pair(1, dpt);
						cur2 = a[cur2];
					}
					ret = max(ret, dpt);
					break;
				}
				c[cur] = 1;
				dpt++;
				cur = a[cur];
			}
		}

		// chain
		vector<vector<int>> chains(N);
		for (int i = 0; i < N; ++i)
		{
			if (in_degree[i] == 0)
			{
				int len = 0;
				int cur = i;
				while (true)
				{
					if (in_cycle[cur].first == 1)
					{
						chains[cur].push_back(len);
						break;
					}

					len++;
					cur = a[cur];
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			sort(chains[i].rbegin(), chains[i].rend());
		}

		int cycle2 = 0;
		for (int i = 0; i < N; ++i)
		{
			if (in_cycle[i].first == 1)
			{
				// cycle 
				if (in_cycle[i].second == 2) // except length 2
				{
					// ------------> i - a[i] <--------
					int cur = 2;
					if (chains[i].size() > 0) cur += chains[i][0];
					if (chains[a[i]].size() > 0) cur += chains[a[i]][0];

					cycle2 += cur;
					in_cycle[a[i]].second = 0; // already processed
				}
			}
			/*
			else
			{
				if (chains[i].size() >= 2)
				{
					ret = max(ret, chains[i][0] + 1 + chains[i][1]);
				}
				else if (chains[i].size() == 1)
				{
					ret = max(ret, chains[i][0] + 1);
				}
			}
			*/
		}
		ret = max(ret, cycle2);

		printf("Case #%d: %d\n", cn, ret);
	}
}