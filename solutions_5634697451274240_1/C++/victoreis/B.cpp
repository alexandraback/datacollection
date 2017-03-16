#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, ans, cur; string s; cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> s;
        ans = 1, cur = s[0];
        for(int i = 1; i < s.size(); i++){
            if(cur != s[i]){
                cur = s[i];
                ans++;
            }
        }
        if(s[s.size() - 1] == '+') ans--;
        cout << "Case #" << t << ": " << ans << endl;
    }
}
