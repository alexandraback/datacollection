#include <bits/stdc++.h>
#define MAXN 2000
using namespace std ;
int a[MAXN];
int t,n, ans;
int mini,maxi;

int main() {
 
 
    cin >> t;
    for(int step=1;step<=t;++step ) {
       cin >> n;
       maxi=0;
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
            maxi = max(maxi,a[i]) ;
        }
        mini = maxi ;
        for(int i = 1;i <= maxi; i++) {
            ans= i ;
            for(int j = 0 ; j < n ; j++) {
                if( a[j] > i ) {
                    if( a[j]%i == 0 )
                        ans+=(a[j]/i-1) ;
                    else
                        ans+=(a[j]/i) ;
                }
            }
            mini = min(mini,ans) ;
        }

        printf("Case #%d: %d\n", step, mini) ;
    }
    return 0 ;
}
