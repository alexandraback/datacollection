#include <iostream>

using namespace std;

struct cl {
	int id;
	int parent[1001];
	int child[1001];
	int nParent;
};

struct cl c[1001];
int N;
int check (int child, int cur)
{
//	cout << child << " is a children of " << cur << endl;
	c[cur].child[child]++;
	if (c[cur].child[child] > 1)
		return 1;
	for (int i = 1; i <= N; i++) {
		if (c[cur].parent[i] > 0)
			if (check(child, i) == 1)
				return 1;
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int n = 1; n <= N; n++)
		{
			int M;
			cin >> M;
			c[n].id = n;
			c[n].nParent = M;
			for (int nn = 1; nn <= 1000; nn++) {
				c[n].parent[nn] = 0;
				c[n].child[nn] = 0;
			}
			for (int m = 0; m < M; m++)
			{
				int p;
				cin >> p;

				//cout << p << " is a parent of " << n << endl;
				c[n].parent[p]++;
			}
		}

		int result = 0;
		for (int n = 1; n <= N; n++)
		{
			for (int i = 1; i <= N; i++) {
				if (c[n].parent[i] > 0) {
					if (check(n, i) == 1) {
						result = 1;
						break;
					}
				}
			}
			if (result == 1)
				break;
		}


		if (result == 1)
			cout << "Case #" << t << ": Yes" << endl;
		else
			cout << "Case #" << t << ": No" << endl;

	}
	return 0;
}
