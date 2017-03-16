#include <cstdio>
using namespace std;

// Main
int main(void)
{
	int tc, cs, K, C, S, i;

	// Test cases
	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs++){
		printf("Case #%d:", cs);
		scanf("%d%d%d", &K, &C, &S);
		// K == S
		for(i = 1; i <= S; i++)
			printf(" %d", i);
		printf("\n");
	}

	return 0;
}
