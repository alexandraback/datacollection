#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, LL> pii;

vector<pii> X, X2;

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    //cin>>caseNumber;
    REP(caseN, caseNumber) {
    	int E, R, N;
    	cin>>E>>R>>N;
        R = min(R, E);
        // cerr<<E<<endl;
        X2.clear();
        X.clear();
    	REP(_i, N) {
    		int v;
    		cin>>v;
            if (_i) {
                X2.clear();
                LL S = 0;
                REP(j, X.size()) {
                    LL best = X[j].second;
                    best = max(best, S - X[j].first * 1LL * v);
                    // cout<<"xxx"<<j<<' '<<X[j].first <<' '<<X[j].second<<' '<<best<<' '<<S<<endl;
                    X2.pb(make_pair(X[j].first, best));
                    S = max(S, X[j].second + X[j].first * 1LL * v);
                }
            } else {
                X2.pb(make_pair(E, 0LL));
                X2.pb(make_pair(0, v * 1LL * E));
            }                
            X.clear();
            REP(j, X2.size()) {
                if (X2[j].first + R <= E) {
                    if (X2[j].first + R < E && X2[j - 1].first + R > E) {
                        LL diff = X2[j].second - X2[j - 1].second;
                        diff /= (X2[j - 1].first - X2[j].first);
                        // cout<<"diff"<<diff<<endl;
                        X.pb(make_pair(E, X2[j].second - diff * (E - X2[j].first - R)));
                    }
                    X.pb(make_pair(X2[j].first + R, X2[j].second));
                }
            }
            X.pb(make_pair(0, X2[X2.size() - 1].second));
            // cout<<_i<<' '<<X.size()<<endl;
            // REP(i, X2.size()) {
            //     cout<<i<<"   "<<X2[i].first<<"    "<<X2[i].second<<endl;
            // }
     	}
        LL res = 0;
        REP(i, X.size()) {
            res = max(res, X[i].second);
            // cout<<i<<"   "<<X[i].first<<"    "<<X[i].second<<endl;
        }
    	printf("Case #%d: %lld\n", caseN + 1, res);
    }
    return 0;
}