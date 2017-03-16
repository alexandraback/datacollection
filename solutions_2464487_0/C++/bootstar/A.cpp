#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
typedef long long LL;

bool check(LL a, LL r, LL T){
    T -= (2*a*a + 2*a);
    LL ans = 2*r*a - 3*a;
    if(ans <= T)
        return true;
    return false;
}

int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T, cas = 1;
    LL l, r, a, b;
    scanf("%d", &T);
    while(T--){
        cin>>a>>b;
        l = 0, r = 20000000;
        while(l <= r){
            LL mid = (l+r)>>1;
            if(check(mid, a, b))
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("Case #%d: %lld\n", cas++, r);
    }
    return 0;
}
