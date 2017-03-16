#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t ; cas ++) {
        int l = 0;
        cin >> l;
        string s;
        cin >> s;
        int sum = (s[0]-'0');
        int ans = 0;
        for(int i = 1 ; i <= l ; i++) {
            if(sum <= i) {
                ans += i - sum;
                sum = i;
            }
            sum += (s[i] - '0');
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }

    return 0;
}
