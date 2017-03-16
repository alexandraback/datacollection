#include <iostream>

using namespace std;

struct cl {
	int id;
	int parent[51];
	int child[51];
	int nParent;
};

struct cl c[51];
int N;
void check (int child, int cur)
{
//	cout << child << " is a children of " << cur << endl;
	c[cur].child[child]++;
	for (int i = 1; i <= N; i++) {
		if (c[cur].parent[i] > 0)
			check(child, i);
	}
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
			for (int nn = 1; nn <= 50; nn++) {
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

		for (int n = 1; n <= N; n++)
		{
			for (int i = 1; i <= N; i++)
				if (c[n].parent[i] > 0)
					check(n, i);
		}

		int result = 0;
		for (int n = 1; n <= N; n++)
		{
			for (int i = 1; i <= N; i++) {
				if (c[n].child[i] > 1) {
					result = 1;
					break;
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
