#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++)
	{
		cout << "Case #" << c << ": ";
		int N, M;
		cin >> N >> M;
		vector <vector <int> > a(N,vector<int>(M));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> a[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				int m = a[i][j];
				for (int k = 0; k < N; k++)
					if (k != i)
						m = max(m,a[k][j]);
				if ( m <= a[i][j])	continue;
				m = a[i][j];
				for (int k = 0; k < M; k++)
					if (k != j)
						m = max(m,a[i][k]);
				if ( m <= a[i][j])	continue;
				cout << "NO" << endl;
				goto next;
			}
		cout << "YES" << endl;
		next:;
	}
	return 0;
}
