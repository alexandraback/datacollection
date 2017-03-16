#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("B-large.in","r",stdin) ;
    freopen("hash.out","w",stdout) ;
    int t ;
    cin >> t ;

    for(int I = 1 ; I <= t ; I++){
        string s ;
        printf("Case #%d: ",I) ;
        cin >> s ;
        int n = s.size() ;
        int ans = 0 ;
        while(true){
            int i = 0 ;
            for(i = 1 ; i < n ; i++){
                if(s[i] != s[i-1]){
                    i-- ;
                    break ;
                }
            }
            if(i == n){
                if(s[0] == '-')ans ++ ;
                break ;
            }
            ans ++ ;
            for(int j = 0 ; j <= i ; j++){
                if(s[j] == '-')s[j] = '+' ;
                else s[j] = '-' ;
            }
        }
        cout << ans << "\n" ;
    }
    return 0;
}
