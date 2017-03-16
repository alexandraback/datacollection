#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
int main() {
    int T; cin >> T;
    for (int zz=1; zz <= T; zz++) {
        int E, R, N; cin >> E >> R >> N; int v[N];
        for (int i=0; i < N; i++) cin >> v[i];
        int dp[11][6]; memset(dp, 0, sizeof dp);
        for (int i=N-1; i >= 0; i--) 
            for (int j=0; j <= E; j++)
                for (int k=0; k <= j; k++)
                    dp[i][j] = max(dp[i][j], dp[i+1][min(E,j-k+R)]+k*v[i]);

        cout << "Case #" << zz << ": " << dp[0][E] << endl;
    }
    return 0;
}
