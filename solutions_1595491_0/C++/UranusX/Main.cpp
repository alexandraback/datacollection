#include <cstdio>
#include <algorithm>

using namespace std;

int N, S, P, T[128];

int Work()
{
	scanf("%d%d%d", &N, &S, &P);
	int Ans = 0;
	for (int i = 0; i < N; i ++)
		scanf("%d", &T[i]);
	sort(T, T + N);
	for (int i = 0; i < N; i ++)
	{
		if (T[i] <= 1 || T[i] >= 29)
			Ans += (T[i] >= 3 * P - 2);
		else if (S > 0 && T[i] >= 3 * P - 4)
		{
			S --;
			Ans += (T[i] >= 3 * P - 4);
		}
		else
			Ans += (T[i] >= 3 * P - 2);
	}
	return Ans;
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %d\n", Case, Work());
	return 0;
}