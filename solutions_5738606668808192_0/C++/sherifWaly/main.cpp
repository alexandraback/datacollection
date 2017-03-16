#include <bits/stdc++.h>
using namespace std;
int primes[11] = {2,3,5,7,11,13,17,19,23,29,31} ;
int n , jj ;
long long power[11][17] ;
long long convert(long long mask , int base){
    long long ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(mask & (1 << i)){
            ans += power[base][i] ;
        }
    }
    return ans ;
}
int main(){
    freopen("C-small-attempt1.in","r",stdin) ;
    freopen("hash.out","w",stdout) ;
    int t ;
    cin >> t ;
    for(int i = 2 ; i <= 10 ; i++){
        power[i][0] = 1 ;
        for(int j = 1 ; j <= 16 ; j++){
            power[i][j] = power[i][j-1] * i ;
        }
    }
    for(int I = 1 ; I <= t ; I++){
        printf("Case #%d:\n",I) ;
        cin >> n >> jj ;
        for(long long i = (1<<(n-1)) ; jj && i < (1<<n)-1 ; i++){
            if((i&1) == 0 || !(i&(1<<(n-1))))continue ;
            vector<long long>v ;
            bool flag = true ;
            for(int j = 2 ; j <= 10 && flag ; j++){
                long long x = convert(i,j) ;
                bool f = true ;
                for(int k = 0 ; k < 11 && f ; k++){
                    if(x%primes[k] == 0){
                        v.push_back(primes[k]) ;
                        f = false ;
                        break ;
                    }
                }
                if(f)flag = false ;
            }
            if(flag){
                string s = "" ;
                for(int j = 0 ; j < n ; j++){
                    if(i&(1<<j))s+="1" ;
                    else s+="0" ;
                }
                reverse(s.begin(),s.end()) ;
                cout << s ;
                for(int j = 0 ; j < v.size() ; j++){
                    cout << " " << v[j] ;
                }
                cout << "\n" ;
                jj--;
            }
        }
    }
    return 0;
}
