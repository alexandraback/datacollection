#include <cstdio>
#include <set>
#include <utility>

using namespace std;

int N, M, D, D2;
char Map[32][32];
set < pair <int, int> > Dm;

int Abs(int A)
{
	return (A > 0) ? A : -A;
}

int Gcd(int A, int B)
{
	return (A == 0) ? B : Gcd(B % A, A);
}

int Update(int x, int y)
{
	int Dist = x * x + y * y;
	if (Dist > D2)
		return 0;
	int G = Gcd(Abs(x), Abs(y));
	if (G == 0)
		return 0;
	//printf("%d %d\n", x, y, Dist);
	x /= G;
	y /= G;
	if (Dm.find(make_pair(x, y)) == Dm.end())
	{
		Dm.insert(make_pair(x, y));
		return 1;
	}
	return 0;
}

int Work()
{
	scanf("%d%d%d", &N, &M, &D);
	D2 = D * D;
	for (int i = 0; i < N; i ++)
		scanf("%s", Map[i]);
	int x, y;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			if (Map[i][j] == 'X')
			{
				x = i;
				y = j;
			}
	x --;
	y --;
	int Ans = 0;
	Dm.clear();
	for (int i = -50; i < 50; i ++)
		for (int j = -50; j < 50; j ++)
		{
			Ans += Update((N - 2) * 2 * i + x - x, (M - 2) * 2 * j + y - y);
			Ans += Update((N - 2) * 2 * i - x - 1 - x, (M - 2) * 2 * j + y - y);
			Ans += Update((N - 2) * 2 * i - x - 1 - x, (M - 2) * 2 * j - y - 1 - y);
			Ans += Update((N - 2) * 2 * i + x - x, (M - 2) * 2 * j - y - 1 - y);
		}
	return Ans;
}

int main()
{
	freopen("D-small.in", "r", stdin);
	freopen("D-small.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %d\n", Case, Work());
	return 0;
}