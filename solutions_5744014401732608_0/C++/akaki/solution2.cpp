#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000000000000000000LL;
long long i,j,k,l,m,n,t, test;

int ans[50][50];


int main(){
    freopen("output.txt", "w", stdout);
    cin >> t;

    for (test = 0; test < t; test++){
        cout << "Case #"<< test+1 << ": ";
        cin >> n >> m;
        memset(ans, 0, sizeof(ans));
        for (i = 0; i < n - 1; i++){
            for (j = i + 1; j < n - 1; j++){
                ans[i][j] = 1;
            }
        }
        if (m > (1LL<<(n-2))){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";
        m--;
        ans[0][n-1] = 1;
        for (i = 1; i < n - 1; i++){
            if (m & (1LL << (i - 1))){
                ans[i][n - 1] = 1;
            }
        }
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                cout << ans[i][j];
            }
            cout << "\n";
        }    
    }
    return 0;
}
