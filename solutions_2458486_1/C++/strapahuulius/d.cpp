#include <iostream>
#include <vector>
#include <assert.h>
#include <cstring>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
bool update(int key_open, const VI &keys_inside, VI &keys)
{
	if (--keys[key_open] < 0)
		return false;
	for (VI::const_iterator it = keys_inside.begin(); it != keys_inside.end(); ++it)
		keys[*it]++;
	return true;
}
int a[202][202];
bool check(const VI &used, VI keys, const VI &key_open, const VVI &keys_inside)
{
	int n = keys_inside.size();
	int m = n - used.size();
	for (VI::const_iterator it = used.begin(); it != used.end(); ++it)
		if (!update(key_open[*it], keys_inside[*it], keys))
			return false;
	memset(a, 0, sizeof a);
	VI visited(n + 1), key_seen(200);
	for (VI::const_iterator it = used.begin(); it != used.end(); ++it)
		visited[*it] = 1;
	for (int i=0; i<n; i++)
		if (!visited[i])
			for (VI::const_iterator it = keys_inside[i].begin(); it != keys_inside[i].end(); ++it)
				a[*it][i]++;
	assert(keys.size() == 200);
	for (int i=0; i<200; i++)
	{
		a[i][n] = keys[i];
	}
	queue<int> q;
	q.push(n);
	int n_visited = 0;
	while (!q.empty())
	{
		int act = q.front();
		q.pop();
		for (int i=0; i<200; i++)
			if (a[i][act] && !key_seen[i])
			{
				key_seen[i] = 1;
				for (int j=0; j<n; j++)
					if (!visited[j] && key_open[j] == i)
					{
						visited[j] = 1;
						n_visited++;
						q.push(j);
					}
			}
	}
	if (n_visited != m)
	{
		return false;
	}
	visited.assign(n + 1, 0);
	for (VI::const_iterator it = used.begin(); it != used.end(); ++it)
		visited[*it] = 1;
	for (int i=0; i<n; i++)
	{
		if (visited[i])
			continue;
		int k = -1;
		int k_o = key_open[i];
		for (int j=0; j<=n; j++)
			if (a[k_o][j] > 0)
			{
				k = j;
				break;
			}
		if (k == -1)
		{
			return false;
		}
		a[k_o][k]--;
	}
	return true;
}
VI solve(VI keys, const VI &key_open, const VVI &keys_inside)
{
	int n = key_open.size();
	bool tmp_res = check(VI(), keys, key_open, keys_inside);
	if (!tmp_res)
		return VI();
	VI tmp_ret;
	VI used(n, 0);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			if (!used[j])
			{
				tmp_ret.push_back(j);
				used[j] = 1;
				if (check(tmp_ret, keys, key_open, keys_inside))
				{
					break;
				}
				used[j] = 0;
				tmp_ret.pop_back();
			}
		assert(!tmp_ret.empty());
	}
	return tmp_ret;
}
int main()
{
	int n_case;
	cin >> n_case;
	for (int tc=0; tc<n_case; tc++)
	{
		int k, n;
		cin >> k >> n;
		VI keys(200, 0);
		for (int i=0; i<k; i++)
		{
			int x;
			cin >> x;
			x--;
			assert(x >= 0 && x < 200);
			keys[x]++;
		}
		vector<VI> keys_inside(n);
		VI key_open(n);
		for (int i=0; i<n; i++)
		{
			cin >> key_open[i];
			key_open[i]--;
			int k_i;
			cin >> k_i;
			for (int j=0; j<k_i; j++)
			{
				int x;
				cin >> x;
				x--;
				assert(x >= 0 && x < 200);
				keys_inside[i].push_back(x);
			}
		}
		VI solution = solve(keys, key_open, keys_inside);
		cout << "Case #" << tc + 1 << ":";
		if (solution.empty())
			cout << " IMPOSSIBLE" << endl;
		else
		{
			for (VI::iterator it = solution.begin(); it != solution.end(); ++it)
				cout << " " << *it + 1;
			cout << endl;
		}
	}
	return 0;
}
