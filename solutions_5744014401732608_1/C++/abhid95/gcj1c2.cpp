#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mat[1005][1005], i, j, tn, r, p, t, _t, n, m, cn;
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>n>>m;
        memset(mat, 0, sizeof mat);
        p = 1;
        for(i = 0; i < n-2; i++) {
            p*=2;
        }
        if(p < m) {
            printf("Case #%lld: IMPOSSIBLE\n", _t);
            continue;
        }
        printf("Case #%lld: POSSIBLE\n", _t);
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                mat[i][j] = 1;
            }
        }
        if(p != m) {
            mat[0][n-1] = 0;
            tn = m;
            cn = n-2;
            while(tn > 0) {
                //cout<<"Hi"<<endl;
                r = tn%2;
                tn/=2;
                if(!r) mat[0][cn] = 0;
                cn--;
                //cout<<tn<<" "<<cn<<endl;
            }
            while(cn > 0) {
                mat[0][cn] = 0;
                cn--;
            }
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cout<<mat[i][j];
            }
            cout<<endl;
        }

    }

    return 0;
}
