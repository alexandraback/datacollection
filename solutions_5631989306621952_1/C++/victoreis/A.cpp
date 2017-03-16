#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        string s; cin >> s;
        string ans;
        ans = ans + s[0];
        for(int i = 1; i < s.size(); i++){
            if(s[i] >= ans[0]) ans = s[i] + ans;
            else ans = ans + s[i];
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
