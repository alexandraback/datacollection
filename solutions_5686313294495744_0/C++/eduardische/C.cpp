#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <map>

const int INF = 1000*1000*1000;

using namespace std;

int main ()
{
	cout.sync_with_stdio(false);

	int T, iT;
	cin >> T;
	for (iT = 0; iT < T; iT++)
	{
		int N;
		cin >> N;
		map < string, int > dataA;
		map < string, int > dataB;

		vector< pair<int, int> > data (N);

		for (int i = 0; i < N; i++)
		{
			std::map<string,int>::iterator it;
			string sA, sB;
			cin >> sA >> sB;
			int iA, iB;
			it = dataA.find(sA);
			if (it == dataA.end())
			{
				iA = dataA.size();
				dataA[sA] = iA;
			}
			else iA = it->second;
			it = dataB.find(sB);
			if (it == dataB.end())
			{
				iB = dataB.size();
				dataB[sB] = iB;
			}
			else iB = it->second;
			data[i] = make_pair(iA, iB);
		}

		int As = dataA.size(); int Bs = dataB.size();

		int n = 2 * As + 2 * Bs + 2;
		int s = 0; int t = n-1;
		vector < vector<int> > c (n, vector<int> (n));
		
		for (int i = 0; i < As; i++)
		{
			c[s][1 + i * 2] = N;
			c[1 + i * 2][1 + i * 2 + 1] = -1;
		}
		for (int i = 0; i < Bs; i++)
		{
			c[1 + As * 2 + i * 2 + 1][t] = N;
			c[1 + As * 2 + i * 2][1 + As * 2 + i * 2 + 1] = -1;
		}

		for (int i = 0; i < N; i++)
		{
			c[1 + data[i].first * 2][1 + data[i].first * 2 + 1]++;
			c[1 + As * 2 + data[i].second * 2][1 + As * 2 + data[i].second * 2 + 1]++;
			c[1 + data[i].first * 2 + 1][1 + As * 2 + data[i].second * 2] = 1;
		}

		vector<int> e (n);
		vector<int> h (n);
		h[s] = n-1;
		vector < vector<int> > f (n, vector<int> (n));

		for (int i=0; i<n; ++i) {
			f[s][i] = c[s][i];
			f[i][s] = -f[s][i];
			e[i] = c[s][i];
		}

		vector<int> maxh (n);
		int sz = 0;
		for (;;) {
			if (!sz)
				for (int i=0; i<n; ++i)
					if (i != s && i != t && e[i] > 0) {
						if (sz && h[i] > h[maxh[0]])
							sz = 0;
						if (!sz || h[i] == h[maxh[0]])
							maxh[sz++] = i;
					}
			if (!sz)  break;
			while (sz) {
				int i = maxh[sz-1];
				bool pushed = false;
				for (int j=0; j<n && e[i]; ++j)
					if (c[i][j]-f[i][j] > 0 && h[i] == h[j]+1) {
						pushed = true;
						int addf = min (c[i][j]-f[i][j], e[i]);
						f[i][j] += addf,  f[j][i] -= addf;
						e[i] -= addf,  e[j] += addf;
						if (e[i] == 0)  --sz;
					}
				if (!pushed) {
					h[i] = INF;
					for (int j=0; j<n; ++j)
						if (c[i][j]-f[i][j] > 0 && h[j]+1 < h[i])
							h[i] = h[j]+1;
					if (h[i] > h[maxh[0]]) {
						sz = 0;
						break;
					}
				}
			}
		}

		int flow = 0;
		for (int i=0; i<n; i++)
			if (c[s][i])
				flow += f[s][i];

		printf("Case #%d: %d\n",iT+1,flow);
	}
	return 0;
}
