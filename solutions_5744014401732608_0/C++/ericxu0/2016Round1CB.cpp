#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <complex>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int T, B;
ll M;
int ans[55][55];

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> B >> M;
		memset(ans, 0, sizeof(ans));

		cout << "Case #" << t << ": ";
		if ((1LL << (B - 2)) < M)
			cout << "IMPOSSIBLE\n";
		else
		{
			cout << "POSSIBLE\n";
			for (int i = B - 2; i >= 0; i--)
			{
				if ((M&(1LL << i)))
				{
					if (i != B - 2)
						ans[1][B - i - 1] = 1;
					for (int j = B - i - 1; j <= B; j++)
						for (int k = j + 1; k <= B; k++)
							ans[j][k] = 1;
				}
			}
			for (int i = 1; i <= B; i++)
			{
				for (int j = 1; j <= B; j++)
					cout << ans[i][j];
				cout << "\n";
			}
		}
	}

	return 0;
}