#include <cstdio>
#include <cstring>
using namespace std;

int table[2000009];

int main()
{
    int T;
    scanf("%d", &T);
    for(int testnum = 1; testnum <= T; testnum++)
    {
	memset(table, 0, sizeof(table));
        printf("Case #%d: ", testnum);

        int A, B;
	scanf("%d%d", &A, &B);

	int r = 1;
	while(r <= A)
	    r *= 10;
        r /= 10;

	int ans = 0;
	for(int k = A; k <= B; k++)
	{
	    int x = k, y = 0;
	    for(int b1 = 1, b2 = r; x; b1 *= 10, b2 /= 10)
	    {
		y += x % 10 * b1;
		x /= 10;
		int v = x + y * b2;
		if(A <= v && v < k && table[v] != k)
		{
		    ans++;
		    table[v] = k;
		}
	    }
	}

	printf("%d\n", ans);
    }
    return 0;
}
