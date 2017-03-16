#include <stdio.h>
#include <set>

using namespace std;

int T;
int A, B;

int main()
{
	int i, j;
	int tt;

	scanf("%d", &T);

	for(tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d", &A, &B);
		
		int d;
		for(d = 1; d <= A; d *= 10);
		d /= 10;

//		printf("d %d\n", d);

		int sol = 0;

		for(i = A; i <= B; ++i)
		{
			set <int> cafe;

			for(j = 10; j <= d; j *= 10)
			{
				int f = i / j;
				int b = i % j;
				int a = b * (10 * d / j) + f;

	//			printf("%d -> %d : %d %d -> %d\n", i, j, f, b, a);

				if(i < a && a <= B)
					cafe.insert(a);
			}

	//		printf("cafe %d\n", cafe.size());

			sol += cafe.size();
		}

		printf("Case #%d: %d\n", tt, sol);
	}

	return 0;
}
