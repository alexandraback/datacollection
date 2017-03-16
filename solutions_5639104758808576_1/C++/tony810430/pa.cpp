#include <stdio.h>
#include <algorithm>

using namespace std;




int main()
{
    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("A-small-attempt1.out","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    int Smax;
    char c;
    int cnt;
    int res;

    scanf(" %d",&T);
    for (int cas = 1; cas <= T; cas++) {
        scanf(" %d",&Smax);
        cnt = res = 0;

        for (int i = 0; i <= Smax; i++) {
            scanf(" %c", &c);

            res += max(0, i-cnt);
            cnt += c-'0'+max(0, i-cnt);
        }

        printf("Case #%d: %d\n", cas, res);
    }

    return 0;
}
