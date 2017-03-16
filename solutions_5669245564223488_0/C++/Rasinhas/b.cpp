#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m = 1e9+7;
string s[111];
int p[111];
int n;

int valid() {
    string v = "";
    int vis[26];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) v += s[p[i]];
    int pt = 0;
    while(1) {
        while(v[pt] == v[pt+1]) pt++;
        if(vis[v[pt]-'a'] > 0) return 0;
        vis[v[pt]-'a']++;
        pt++;
        if(pt == v.size()) return 1;
    }
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> s[i];
            p[i] = i;
        }
        ll ans = 0;
        do {
            if(valid()) ans++;
        } while(next_permutation(p,p+n));
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
