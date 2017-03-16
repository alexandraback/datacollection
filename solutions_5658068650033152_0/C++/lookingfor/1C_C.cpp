#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int nbits(int n)
{
	int res = 0;
	while (n > 0)
	{
		n &= n-1;
		++res;
	}
	return res;
}

void setStones( vector<vector<int>>& a, int mask )
{
	int n = a.size(), m = a[0].size();
	for (int i = 0, l = 1; i < n; ++i )
	{
		for (int j = 0; j < m; ++j, l<<=1)			
			a[i][j] = (mask&l) ? 1 : 0;
	}
}

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int nEncl( vector<vector<int>>& a )
{
	int res = 0;
	int n = a.size(), m = a[0].size();
	vector<int> X, Y;	
	int x, y, x1, y1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 1)
				++res; // stone
			if (a[i][j] != 0)
				continue; // already seen
			// dfs
			a[i][j] = -1;
			X.clear();Y.clear();
			X.push_back(i);Y.push_back(j);
			bool isBoundary = false;
			for (int l = 0; l < X.size(); ++l)
			{
				x = X[l];
				y = Y[l];
				isBoundary = isBoundary || (x == 0 || x == n-1 || y == 0 || y == m-1);
				for (int k = 0; k < 4; ++k)
				{
					x1 = x + dx[k];
					y1 = y + dy[k];
					if (x1 < 0 || x1 == n || y1 < 0 || y1 == m || a[x1][y1] != 0)
						continue;
					a[x1][y1] = -1;
					X.push_back(x1);Y.push_back(y1);
				}
			}
			if (!isBoundary)
				res += X.size();
		}
	return res;
}

int solve(int N, int M, int K)
{
	vector<vector<int>> a(N, vector<int>(M));
	int P = N*M;
	int T = 1<<P, best = P;	
	for (int i = 0, ne; i < T; ++i)
	{
		if (i % 10000 == 0)
			cerr<<i<<endl;
		setStones(a, i);
		if (nEncl(a) >= K)
		{		
			best = min(best, nbits(i));
		}
	}
	return best;
}

int main()
{
	int T, N, M, K;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		cin>>N>>M>>K;
		cout<<"Case #"<<(i+1)<<": "<<solve(N, M, K)<<endl;
	}
	return 0;
}

