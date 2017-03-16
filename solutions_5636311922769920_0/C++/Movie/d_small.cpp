#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main (void)
{
	int T;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int K, C, S;

		scanf ("%d %d %d", &K, &C, &S);

		printf ("Case #%d:", t);

		for (int i = 1; i <= S; i++)
			printf (" %d", i);
		printf ("\n");
	}
}