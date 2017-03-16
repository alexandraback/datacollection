#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int C,D,V;
bool used[31];

int rec(int idx,int added){
    if(added>5)return 1<<30;
    if(idx>30){
        vector<int> denoms;
        REP(i,V+1)if(used[i])denoms.push_back(i);
        vector<bool> dp(V+1);
        dp[0] = true;
        REP(i,denoms.size()){
            for(int j=V; j-denoms[i]>=0; j--){
                dp[j] = dp[j] || dp[j-denoms[i]];
            }
        }
        bool ok = true;
        REP(i,V+1)ok = ok && dp[i];
        return ok ? added : 1<<30;
    }

    int res = rec(idx+1,added);
    if(!used[idx]){
        used[idx] = true;
        res = min(res, rec(idx+1, added+1));
        used[idx] = false;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    REP(testCase,T){
        cin >> C >> D >> V;
        memset(used,false,sizeof(used));
        REP(i,D){
            int d;
            cin >> d;
            used[d] = true;
        }
        printf("Case #%d: %d\n", testCase+1, rec(1,0));

    }
    return 0;
}
