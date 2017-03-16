#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string s,res;
    for(int caso=1;caso<=n;caso++){
        cin >> s;
        res = s[0];
        for(int i=1;i<s.length();i++){
            if( s[i] >= res[0] ) res = s[i] + res;
            else res+=s[i];
        }
        cout << "Case #" << caso << ": " << res << "\n";
    }
    return 0;
}
