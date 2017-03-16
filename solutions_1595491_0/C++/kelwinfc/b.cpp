#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX 110
#define INF 0x77FFFFFF

using namespace std;

int n;
int s[MAX];
int p;
int dp[MAX][MAX];

int f(int i, int r){
    
    if ( i == n ){
        if ( r == 0 ){
            return 0;
        } else {
            return -INF;
        }
    }
    
    if ( dp[i][r] != -1 ){
        return dp[i][r];
    }
    
    int sol = 0;
    
    if ( s[i] == 0 ){
        return dp[i][r] = sol = (0 >= p ? 1 : 0) + f(i+1,r);
    } else if ( s[i] == 1 ){
        return dp[i][r] = sol = (1 >= p ? 1 : 0) + f(i+1,r);
    }
    
    // no surprise
    {
        int s3 = s[i]/3;
        int scores[3];
        
        if ( s[i] % 3 == 0 ){
            scores[0] = s3;
            scores[1] = s3 ;
            scores[2] = s3 ;
        } else if ( s[i] % 3 == 1 ){
            scores[0] = s3-1;
            scores[1] = s3+1;
            scores[2] = s3+1;
        } else {
            scores[0] = s3;
            scores[1] = s3+1;
            scores[2] = s3+1;
        }
        
        //cout << scores[0] << " " << scores[1] << " " << scores[2] << " = " << s[i] << endl;
        if( scores[0] + scores[1] + scores[2] != s[i] ){
            cout << scores[0] << " " << scores[1] << " " << scores[2] << " = " << s[i] << endl;
            cout << "error\n";
            exit(1);
        }
        
        sol = max(sol, (scores[2] >= p ? 1 : 0) + f(i+1,r));
    }
    
    // surprise
    if ( r > 0 ){
        int s3 = s[i]/3;
        int scores[3];
        
        if ( s[i] % 3 == 0 ){
            scores[0] = s3-1;
            scores[1] = s3 ;
            scores[2] = s3+1;
        } else if ( s[i] % 3 == 1 ){
            scores[0] = s3-1;
            scores[1] = s3+1;
            scores[2] = s3+1;
        } else {
            scores[0] = s3;
            scores[1] = s3;
            scores[2] = s3+2;
        }
        
        //cout << scores[0] << " " << scores[1] << " " << scores[2] << " = " << s[i] << endl;
        if( scores[0] + scores[1] + scores[2] != s[i] ){
            cout << scores[0] << " " << scores[1] << " " << scores[2] << " = " << s[i] << endl;
            cout << "error\n";
            exit(1);
        }
        
        sol = max(sol, (scores[2] >= p ? 1 : 0) + f(i+1,r-1));
    }
    
    return dp[i][r] = sol;
}

//
int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        int r;
        cin >> n >> r >> p;
        
        for (int i=0; i<n; i++){
            cin >> s[i];
        }
        
        memset(dp, -1, sizeof dp);
        cout << "Case #" << t << ": " << f(0,r) << endl;
    }
    return 0;
}