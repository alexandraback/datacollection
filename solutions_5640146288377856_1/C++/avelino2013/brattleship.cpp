#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, T=1, r, c, w;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &r, &c, &w);
        int ans=r*(c/w)+w;
        if(c%w==0) ans--;
        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
