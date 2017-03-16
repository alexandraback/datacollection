#include <stdio.h>
#include <map>
using namespace std;

const int MAXN = 20 + 1;

int N, T, s[MAXN];
	map<int, int> hm;

int getSum (int S)
{
	int sum = 0;
	for (int i = 0; i < N; ++i)
		if ((S >> i) & 1)
			sum += s[i];
	return sum;
}

void Solve ()
{
	scanf ("%d", &N);
	for (int i = 0; i < N; ++i) scanf ("%d", s + i);

	hm.clear ();

	int S = (1 << N) - 1;
	int sum;
	while (S > 0)
	{
		sum = getSum (S);
		if (hm[sum] == 0)
			hm[sum] = S;
		else {
			for (int i = 0; i < N; ++i)
				if ((hm[sum] >> i) & 1) printf ("%d ", s[i]);
			printf ("\n");
			for (int i = 0; i < N; ++i)
				if ((S >> i) & 1) printf ("%d ", s[i]);
			printf ("\n");
			return;
		}
		S--;
	}
	printf ("Impossible\n");
}

int main(int argc, char *argv[])
{
	freopen ("C-small-attempt1.in", "r", stdin);
	freopen ("C-small.out", "w", stdout);

	scanf ("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		printf ("Case #%d:\n", i);
		Solve ();
	}
	
	return 0;
}
