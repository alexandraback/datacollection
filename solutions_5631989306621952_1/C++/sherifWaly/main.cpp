#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("A-large(2).in","r",stdin) ;
    freopen("hash.out","w",stdout) ;
    int t ;
    cin >> t ;
    for(int I = 1 ; I <= t ; I ++){
        string s ;
        cin >> s;
        printf("Case #%d: ",I);
        string ans = "" ;
        ans += s[0] ;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] >= ans[0]){
                ans = s[i] + ans ;
            }
            else {
                ans += s[i] ;
            }
        }
        cout << ans << "\n" ;
    }
    return 0;
}
