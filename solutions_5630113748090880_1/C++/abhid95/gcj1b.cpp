#include<bits/stdc++.h>
using namespace std;
int t, _t, n, i, h[10005], mx, x, j;
vector<int> v;
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>n;
        mx = 0;
        memset(h, 0, sizeof h);
        for(i = 0; i < 2*n-1; i++) {
            for(j = 0; j < n; j++) {
                cin>>x;
                h[x]++;
                mx = max(mx, x);
            }
        }
        for(i = 0; i <= mx; i++) {
            if(h[i]&1) {
                v.push_back(i);
            }
        }
        printf("Case #%d:", _t);
        for(i = 0; i < v.size(); i++) {
            printf(" %d", v[i]);
        }
        printf("\n");
        v.clear();
    }

    return 0;
}
