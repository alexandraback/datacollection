# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <map>
# include <queue>
# include <iostream>
# include <math.h>

using namespace std;

# define testin freopen("A-small-attempt4.in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
typedef long long int lli;

int R, C, W;

int main()
{
    testin;
    testout;

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        printf("Case #%d: ", ica);
        scanf("%d%d%d", &R, &C, &W);
        int ans = 0;

        if (W == 1) ans = R*C;
        else {
            ans = C/(W-1)-1+W;
        }
        printf("%d\n", ans);
    }

    return 0;
}
