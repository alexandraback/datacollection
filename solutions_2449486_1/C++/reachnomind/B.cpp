#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int n, m;
        cin>>n>>m;
        int g[n][m], f[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>g[i][j];
                f[i][j] = 100;
            }
        }

        int r[n], c[m];
        for(int i=0; i<n; i++) {
            r[i] = 1;
        }
        for(int j=0; j<m; j++) {
            c[j] = 1;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                r[i] = max(r[i], g[i][j]);
                c[j] = max(c[j], g[i][j]);
            }
        }

        bool solve = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                f[i][j] = min(r[i], c[j]);
                if(f[i][j] != g[i][j]) {
                    solve = false;
                }
            }
        }

        cout<<"Case #"<<t<<": ";
        if(solve) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}

