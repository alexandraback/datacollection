#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double EPS = 1e-9;
bool used[3000000];
int val[3000000];
void print(int pos)
{
	while (pos)
	{
		printf("%d ", val[pos]);
		pos -= val[pos];
	}
	puts("");
}
int X[500];
void solve()
{
	memset(used, false, sizeof(used));
	int N;
	scanf ("%d", &N);
	used[0] = true;
	int mx = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf ("%d", &X[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		int x = X[i];
		for (int j = mx; j >= 0; --j)
		{
			if (used[j])
			{
				if (used[j + x])
				{
					print(j + x);
					val[j+x] = x;
					print(j + x);
					return;
				}
				else
				{
					used[j + x] = true;
					val[j + x] = x;
				}
			}
		}
		mx += x;
	}
	puts("Impossible");
}
int main()
{
#ifdef _DEBUG
	freopen("Ctest.txt", "r", stdin);
	freopen("Cout.txt", "w", stdout);
#endif
	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return 0;
}