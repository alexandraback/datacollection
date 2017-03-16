#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, ll> > v;

ll tempo(int i) {
    return v[i].second*(360-v[i].first);
}

int main() {
    int t, T=1, n;
    scanf("%d", &t);
    while(t--) {
        int ans=1e9;
        v.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int d, h;
            ll m;
            scanf("%d %d %lld", &d, &h, &m);
            for(int j=0; j<h; j++) v.push_back(make_pair(d, j+m));
        }
        sort(v.begin(), v.end());
        assert((int)v.size()<=2);
        if((int)v.size()<2) ans=0;
        else {
            if(v[0].second==v[1].second) ans=0;
            else if(v[0].second<v[1].second) {
                if(tempo(0)>=tempo(1)) ans=0;
                else if(v[0].second*360+tempo(0)>tempo(1)) ans=0;
                else ans=1;
            }
            else {
                if(v[1].second*360+tempo(1)>tempo(0)) ans=0;
                else ans=1;
            }
        }
        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
