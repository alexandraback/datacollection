#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;

int n, S;
int P;
int score[N];

int f[N + 1][N + 1];

void solve(int t)
{
	printf("Case #%d: ", t + 1);
	memset(f[n], 0, sizeof f[n]);

	for (int i = n - 1; i >= 0; i--)
	{
		for (int s = 0; s <= S; s++)
		{
			int total = score[i];
			int best = (total + 2) / 3;
			int maxi = f[i + 1][s] + (best >= P);

			if (s > 0 && total < 28 && total > 0 && total % 3 != 1)
			{
				++best;
				maxi = max(maxi, f[i + 1][s - 1] + (best >= P));
			}

			f[i][s] = maxi;
		}
	}

	printf("%d\n", f[0][S]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &n, &S, &P);
		for (int j = 0; j < n; j++) scanf("%d", score + j);
		solve(i);
	}
}