#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;
int C,D,V;
set<int> S;
vector<int> vec;

void solve() {
    int dp[300]={};
    S.clear();
    vec.clear();

    cin>>C>>D>>V;
    rep(i,D) {
        int a;
        cin>>a;
        S.insert(a);
        vec.pb(a);
    }
    rep(S,1<<D) {
        int sum=0;
        rep(i,5) if((S>>i)&1) sum+=vec[i];
        dp[sum]=1;
    }
    int ans=0;
    rep(i,V+1) if(i&&!dp[i]) ans++;
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    rep(i,t) {
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

