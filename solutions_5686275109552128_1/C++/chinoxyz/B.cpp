#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());

int n;
vector<int> ve;

int dp[1109][1109];
bool visit[1109][1109];

int h(int x, int c){
    
    if(x <= c) return 0;
    if(visit[c][x]) return dp[c][x];
    visit[c][x] = 1;
    int res = inf;
    for(int k = 2; k <= x; k++){
        int a = x%k;
        int b = k-a;
        res = min(res,
                  a*h(x/k+1,c)+
                  b*h(x/k,c)+
                  (k-1)
                  
                  );
    }
    return dp[c][x] = res;
}


int solve(){
    sort(all(ve));
    reverse(all(ve));
    int res = ve[0];
    int rp;
    
    
    for(int k = 1; k <= ve[0]; k++){
        rp = 0;
        for(int i = 0; i < n; i++){
            rp += h(ve[i],k);
        }
        res = min(res, rp+k);
    }
    return res;
}

int main(){
    int T;
    ri(T);
    
    int e;
    for(int t = 0; t < T; t++){
        ri(n);
        ve.clear();
        for(int i = 0; i < n; i++){
            ri(e);
            ve.pb(e);
        }
        
        printf("Case #%d: %d\n",t+1, solve());
    
    }
    return 0;
}
