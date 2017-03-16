#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, T=1, c, d, v, dp[33];
    scanf("%d", &t);
    while(t--) {
        vector<int> a;
        scanf("%d %d %d", &c, &d, &v);
        assert(c==1);
        for(int i=0; i<d; i++) {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        int ans=0;
        while(1) {
            memset(dp, 0, sizeof(dp));
            dp[0]=1;
            int s=0;
            for(int i=0; i<a.size(); i++) {
                for(int j=s; j>=0; j--) if(dp[j] && j+a[i]<=v) dp[j+a[i]]=1;
                s+=a[i];
                s=min(s, v);
            }
            int ok=1;
            for(int i=0; i<=v && ok; i++) if(!dp[i]) {
                ok=0;
                ans++;
                a.push_back(i);
            }
            if(ok) break;
        }
        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
