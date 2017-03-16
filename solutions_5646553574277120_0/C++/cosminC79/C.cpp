#include <cstdio>
#define NMAX 105
#define ll long long
int tests, c, d, v, A[NMAX];

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	
	scanf("%d", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		printf("Case #%d: ", test_no);
		scanf("%d%d%d", &c, &d, &v);
		
		for (int i = 1; i <= d; i++)
			scanf("%d", &A[i]);
		
		ll so_far = 0;
		int last_pos = 0, res = 0;
		while (so_far < v)
		{
			while (so_far < v && last_pos + 1 <= d && A[last_pos + 1] <= so_far + 1)
			{
				last_pos++;
				so_far += (ll)A[last_pos] * c;
			}
			
			if (so_far < v)
			{
				so_far += (ll)(so_far + 1) * c;
				res++;
			}
		}
		
		printf("%d\n", res);
	}
	return 0;
}

