#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <set>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		set<double> nao, ken;
		double cv;
		int n, pl = 0;
		cin >> n;
		for (int q = 0; q < n; q++)
		{
			cin >> cv;
			nao.insert(cv);
		}
		for (int q = 0; q < n; q++)
		{
			cin >> cv;
			ken.insert(cv);
		}
		set<double>::iterator nk = ken.begin(), nnao;
		int dec = 0, war = 0;
		for (nnao = nao.begin(); nnao != nao.end(); nnao++)
		{
			if (*nnao >= *nk)
			{
				dec++;
				nk++;
			}
		}

		for (nnao = nao.begin(); nnao != nao.end(); nnao++)
		{
			if (ken.upper_bound(*nnao) == ken.end())
			{
				war++;
				ken.erase(ken.begin());
			}
			else
				ken.erase(ken.upper_bound(*nnao));
		}

		cout << dec << " " << war << endl;
	}
}