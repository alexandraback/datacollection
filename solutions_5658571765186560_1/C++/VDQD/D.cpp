#include <bits/stdc++.h>
using namespace std;

int x, r, c;

bool solve(){
    if (r > c) swap(r, c);
    if (r*c % x || x >= 7) return true;
    if (r < (x+1)/2) return true;
    if (x <= 3) return false;
    if (x == 4) return (r == 2);
    if (x == 5) return false;
    if (x == 6){
        if (r == 3) return true;
        return false;
    }
    return true;
}

int main(){
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    while (t--){
        scanf("%d%d%d", &x, &r, &c);
        printf("Case #%d: %s\n", ++cases, solve()?"RICHARD":"GABRIEL");
    }
    return 0;
}
