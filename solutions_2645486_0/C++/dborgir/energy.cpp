#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main () {
    int T; cin >> T;
    for (int step=1; step<=T; step++) {
        int E, R, N; cin >> E >> R >> N;
        vector<int> v(N);    
        int result = 0;
        for (int i=0; i<N; i++)
            cin >> v[i];
        if (R >= E) {
            for (int i=0; i<N; i++)
                result += v[i];
            cout << "Case #" << step << ": " << result*E << endl;          
            continue;
        }    
        int dp[N][E+1];
        for (int i=0; i<=E; i++) {
            dp[N-1][i] = v[N-1]*i;    
        }
        for (int i=N-2; i>=0; i--) {
            for (int j=0; j<=E; j++) {
                int m = -1;    
                for (int k=0; k<=j; k++) {
                    if (m < v[i]*k + dp[i+1][min(E, j-k+R)]) 
                        m = v[i]*k + dp[i+1][min(E, j-k+R)];
                }
                dp[i][j] = m;        
            }    
        }
        cout << "Case #" << step << ": " << dp[0][E] << endl;
    }     
    
    
    
}
