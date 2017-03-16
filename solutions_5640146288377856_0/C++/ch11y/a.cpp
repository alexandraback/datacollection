#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector> 
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std; 


const int maxn = 2000000 + 100; 
char ss1[maxn], ss2[maxn]; 
vector < int > init_kmp(string s){ 
    if( "" == s ) return vector< int > (); 
    vector < int > next( s.length()+1, -1);
    for(int i = 0, j = -1 ; i < s.length();){
        if( j == -1 || s[ i ] == s[j] )
            next[++i] = ++j ; 
        else j = next[j];
    }
    return next; 
}

double dp[100+5][100+5][100+5]; 

int main (){
    freopen("in.txt","r",stdin); 
    freopen("out.txt","w",stdout);

    int T; 
    cin >> T;
    for(int cas = 1 ; cas <= T; ++cas){
        int R , C, W; 
        cin >>  R >> C>>W;  

        int ans =   R*(max(0,  C- C%W - W))/W +max(0,R-1); 
        int left = min( C,C%W+W); 
        if( left == W ) 
            ans += W;
        else{ 
            ans += W+1; 
        }
        cout <<"Case #"<<cas <<": " << ans << endl;
    }
    return 0;
}

