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

int dp[1000006];
string to_s(int n) {
    string res;
    stringstream ss;
    ss<<n;
    ss>>res;
    return res;
}
int to_i(string &s) {
    int res;
    stringstream ss;
    ss<<s;
    ss>>res;
    return res;
}
int f(int n) {
    string s=to_s(n);
    reverse(all(s));
    while(s[0]=='0') s.erase(0,1);

    return to_i(s);
}
void init() {
    rep(i,1000006) dp[i]=INF;
    dp[1]=1;
    rep(i,1000005) {
        dp[i+1]=min(dp[i]+1,dp[i+1]);
        int m=f(i);
        if(m<1000006) dp[m]=min(dp[m],dp[i]+1);
    }
}
void solve() {
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
}

int main() {
    init();

    int t;
    cin>>t;
    rep(i,t) {
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

