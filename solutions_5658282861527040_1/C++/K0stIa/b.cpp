#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

/*** TEMPLATE CODE ENDS HERE */

ll memo[33][2][2][2];

ll solve(int n, int a, int b, int c, bool eq_a, bool eq_b, bool eq_c) {
    
    if(n==-1) {
        return 1;
    }
    
    ll &ans = memo[n][eq_a][eq_b][eq_c];
    if(ans != -1) return ans;
    ans = 0;
    
    rep(i,2) rep(j,2) {
        
        int x = (a>>n)&1;
        int y = (b>>n)&1;
        int z = (c>>n)&1;
        
        if(eq_a && x<i) continue;
        if(eq_b && y<j) continue;
        
        int k = i&j;
        
        if(eq_c && k>z) continue;
        
        bool neq_a = eq_a && (x==i);
        bool neq_b = eq_b && (y==j);
        bool neq_c = eq_c && (z==k);
        
        ans += solve(n-1, a, b, c, neq_a, neq_b, neq_c);
    }
    
    return ans;
}

int main() {
#ifdef LOCAL_HOST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    FOR(t,1,T+1) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int x = max(a-1,max(b-1,c-1));
        int len = 0;
        rep(i,32) if((x>>i)&1) len = i;
        
        CL(memo, -1);
        
        ll cnt = 0;
        cnt = solve(len, a-1, b-1, c-1, true, true, true);
        cout << "Case #" << t << ": " << cnt << endl;
//        
//        cnt = 0;
//        rep(i,a) rep(j,b) {
//            if((i&j) < c) ++cnt;
//        }
//        cout << "Case #" << t << ": " << cnt << endl;
    }

    return 0;
}
