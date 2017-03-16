#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    for(int T = 1; T <= t; T++) {
        int k, l, s;
        cin >> k >> l >> s;
        string line, key;
        cin >> key >> line;
        int n = 1;
        for(int i = 0; i < s; i++) n *= k;
        double ans = 0, rekord = 0;
        for(int i = 0; i < n; i++) {
            int a = i;
            char sl[7];
            for(int j = 0; j < s; j++) {
                sl[j] = key[a%k];
                a/=k;
//                 cout << sl[j];
            }
            double loc = 0;
            for(int j = 0; j <= s - l; j++) {
                for(int h = 0; h < l; h++) {
                    if(sl[j+h] != line[h])
                        break;
                    if(h == l-1)
                        loc += 1;
                }
            }
            rekord = max(rekord, loc);
            ans += loc;
        }
        ans /= (double)n;
        ans = rekord - ans;
        printf("Case #%d: %.10lf\n", T, ans);
    }
}