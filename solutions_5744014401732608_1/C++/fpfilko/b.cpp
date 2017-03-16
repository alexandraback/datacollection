#include<iostream>
#include<vector>

using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 1; t<=T; t++) {
        long long n, m; cin >> n >> m;
        vector<vector<long long>> v(n, vector<long long>(n,0));
        long long ma = 1ll<<(n-2);
        if(m > ma) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }
        if(m == ma) {
            v[0][n-1] = 1;
            m--;
        }
        for(int i = 1; i<n-1; i++) {
            v[0][i] = 1;
        }
        for(int i = 1; i<n-1; i++) {
            for(int j = i+1; j<n-1; j++) {
                v[i][j] = 1;
            }
        }
        int i = 1;
        while(m > 0) {
            if(m%2 == 1) {
                v[i][n-1] = 1;
            }
            m /= 2;
            i++;
        }
        cout << "Case #" << t << ": POSSIBLE\n";
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cout << v[i][j];
            }
            cout << "\n";
        }

    }
}
