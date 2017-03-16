/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("C-small-attempt1.in","r",stdin);
    // freopen("input.txt","r",stdin);
    freopen("out2.txt","w",stdout);
#endif
}

/* Input opener ends */

int d[14];
int el;
int dp[32][1<<14];

int f(int val, int mask) {

    if ( val < 0 ) return 0;
    if ( val == 0 ) return 1;
    int &res = dp[val][mask];
    if ( res != -1 ) return res;

    res = 0;
    F(i,0,el) {
        if ( (mask&(1<<i)) > 0 ) continue;

        if ( d[i] <= val )
            res |= f(val-d[i], mask|(1<<i));

    }
    return res;

}


int main() {
    input();

    int t, kase = 1; cin >> t;
    while ( t-- ) {

        // at max 8 coins for small set

        int C, D, V; set<int> s;
        cin >> C >> D >> V;
        F(i,0,D) {
            int x; cin >> x; s.insert(x);
        }
        int ans = 8;
        F(could,0,8) {

            M(dp,-1);
            set<int>::iterator it;
            int k = 0;
            FE(it,s) d[k++] = *it;
            el = s.size();

            bool ok = 1;
            int failed = -1;
            F(i,1,V+1) {
                if ( !f(i,0) ) {
                    failed = i;
                    ok = 0; break;
                }
            }

            if ( ok ) {
                ans = could;
                break;
            }

            s.insert(failed);
        }
        
        printf("Case #%d: %d\n", kase++, ans);

    }

    return 0;
}


