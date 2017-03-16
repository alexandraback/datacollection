#include <bits/stdc++.h>
using namespace std;
vector<pair<string,string>>v ;
void solve(int k ,string s){
    if(k == 0){
        string ans = "" ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'L'){
                ans += s ;
            }
            else {
                for(int j = 0 ;j < s.size() ; j++)ans += "G" ;
            }
        }
        v.push_back({s,ans}) ;
        return ;
    }
    solve(k-1,s+"G") ;
    solve(k-1,s+"L") ;

}
int main(){
    freopen("D-large.in","r",stdin) ;
    freopen("hash.out","w",stdout) ;
    int t ;
    cin >> t ;
    for(int I = 1 ; I <= t ; I++){
        printf("Case #%d: ",I) ;
        int k , c , s ;
        cin >> k >> c >> s ;
        if(c == 1){
            if(s == k){
                for(int i = 1 ; i <= k ; i++){
                    cout << i << " " ;
                }
            }
            else cout << "IMPOSSIBLE" ;
            cout << "\n" ;
            continue ;
        }
        if(s >= k-1){
            if(k == 1){
                cout << "1" ;
            }
            else for(int i = 2 ; i <= k ; i++)cout << i << " " ;
        }
        else cout << "IMPOSSIBLE" ;
        cout << "\n" ;
    }
    /*solve(4,"") ;
    for(int i = 0 ; i < v.size() ; i++)cout << v[i].first << " " << v[i].second << "\n" ;
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = i+1 ; j < v.size() ; j++){
            int c = 0 ;
            for(int k = 0 ; k < v[0].second.size() ; k++){
                if(v[i].second[k] == 'L' && v[j].second[k] == 'L')c++ ;
            }
            if(c == 4){
                cout << v[i].second << " " << v[j].second << "\n" ;
            }
        }

    }*/
    return 0;
}
