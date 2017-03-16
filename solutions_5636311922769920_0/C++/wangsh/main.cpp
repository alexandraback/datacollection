#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//global constants
const int INF = 1<<29;
const double EPS = 1e-8;
typedef __int64 LL;

//local constants
const int N = 110;
LL ans[N];
LL pre[N];

int main()
{
    freopen("D-small-attempt3.in","r",stdin);
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        int K, C, S;
        scanf("%d %d %d", &K, &C, &S);
        printf("Case #%d: ", ++cas);
        if (S*C < K) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < S; ++i) {
            pre[i] = 0;
            ans[i] = (i*C) % K;
        }
        for (int i = 1; i < C; ++i) {
            for (int j = 0; j < S; ++j) {
                pre[j] = pre[j]*K + ans[j];
                ans[j] = ans[j] + 1;
                ans[j] %= K;
//                printf("pre[%d] = %I64d, ans[%d] = %I64d\n", j, pre[j], j, ans[j]);
            }
        }
        set<LL> st;
        for (int i = 0; i < S; ++i) {
            LL val = pre[i]*K + ans[i] + 1;
            if (st.count(val) > 0) continue;
            printf(" %I64d", val);
            st.insert(val);
        }
        putchar('\n');
    }

//    printf("%I64d\n", 1000000000000000000LL);
    return 0;
}
