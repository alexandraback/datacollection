#include <bits/stdc++.h>
using namespace std;
string s1[20], s2[20];
unordered_set<string> S1, S2;
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T; cin>>T;
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" <<cs <<endl;
        int n; cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> s1[i] >> s2[i];
        }
        int ans = 0;
        for(int s = 0; s < (1 << n); s ++) {
            int cnt = 0;
            S1.clear(); S2.clear();
            for(int i = 0; i < n; i ++) {
                if(s >> i & 1) {
                    cnt ++;
                } else {
                    S1.insert(s1[i]);
                    S2.insert(s2[i]);
                }
            }
            for(int i = 0; i < n; i ++) {
                if(s >> i & 1) {
                    if(S1.find(s1[i]) == S1.end() || S2.find(s2[i]) == S2.end()) {
                        goto failed;
                    }
                }
            }
            ans = max(ans, cnt);
            failed:;
        }
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
