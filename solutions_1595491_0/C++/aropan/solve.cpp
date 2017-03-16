#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

int n, s, p, m, t, k;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    int t;
    scanf("%d\n", &t);
    for (int test = 1; test <= t; test++)
    {
    	printf("Case #%d: ", test);
    	scanf("%d %d %d", &n, &s, &p);
    	int ans = 0;
    	for (int i = 0; i < n; i++)
    	{
    		int x;
    		scanf("%d", &x);
    		if ((x + 2) / 3 >= p)
    		{
    			ans++;
    		}
    		else
    		if (s && x % 3 != 1 && x && (x + 2) / 3 == p - 1)
    		{
    			s--;
    			ans++;
    		}
    	}
    	printf("%d", ans);
    	printf("\n");
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
