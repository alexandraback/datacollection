#include <iostream>
#include <fstream>

#define cin in
#define cout out

using namespace std;

struct triple
{
	int a, b, c;
};

ifstream in("in.txt");
ofstream out("out.txt");

int main()
{
	int T, a, b, c, k;

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		cin >> a >> b >> c >> k;

		triple d[1000];
		int ans = 0;
		int ab[10][10] = {0}, bc[10][10] = {0}, ca[10][10] = {0};

		for (int i = 1; i <= a; ++i)
			for (int j = 1; j <= b; ++j)
				for (int l = 1; l <= c; ++l)
				{
					if (ab[i][j] >= k or bc[j][l] >= k or ca[l][i] >= k)
						continue;

					ab[i][j]++;
					bc[j][l]++;
					ca[l][i]++;

					d[ans++] = {i, j, l};
				}
				
		cout << ans << '\n';

		for (int i = 0; i < ans; ++i)
		{
			cout << d[i].a << ' ' << d[i].b << ' ' << d[i].c << '\n';
		}

	}
}