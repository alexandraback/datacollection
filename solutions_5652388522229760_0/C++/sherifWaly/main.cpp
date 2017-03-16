#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin) ;
    freopen("hash.out","w",stdout) ;
    int t ;
    cin >> t ;
    int mask = (1<<10)-1 ;

    for(int I = 1 ; I <= t ; I++){
        int n ;
        cin >> n ;
        printf("Case #%d: ",I) ;
        if(n == 0){
            cout << "INSOMNIA\n" ;
            continue ;
        }
        int m = 0 ;
        int x = n ;
        int y = 0 ;
        while(true){
            y += n ;
            x = y ;
            while(x){
                m |= 1 << (x%10) ;
                x /= 10 ;
            }
            if(m == mask){
                break ;
            }
        }
        cout << y << "\n" ;
    }
    return 0;
}
