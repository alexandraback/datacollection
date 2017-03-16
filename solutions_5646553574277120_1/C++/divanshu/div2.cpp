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
    freopen("C-large.in","r",stdin);
    // freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

int main() {
    input();

    int t, kase = 1; cin >> t;
    while ( t-- ) {

        // at max 8 coins for small set

        int C, D, V; set<ill> s;
        cin >> C >> D >> V;
        F(i,0,D) {
            int x; cin >> x; s.insert(x);
        }
        ill last = 1;
        ill where = 1;

        int ans = 0;

        while ( where <= V ) {


            // cout << last << " " << where << endl;
            set<ill>::iterator it = s.lower_bound(last);
            if ( it == s.end() ) {
                s.insert(where);
                ans++;
                continue;
            }
            ill x = *it;
            if ( x <= where ) {
                where += C*x;
                last = x+1;
            } else {
                s.insert(where);
                ans++;
            }

        }
        
        printf("Case #%d: %d\n", kase++, ans);

    }

    return 0;
}




