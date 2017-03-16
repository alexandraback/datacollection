#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>

using namespace std;

void init()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
}

int main()
{
	init();
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N;
		cin >> N;
		vector <vector <int> > diagrs(N);
		for (int i = 0; i < N; ++i)
		{
			int M;
			cin >> M;
			diagrs[i].resize(M);
			for (int j = 0; j < M; ++j)
			{
				int a;
				cin >> a;
				--a;
				diagrs[i][j] = a;
			}
		}
		vector <vector <int> > inh(N);
		for (int i = 0; i < N; ++i)
		{
			inh[i].resize(N);
			for (int j = 0; j < N; ++j)
			{
				inh[i][j] = 0;
			}
			for (int j = 0; j < (int) diagrs[i].size(); ++j)
			{
				inh[i][diagrs[i][j]] = 1;
			}
		}
		vector <bool> was(N, false);
		for (int k = 0; k < N + 2; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				if (!was[i])
				{
					int ok = true;
					for (int j = 0; j < (int) diagrs[i].size(); ++j)
					{
						if (!was[diagrs[i][j]])
						{
							ok = false;
						}
					}
					if (ok)
					{
						was[i] = true;
						for (int j = 0; j < (int) diagrs[i].size(); ++j)
						{
							for (int k = 0; k < N; ++k)
							{
								if (inh[diagrs[i][j]][k] == 1)
								{
									inh[i][k] = 1;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < N; ++i)
		{
			inh[i][i] = 1;
		}
		bool ans = false;
		for (int i = 0; i < N; ++i)
		{
			int sz = diagrs[i].size();
			for (int j = 0; j < sz; ++j)
			{
				for (int k = j + 1; k < sz; ++k)
				{
					for (int l = 0; l < N; ++l)
					{
						if ((inh[diagrs[i][j]][l] == 1) && (inh[diagrs[i][k]][l] == 1))
						{
							ans = true;
						}
					}
				}
			}
		}
		cout << "Case #" << t + 1<< ": ";
		if (ans)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
