#include <bits/stdc++.h>
using namespace std;

int k, l, s, cnt, m;
char c[11], d[11], aux[11];

void solve(int p) {
    if(p==s) {
        int t=0;
        for(int i=l-1; i<s; i++) {
            int ok=1;
            for(int j=0; j<l && ok; j++) if(d[j]!=aux[i-(l-1)+j]) ok=0;
            if(ok) t++;
        }
        cnt+=(m-t);
        m=max(m, t);
        return;
    }
    for(int i=0; i<k; i++) {
        aux[p]=c[i];
        solve(p+1);
    }
}

int main() {
    int t, T=1;
    scanf("%d", &t);
    while(t--) {
        cnt=m=0;
        scanf("%d %d %d %s %s", &k, &l, &s, c, d);
        solve(0);
        cnt=0;
        solve(0);
        double ans=cnt;
        for(int i=0; i<s; i++) ans/=k;
        printf("Case #%d: %lf\n", T++, ans);
    }
    return 0;
}
