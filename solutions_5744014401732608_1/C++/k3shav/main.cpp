#include <bits/stdc++.h>
using namespace std;

int g[55][55];
long long v[55];
long long b,m;

long long dfs(long long i) {
    if (i == b-1) {
        return 1;
    }
    if (v[i] >= 0) {
        return v[i];
    }
    v[i] = 0;
    for(int j=0 ; j< b ; j++) {
        if (g[i][j]) {
            v[i] += dfs(j);
        }
    }
    return v[i];
}

void solve() {
    cin>>b>>m;
    for(int i=1 ; i< b ; i++) {
        for(int j=0 ; i+j< b ; j++) {
            g[j][i+j] = 1;
        }
    }
    memset(v, -1, sizeof(v));
    long long y= dfs(0);
    if (y==m) {
        cout<<"POSSIBLE\n";
        for(int i=0 ; i< b ; i++) {
            for(int j=0 ; j< b ; j++) {
                cout<<g[i][j];
            }
            cout<<endl;
        }
        return;
    }
    cerr<<b<<" "<<endl;
    for(int i=1 ; i< b ; i++) {
        for(int j=0 ; i+j< b ; j++) {
            g[j][i+j] = 0;
            memset(v, -1, sizeof(v));
            long long x= dfs(0);
            if (x<m) {
                g[j][i+j] = 1;
            }
            if (x==m) {
                cout<<"POSSIBLE\n";
                for(int i=0 ; i< b ; i++) {
                    for(int j=0 ; j< b ; j++) {
                        cout<<g[i][j];
                    }
                    cout<<endl;
                }
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main(int argc, const char **argv) {
    if(argc>=2) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }
    int T;
    cin>>T;
    for(int t=1 ; t<=T ; t++) {
        printf("Case #%d: ",t);
        solve();
        cerr<<"DONE CASE "<<t<<endl;
    }
}

