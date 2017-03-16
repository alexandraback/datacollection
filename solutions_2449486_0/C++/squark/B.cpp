#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

int h[104][104];
int rh[104], ch[104];

int main()
{
    #ifdef __FIO
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        printf("Case #%d: ", i0);
        int n, m;
        int i, j;
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++){
                scanf("%d", &h[i][j]);
                h[i][j] = -h[i][j];
            }
        for(i = 0; i < n; i++)
            rh[i] = 100;
        for(j = 0; j < m; j++)
            ch[j] = 100;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++){
                rh[i] = min(rh[i], h[i][j]);
                ch[j] = min(ch[j], h[i][j]);
            }
        bool check = true;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(h[i][j] != rh[i] && h[i][j] != ch[j])
                    check = false;
        if(check)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
