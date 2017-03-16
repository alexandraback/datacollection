#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int s[500];
int X = 0, N = 0;

bool g(int i, long double p)
{
	long double score = (long double)s[i] + p * (long double)X;
	long double left = (1.0 - p) * (long double)X;
    //printf("# %Lf %Lf\n", score, left);
	for (int j = 0; j < N; j++)
		if (j != i && (long double)s[j] < score) {
			long double dif = score - (long double)s[j];
			left -= dif;
		}
	if (left <= 0.0)
		return true;
	return false;
}

void solve(int t)
{
	scanf("%d", &N);
    X = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i]);
		X += s[i];
	}

	printf("Case #%d:", t);

	for (int i = 0; i < N; i++) {
		long double min = 0.0;
		long double max = 1.0;
		long double mid = 0;

		while (fabs(max - min) > 0.000000001) {
			mid = (min + max) / 2.0;
			if (g(i, mid))
				max = mid;
			else
				min = mid;
		}
		printf(" %Lf", mid * 100.0);
	}
	printf("\n");
}


int main()
{
	int tc = 0;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
		solve(i + 1);
}
