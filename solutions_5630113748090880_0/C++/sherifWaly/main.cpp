#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin) ;
    freopen("hash.out","w",stdout) ;
    int t ;
    cin >> t ;
    for(int I = 1 ; I <= t ; I ++){
        int n ;
        cin >> n ;
        map<int,int>mp ;
        int x ;
        for(int i = 0 ; i < 2*n-1 ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> x ;
                mp[x]++;
            }
        }
        printf("Case #%d: ", I);
        for(map<int,int> :: iterator it = mp.begin() ; it != mp.end() ; it++){
            if(it->second % 2){
                cout << it->first << " " ;
            }
        }
        cout << "\n" ;
    }
    return 0;
}
