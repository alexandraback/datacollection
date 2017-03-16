#include <algorithm>
#include <assert.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<unsigned> vout;
vector<unsigned> vincnt;
vector<vector<int>> vinv;

int MaxL(int from, int block)
{
	vector<int> vd(vinv.size(), -1);
	vd[from] = 0;
	int maxd = 0;
	queue<int> q;
	q.push(from);
	while (!q.empty())
	{
		int i = q.front(); q.pop();
		for (int j = 0; j < vinv[i].size(); ++j)
		{
			int k = vinv[i][j];
			if ((vd[k] == -1) && (k != block))
			{
				vd[k] = vd[i] + 1;
				maxd = max(maxd, vd[k]);
				q.push(k);
			}
		}
	}
	return maxd;
}

int main()
{
	int T;
	cin >> T;
	for (int it = 0; it < T; ++it)
	{
		int N;
		cin >> N;
		vout.resize(N);
		vincnt.resize(0); 
		vincnt.resize(N, 0);
		vinv.resize(0);
		vinv.resize(N);
		for (int i = 0; i < N; ++i)
		{
			int k;
			cin >> k;
			k -= 1;
			vout[i] = k;
			vincnt[k]++;
			vinv[k].push_back(i);
		}

		// Check loops first
		int max_loop = 0;
		queue<int> q;
		for (int i = 0; i < N; ++i)
		{
			if (vincnt[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int i = q.front(); q.pop();
			if ((--vincnt[vout[i]]) == 0)
			{
				q.push(vout[i]);
			}
		}
		for (int i = 0; i < N; ++i)
		{
			if (vincnt[i] > 0)
			{
				assert(vincnt[i] == 1);
				vincnt[i] = 0;
				int l = 1;
				for (int j = vout[i]; j != i; j = vout[j])
				{
					assert(vincnt[j] == 1);
					vincnt[j] = 0;
					++l;
				}
				max_loop = max(max_loop, l);
			}
		}
		assert(max_loop > 0);

		int stwins = 0;
		for (int i = 0; i < N; ++i)
		{
			if ((vout[i] > i) && (vout[vout[i]] == i))
			{
				stwins += 2;
				stwins += MaxL(i, vout[i]);
				stwins += MaxL(vout[i], i);
			}
		}
		cout << “Case #" << it+1 << ": " << max(max_loop, stwins) << endl;
	}
}