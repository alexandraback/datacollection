#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        int R, C, W, ans = 0;
        scanf("%d%d%d", &R, &C, &W);
        while(C >= W)
        {
            ans += R;
            C -= W;
        }
//        cout<<ans<<endl;
        if (C % W == 0) ans += W - 1;
        else            ans += W;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
