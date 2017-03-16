#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#define PI 1
#include <queue>
#define FOR(i,a)    for(int i = 0;i<(a);i++)
#define REP(i,a,b)  for(int i = (a);i<(b);i++)
#define SZ(a)   ((signed)a.size())

using namespace std;

int caseno = 1;

void solve(){
    cout<<"Case #"<<caseno<<": "<<"\n";
    int r,n,m,k;
    cin>>r>>n>>m>>k;
    FOR(i,r){
        vector<int>v(k);
        FOR(j,k)    cin>>v[j];
        REP(l,2,6){
            REP(m,l,6){
                REP(n,m,6){
                    set<int>s;
                    int arr[] = {l,m,n};
                    FOR(o,8){
                        int pr = 1;
                        int p = o,q = 0;
                        while(p){
                            if(p%2)    pr = pr*arr[q];
                            q++;
                            p/= 2;
                        }
                        s.insert(pr);
                    }
                    bool tr = true;
                    FOR(o,k){
                        if(s.find(v[o]) == s.end()) {tr = false;break;}
                    }
                    if(tr){
                        cout<<l<<m<<n<<"\n";
                        goto outlabel;
                    }
                }
            }
        }
        outlabel:;
    }
    cout<<"\n";
    caseno++;
}

int main(){
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    cin>>t;
    FOR(i,t)    solve();
    return 0;
}

