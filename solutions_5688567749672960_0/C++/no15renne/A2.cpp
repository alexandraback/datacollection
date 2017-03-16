
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;


int main(void){
    int n = 1001000;
    int dp[n];
    REP(i, n) dp[i] = INF;
    dp[0] = dp[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x = q.front(); q.pop();
        stringstream ss;
        ss << x;
        string s = ss.str();
        reverse(ALL(s));
        stringstream ss2(s);
        int y; ss2 >> y;
        if(x + 1 < n && dp[x+1] == INF){
            q.push(x + 1);
            dp[x+1] = dp[x] + 1;
        }
        if(y < n && dp[y] == INF){
            q.push(y);
            dp[y] = dp[x] + 1;
        }
    }
    
    int t;
    cin >> t;
    REP(tt, t){
        ll x;
        cin >> x;
        ll ans = dp[(int)x];
        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
    return 0;
}

