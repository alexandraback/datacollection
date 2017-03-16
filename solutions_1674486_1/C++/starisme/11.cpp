#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
using namespace std;


int cmp(const void* x, const void* y)
{
	if (*((int*)x) > *((int*)y))
		return 1;
	return -1;
}




int main()
{
	ifstream inf("1.in", ios::in);
	ofstream outf("1.out", ios::out);

	int t;
	inf >> t;
	int i, j, k;
	int n;
	for (i = 1; i <= t;i++)
	{
		inf >> n;
		int e[1010][11] = {0};
		int InDegree[1010] = {0};
		int OutDegree[1010] = {0};
		int m;

		int visit[1010] = {0};
		queue<int> q;

		for (j = 1;j <= n;j++)
		{
			inf >> m; 
			OutDegree[j] = m;
			for (k = 1;k <= m;k++)
			{
				inf >> e[j][k];
				InDegree[e[j][k]] ++;
			}
		}

		for (j = 1;j <= n;j++)
		{
			if (InDegree[j] == 0)
				q.push(j);
		}

		int flag = 0;

		while (! q.empty())
		{
			int v = q.front();
			q.pop();
			for (j = 1;j <= OutDegree[v];j++)
			{
				if (visit[e[v][j]] == 1)
				{
					flag = 1;
					break;
				}
				else
				{
					InDegree[e[v][j]] --;
					visit[e[v][j]] = 1;

					if (InDegree[e[v][j]] == 0)
						q.push(e[v][j]);
				}
			}
			if (flag)
				break;
		}

		if (flag)
			outf << "Case #" << i <<": Yes" << endl;
		else
			outf << "Case #" << i <<": No" << endl;
		
	}
	return 0;
}