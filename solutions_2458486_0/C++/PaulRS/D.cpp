#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int vis[1 << 20];
int req[20];
vector<vector<int> > keys;
int M, K, N;

bool solve(vector <int> c, int s)
{
	if ( __builtin_popcount(s) == N)	return true;
	for (int i = 0; i < N; i++)
		if ( vis[s|(1<<i)] == -1 && c[req[i]] > 0 )
		{
			vis[s|(1<<i)] = i + 1;
			vector <int> aux = c;
			c[req[i]]--;
			for (int j = 0; j < keys[i].size(); j++)
				c[keys[i][j]]++;
			if (solve(c,s|(1<<i)))	return true;
			c = aux;
		}
	return false;
}

int main(void)
{
	int T;
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cout << "Case #" << C << ": ";
		M = 0;
		cin >> K >> N;	
		memset(vis,-1,sizeof(vis));
		vector <int> v;
		for (int i = 0; i < K; i++)
		{
			int t;
			cin >> t;
			v.push_back(t);
			M = max(M,t);
		}
		keys = vector<vector<int> > (N,vector<int>());
		for (int i = 0; i < N; i++)
		{
			int t, k;
			cin >> t >> k;
			req[i] = t;
			M = max(M,t);
			for (int j = 0; j < k; j++)
			{
				cin >> t;
				M = max(M,t);
				keys[i].push_back(t);
			}
		}
		vector <int> c(M+1);
		for (int i = 0; i < v.size(); i++)
			c[v[i]]++;
		if (!solve(c,0))
			cout << "IMPOSSIBLE" << endl;
		else
		{
			int s = (1 << N) - 1;
			stack <int> out;
			while (vis[s] > 0)
				out.push(vis[s]), s ^= 1 << (vis[s] - 1);
			while (out.size() > 1)
				cout << out.top() << " ", out.pop();
			cout << out.top() << endl;
			out.pop();
		}
	}
	return 0;
}
