#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("c.in");
ofstream fout("c.out");

int chain[2000];
int bff[2000];
bool visited[2000];

int find(int k, int step, int first)
{
	if (visited[k]) return -1;

	visited[k] = true;

	if (bff[k] == first)
		return step;
	if (chain[k] > -1)
	{
		if (step > chain[k]) chain[k] = step;
		return -1;
	}

	return find(bff[k], step + 1, first);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int T;
	fin >> T;

	for (int ca = 1; ca <= T; ca++)
	{
		memset(bff, 0, sizeof(bff));
		memset(chain, -1, sizeof(chain));

		int n;
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			fin >> bff[i];
			bff[i]--;
		}

		int max_circle = 0;

		for (int i = 0; i < n; i++)
			if (bff[bff[i]] == i) chain[i] = 0; 



		for (int i = 0; i < n; i++)
		{
			memset(visited, false, sizeof(visited));

			int c = find(i, 1, i);
			if (c > max_circle) max_circle = c;
		}

		int max_chain = 0;
		for (int i = 0; i < n; i++)
		{
			if (chain[i] > -1)
			{
				// chain[i] = max(chain[i], chain[bff[i]]);
				// chain[bff[i]] = -1;

				max_chain += chain[i];
			}
		}
		int ans = max(max_chain, max_circle);
		fout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}