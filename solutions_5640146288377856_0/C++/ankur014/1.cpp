#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    long long r, c, w, ans, dum;
	scanf("%d", &t);

    for (int kase = 1; kase <= t; ++kase) {
        scanf("%lld%lld%lld", &r, &c, &w);

        dum = c / w;

        if(c % w != 0) {
        	ans = w + dum;
        } else {
            ans = w - 1 + dum;
        }

        printf("Case #%d: %lld\n", kase, ans);
    }

    return 0;
}



