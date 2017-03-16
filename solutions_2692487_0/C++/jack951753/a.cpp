#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100;
int dat[maxn];
void doit()
{
    long long size;
    int n;
    scanf("%lld %d", &size, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", dat + i);
    sort(dat, dat + n);

    if(size < 2)
    {
    	printf("%d\n", n);
    	return;
    }

    int ans = n, t = 0;
    for (int i = 0; i < n; ++i)
    {
    	// printf("%lld %d d ", size, dat[i]);
    	while(size <= dat[i])
    		size += size - 1, t++;
    	size += dat[i];
    	ans = min(ans, t+n-i-1);
    	// printf("%d\n", t+(n-i-1));
    }
    printf("%d\n", ans);
}
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        printf("Case #%d: ", i), doit();
    return 0;
}
