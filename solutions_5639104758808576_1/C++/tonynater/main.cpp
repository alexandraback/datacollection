//tonynater

#include <cstdio>
#include <iostream>
#include <string>

#define sz(x) ((int) x.size())

using namespace std;

string S;

int main() {
    freopen("/Users/tonynater/Downloads/A-large.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/GCJ_2015/QA/qa_large.out", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> S >> S;
        
        int res = 0;
        for(int i = 0, cur = 0; i < sz(S); i++) {
            if(cur < i) {
                ++res;
                ++cur;
            }
            cur += S[i]-'0';
        }
        
        cout << "Case #" << t+1 << ": " << res << '\n';
    }
    
    return 0;
}