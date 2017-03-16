#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

bool isPossible(vector<int> &cur, vector<vector<int> > &inside, vector<bool> &used, vector<int> &needs)
{
	vector<bool> reachable(200);
	int i, j;
	int n = used.size();
	for(i = 0; i < 200; i++)
		reachable[i] = cur[i] > 0;
	vector<bool> seen(n);

	vector<int> needed(200);
	for(i = 0; i < n; i++)
		if (!used[i])
			needed[needs[i]]++;
	vector<int> sum(200);
	for(i = 0; i < n; i++)
		if (!used[i])
			for(j = 0; j < 200; j++)
				sum[j] += inside[i][j];
	for(j = 0; j < 200; j++)
	{
		sum[j] += cur[j];
		if (sum[j] < needed[j])
			return false;
	}

	while(true)
	{
		bool ch = false;
		for(i = 0; i < n; i++)
			if (!used[i] && !seen[i] && reachable[needs[i]])
			{
				seen[i] = true;
				for(j = 0; j < 200; j++)
					if (!reachable[j] && inside[i][j] > 0)
					{
						ch = true;
						reachable[j] = true;
					}
			}
		if (!ch) break;
	}
	for(i = 0; i < used.size(); i++)
		if (!used[i] && !reachable[needs[i]])
			return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int T, i, j, k;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int n, m;
		cin >> m >> n;
		vector<int> cur(200);
		vector<vector<int> > inside(n);
		for(i = 0; i < m; i++)
		{
			cin >> j;
			cur[j - 1]++;
		}
		vector<int> needs(n);
		for(i = 0; i < n; i++)
		{
			cin >> needs[i];
			--needs[i];
			cin >> k;
			inside[i].resize(200);
			while(k--)
			{
				cin >> j;
				inside[i][j - 1]++;
			}
		}

		printf("Case #%d:", t);
		vector<bool> used(n);
		if (!isPossible(cur, inside, used, needs))
			puts(" IMPOSSIBLE");
		else
		{
			for(int it = 0; it < n; it++)
			{
				for(i = 0; i < n; i++)
				{
					if (used[i] || cur[needs[i]] == 0) continue;
					cur[needs[i]]--;
					for(j = 0; j < 200; j++)
						cur[j] += inside[i][j];
					used[i] = true;
					if (isPossible(cur, inside, used, needs)) break;
					cur[needs[i]]++;
					for(j = 0; j < 200; j++)
						cur[j] -= inside[i][j];
					used[i] = false;
				}
				if (i == n) throw 1;
				cout << " " << i + 1;
			}
			cout << endl;
		}
	}

	return 0;
}