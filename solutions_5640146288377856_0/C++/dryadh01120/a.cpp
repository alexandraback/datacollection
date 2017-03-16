#include <cstdio>

int main(void)
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);

    int N, r, c, w, ans, cas = 1;

    scanf("%d", &N);
    while(N--) {
        scanf("%d %d %d", &r, &c, &w);

        ans = c/w-1;
        if( r > 1 ) ans += (r-1) * (c/w);
		if( c-w*(c/w-1) > w ) ans += w+1;
		else ans += w;

		printf( "Case #%d: %d\n", cas++, ans );
    }


    return 0;
}
