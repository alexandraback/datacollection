#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

const int N = 55;

int b[N][N];
int d[N][N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	for (int k = 0; k < t; ++k)
	{
		int m, r, c;

		cin >> r >> c >> m;

		if (m >= r*c)
		{
			printf("Case #%i: \nImpossible\n", k + 1);
			continue;
		}
		
		if (m == r*c-1)
		{
			printf("Case #%i: \n", k + 1);
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
					printf("%c", (i+j==0)?'c':'*');
				printf("\n");
			}
			continue;
		}

		vector<int> a;
		for (int i = 0; i < m; ++i)
			a.push_back(0);
		while (a.size() < r*c)
			a.push_back(1);

		bool f = false;

		do
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					b[i][j] = a[i * c + j];
					d[i][j] = 0;
				}
			}
			for (int i1 = 0; i1 < r; ++i1)
			{
				for (int j1 = 0; j1 < c; ++j1)
				{
					if (b[i1][j1] == 1)
					{
						for (int i = -1; i < 2; ++i)
							for (int j = -1; j < 2; ++j)
							if (i1 + i >= 0 && i1 + i < r && j1 + j >= 0 && j1 + j < c && b[i1 + i][j1 + j] == 0)
							{
								b[i1][j1] = 2;
							}
					}
					
				}
			}
			int x=-1, y=-1;
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if (b[i][j] == 1)
						x = i, y = j;
				}
			}

			if (x == -1)
			{
				//next_permutation(a.begin(), a.end());
				continue;
			}

			queue<pair<int, int>> q;
			q.push(make_pair(x, y));
			b[x][y] = 1;
			d[x][y] = 1;
			while (!q.empty())
			{
				auto p = q.front();
				q.pop();
				if (b[p.first][p.second] == 1)
				{
					for (int i = -1; i < 2; ++i)
					{
						for (int j = -1; j < 2; ++j)
						{
							if (p.first + i >= 0 && p.first + i < r && p.second + j >= 0 && p.second + j < c && d[p.first + i][p.second + j] != 1)
							{
								d[p.first + i][p.second + j] = 1;
								q.push(make_pair(p.first + i, p.second + j));
							}
						}
					}
				}
			}

			f = true;
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if (b[i][j] != 0 && d[i][j] != 1)
						f = false;
				}
			}
			
			if (f)
			{
				b[x][y] = 5;
				printf("Case #%i: \n", k + 1);
				for (int i = 0; i < r; ++i)
				{
					for (int j = 0; j < c; ++j)
					{
						if (b[i][j] == 5)
							printf("c");
						if (b[i][j] == 1)
							printf(".");
						if (b[i][j] == 2)
							printf(".");
						if (b[i][j] == 0)
							printf("*");
					}
					printf("\n");
				}
			}
		} while (!f && next_permutation(a.begin(), a.end()));

		if (!f)
		{
			printf("Case #%i: \nImpossible\n", k + 1);
		}
	}


	return 0;
}
