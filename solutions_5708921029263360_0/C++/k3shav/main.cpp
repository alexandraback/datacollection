#include <bits/stdc++.h>
using namespace std;

int cjp[11][11];
int cps[11][11];
int cjs[11][11];

void solve() {
    int J,p,s,z;
    vector <pair<int, pair<int, int>>> ans;
    memset(cjp, 0, sizeof(cjp));
    memset(cps, 0, sizeof(cps));
    memset(cjs, 0, sizeof(cjs));
    
    cin>>J>>p>>s>>z;
    for(int k = 1; k<= s ; k++) {
        for(int j=1 ; j<= p ; j++) {
            for(int i=1 ; i<= J ; i++) {
                if (cjs[i][k] >=z || cjp[i][j]>=z || cps[j][k]>=z) {
                    continue;
                }
                cjp[i][j]++;
                cjs[i][k]++;
                cps[j][k]++;
                ans.push_back({i, {j,k}});
            }
        }
    }
    for(int k = 1; k<= s ; k++) {
        for(int j=1 ; j<= p ; j++) {
            for(int i=1 ; i<= J ; i++) {
                if (cjs[i][k] >=z || cjp[i][j]>=z || cps[j][k]>=z) {
                    continue;
                }
                cjp[i][j]++;
                cjs[i][k]++;
                cps[j][k]++;
                ans.push_back({i, {j,k}});
            }
        }
    }

    
    for(int k = 1; k<= s ; k++) {
        for(int j=1 ; j<= p ; j++) {
            for(int i=1 ; i<= J ; i++) {
                if (cjs[i][k] >=z || cjp[i][j]>=z || cps[j][k]>=z) {
                    continue;
                }
                cjp[i][j]++;
                cjs[i][k]++;
                cps[j][k]++;
                ans.push_back({i, {j,k}});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto v:ans) {
        cout<<v.first<<" "<<v.second.first<<" "<<v.second.second<<endl;
    }
    
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

