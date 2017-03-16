#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int N = 205;
const int M = 15;
const int INF = 0x3f3f3f3f;
const LL MOD = 1e9 + 7;

int n, m, k;
LL gcd(LL a, LL b)
{
    LL tmp;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    while(a % b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return b;
}


int main() {
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
//    cout<<ans<<endl;
    int cases;
    scanf ("%d", &cases);
    for (int cas = 1; cas <= cases; cas ++) {
        LL p, q;
        //__int64 ans = 0;
        cin>>p;
        getchar();
        cin>>q;
        LL tmp = gcd(p, q);
        p /= tmp;
        q /= tmp;
        printf ("Case #%d: ", cas);

        bool flag = 0;
        LL cnt = 1;
        for (int i = 1; i <= 40; i++) {
            cnt *= (2LL);
            if (cnt == q) {
                //printf ("%d\n", i);
                flag = 1;
                break;
            }
        }
        if (!flag) {
            puts("impossible");
            continue;
        }
        double num = p*1.0/q;
        for (int i = 1; i <= 40; i++) {
            num *= 2;
            if (num >= 1) {
                printf ("%d\n", i);
                flag = 1;
                break;
            }
        }



    }
    return 0;
}
