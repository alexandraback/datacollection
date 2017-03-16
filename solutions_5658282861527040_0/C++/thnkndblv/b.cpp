using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "stdio.h"
#include "algorithm"
#include "math.h"
#include "vector"

int main()
{
	int ntc;

	scanf("%d", &ntc);
	for (int tc = 1; tc <= ntc; tc++)
	{
		int A, B, K;

		scanf("%d %d %d", &A, &B, &K);
		int ans = 0;

		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++)
				if ( (a & b) < K )
					ans++;

		printf("Case #%d: %d\n", tc, ans);
	}
	
    return 0;
}