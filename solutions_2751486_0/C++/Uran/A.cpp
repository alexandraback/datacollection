#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

const int N = 1111111;

char buf[N];

inline bool isvow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int a[N];

void solve(int case_id) {
    int p;
    scanf("%s%d", buf, &p);
    int n = strlen(buf);
    rept(i, n) a[i] = !isvow(buf[i]);
    vector<pii> seg;
    int st = -1;
    a[n] = 0;
    rept(i, n + 1) {
        if (a[i] == 0 && st != -1) {
            if (i - st >= p) seg.pb(mp(st, i));
            st = -1;
        } else if (a[i] == 1 && st == -1) {
            st = i;
        }
    }
    ll ans = (ll) n * (n + 1) / 2;
    SORT(seg);
    rept(i, L(seg)) {
        for (int j = seg[i].x; j < seg[i].y; j++) {
            a[j] = 2;
        }
     }
    rept(i, n) if (a[i] == 1) a[i] = 0;
    //cerr << DEB(a, n) << " " << ans << endl;

    st = -1;
    int cnt = 0;
    rept(i, n) {
        cnt += a[i] == 2;
        if (a[i] == 0) cnt = 0;
        if (a[i] == 2 && cnt >= p) {
            st = i - p + 1;
        }
        //cerr << i << " " << st << " " << i - st << endl;
        ans -= i - st;
    }
    printf("Case #%d: %lld\n", case_id, ans);
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
        solve(tc);
    }
    return 0;
}
