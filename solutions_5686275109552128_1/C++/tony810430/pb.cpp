#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("B-small-attempt3.in", "r", stdin);
    //freopen("B-small-attempt3.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    int D;
    int res;
    vector<int> P;
    int UPPER = 1001;


    scanf(" %d",&T);

    for (int cas = 1; cas <= T; cas++) {
        scanf(" %d",&D);
        P.resize(D);
        for (int i = 0; i < D; i++) {
            scanf(" %d",&P[i]);
        }

        sort(P.begin(), P.end());
        res = UPPER;
        for (int u = UPPER; u >= 1; u--) {
            if (u >= P[D-1]){
                res = min(u, res);
            } else {
                int res_tmp = u;
                for (int i = 0; i < D; i++) {
                    res_tmp += P[i]/u;
                    if (P[i]%u == 0)res_tmp--;
                }
                res = min(res, res_tmp);
            }
        }

        printf("Case #%d: %d\n", cas, res);
    }


    return 0;
}
