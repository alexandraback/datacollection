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
        int K , L  , S; 
        cin >> K >> L >> S; 
        string keyboard = "", target = "";
        cin >> keyboard >> target ;
        vector < int > count ( 26,0); 
        for(int i = 0 ;  i < keyboard.length(); ++i) 
            count[ keyboard[i]-'A']++; 
        vector < int > next = init_kmp( target );
        bool reach = true;
        for(int i = 0 ; i < target.size(); ++i) 
            reach &= count[target[i]-'A']>0; 
        cout << "Case #"<<cas <<": "; 
        if( !reach ){
            cout << 0.0 <<endl ; 
            continue; 
        }
        int most =  (S - L)/(target.length()-max(next[ target.size()],0))+1;  
        memset( dp, 0, sizeof(dp));
        // pos = 0, state = 0, times = 0 ; 
        dp[0][0][0] = 1.0; 
        int to[100+10][26]; 
        for(int j= 0; j < L; ++j){ 
            for(int k = 0 ; k < 26; ++k){
                if(!count[k])
                    continue; 
                char c =(char) ('A'+ k); 
                int tj = j; 
                while(tj != -1 && target[tj] != c){
                    tj = next[tj]; 
                } 
                to[ j ][k] = tj; 
            }
        }

        for(int i = 0; i < S; ++i){ 
            for(int j = 0 ; j < L ; ++j){
                for(int k = 0 ; k <= most; ++k){
                    for(int p = 0 ; p < 26 ; ++p){ 
                        if(!count[p]) 
                            continue;
                        int toj = to[j][p]; 
                        ++toj;
                        int tok = k ; 
                        if( toj ==  L ) {
                            ++tok; 
                            toj = max(0, next[toj]);
                        }
                        dp[i+1][toj][tok]+=
                            dp[i][j][k] * count[p]/K;
                    }
                }
            }
        }
        double tot = 0 ; 
        for(int  j = 0 ; j <= L ; ++j)
            for(int k =  0; k <= most; ++k)
                tot += dp[S][j][k]*k; 
        printf("%.10lf\n", most - tot); 
    }
    return 0;
}





