#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
string dp[1005];
int main(){
    int t;
    cin >> t;
    int index=1;
    while(t--){
        string s;
        cin >> s;
        dp[1]=s[0];
        for(int i=1;i<s.size();++i){
            string f=dp[i];
            string g=f;
            g=s[i]+dp[i];
            f=dp[i]+s[i];
            dp[i+1]=max(f,g);
        }
        cout << "Case #" << index++ << ": " << dp[(int)s.size()] << endl;

    }
    return 0;
}
