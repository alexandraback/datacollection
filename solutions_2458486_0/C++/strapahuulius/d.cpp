#include <iostream>
#include <vector>
#include <assert.h>
#include <cstring>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
int mem[1 << 20];
bool doit(int mask, int n, VI &keys, const VI &key_open, const VVI &keys_inside)
{
	if (mem[mask] != -1)
		return mem[mask];
	bool res = false;
	for (int i=0; i<n && !res; i++)
		if (!(mask & (1 << i)) && keys[key_open[i]] > 0)
		{
			keys[key_open[i]]--;
			for (VI::const_iterator it = keys_inside[i].begin(); it != keys_inside[i].end(); ++it)
				keys[*it]++;
			res |= doit(mask | (1 << i), n, keys, key_open, keys_inside);
			keys[key_open[i]]++;
			for (VI::const_iterator it = keys_inside[i].begin(); it != keys_inside[i].end(); ++it)
				keys[*it]--;
		}
	mem[mask] = (res ? 1 : 0);
	return res;
}
VI solve(VI keys, const VI &key_open, const VVI &keys_inside)
{
	int n = key_open.size();
	memset(mem, -1, sizeof mem);
	mem[(1 << n) - 1] = 1;
	if (!doit(0, n, keys, key_open, keys_inside))
		return VI();
	VI ret;
	for (int i=0, mask=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			if (!(mask & (1 << j)) && keys[key_open[j]] > 0 && mem[mask | (1 << j)])
			{
				keys[key_open[j]]--;
				for (VI::const_iterator it = keys_inside[j].begin(); it != keys_inside[j].end(); ++it)
					keys[*it]++;
				ret.push_back(j);
				mask |= 1 << j;
				break;
			}
	}
	assert((int)ret.size() == n);
	return ret;
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
