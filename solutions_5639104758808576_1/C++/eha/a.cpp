#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n; string s;
        cin >> n >> s;
        int ans = 0, cnt = 0;
        for(int i = 0; i < (int)s.size(); i++){
            int d = max(0, i-cnt);
            ans += d;
            cnt += d;
            cnt += s[i]-'0';
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
