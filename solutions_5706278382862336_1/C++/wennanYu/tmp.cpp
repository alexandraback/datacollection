#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

long long p, q;
int T, cas = 0;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%lld/%lld", &p, &q);
        long long g = __gcd(p, q);
        p /= g; q /= g;
        long long t = q;
        bool flag = true;
        while (t > 1){
            if (t&1){
                flag = false;
                break;
            }
            t>>=1;
        }
        printf("Case #%d: ", ++cas);
        if (!flag){
            printf("impossible\n");
            continue;
        }
        int ans = 1;
        while (p<(q/2)){
            ans++;
            q/=2;
        }
        printf("%d\n", ans);
    }
}
