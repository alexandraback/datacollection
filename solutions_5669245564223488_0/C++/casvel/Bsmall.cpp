#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define MP make_pair
#define INF (1<<30)

using namespace std;

typedef pair <int, int> ii;

string aux[105];
vector <int> train[105];
bool used[30];
int p[15];
int N;

bool revisa()
{
	For(i, 0, N)
	{
		int a = p[i], b = i > 0 ? p[i-1] : 0;

		For(k, 0, train[a].size())
		{
			int letra = train[a][k];

			if (used[letra] == true)
			{
				if (k == 0 and train[b][train[b].size()-1] == train[a][k])
					continue;

				if (k > 0 and train[a][k-1] == train[a][k])
					continue;

				return false;
			}

			used[letra] = true;
		}
	}

	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int caso = 1;
	while (T--)
	{
		scanf("%d", &N);

		For(i, 0, N)
			cin >> aux[i];

		For(i, 0, N)
			train[i].clear();

		For(i, 0, N)
		{
			int j = 0;
			while (j < aux[i].size())
			{
				int a = aux[i][j];
				train[i].push_back(a-'a');
				while (j < aux[i].size() and aux[i][j] == a)
					j++;
			}
		}

		For(i, 0, N)
			p[i] = i;

		int res = 0;
		do{
			memset(used, 0, sizeof used);
			res += revisa();
		}while(next_permutation(p, p+N));

		printf("Case #%d: %d\n", caso++, res);

	}

	return 0;
}