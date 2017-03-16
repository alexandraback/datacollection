#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <cassert>
using namespace std;

#define SD(i) scanf("%d", &(i))
#define SDD(i, j) scanf("%d%d", &(i), &(j))
#define SDDD(i, j, k) scanf("%d%d%d", &(i), &(j), &(k))
#define SDDDD(i, j, k, l) scanf("%d%d%d%d", &(i), &(j), &(k), &(l))
#define SL(i) scanf("%lld", &(i))
#define SC(i) scanf(" %c", &(i))
#define SS(i) scanf(" %s", &(i))
#define PD(i) printf("%d", i)
#define PL(i) printf("%lld", i)
#define PC(i) printf("%c", i)
#define PS(i) printf("%s", i)
#define PN printf("\n");

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SFOR(i,a,b,c) for(int i=a;i<b;i+=c)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(auto it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define SRT(x) sort(ALL(x))
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define MOD 1000000007
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long UL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PI;

bool fn(string a, int b) {
    RREP(i, a.length()) {
        if(a[i] != '?' && a[i] != b%10 + '0') return false;
        b /= 10;
    }
    return b == 0? true:false;
}

string a, b, ma, mb;
LL md;
int state;

void rec(int in) {
    if(in == a.length()) {
        LL c = 0, d = 0;
        REP(i, in) {
            c *= 10;
            c += a[i]-'0';
            d *= 10;
            d += b[i]-'0';
        }
        if(md > abs(c-d)) md = abs(c-d), ma = a, mb = b;
        else if(md == abs(c-d)) {
            if(ma > a) ma = a, mb = b;
            else if(ma == a && mb > b) mb = b;
        }
        return;
    }
    int tstate = state;
    if(a[in] == b[in] && a[in] == '?') {
        if(state == 0) {
            a[in] = b[in] = '0';
            rec(in+1);
            a[in] = '0', b[in] = '1';
            state = 2;
            rec(in+1);
            a[in] = '1', b[in] = '0';
            state = 1;
            rec(in+1);
        } else if(state == 1) {
            a[in] = '0', b[in] = '9';
            rec(in+1);
        } else {
            a[in] = '9', b[in] = '0';
            rec(in+1);
        }
        a[in] = b[in] = '?';
    } else if(a[in] == '?') {
        if(state == 0) {
            if(b[in] == '0') a[in] = '9';
            else a[in] = b[in] - 1;
            state = 2;
            rec(in+1);
            if(b[in] == '9') a[in] = '0';
            else a[in] = b[in] + 1;
            state = 1;
            rec(in+1);
            a[in] = b[in];
            state = 0;
            rec(in+1);
        } else if(state == 1) {
            a[in] = '0';
            rec(in+1);
        } else {
            a[in] = '9';
            rec(in+1);
        }
        a[in] = '?';
    } else if(b[in] == '?') {
        if(state == 0) {
            if(a[in] == '0') b[in] = '9';
            else b[in] = a[in] - 1;
            state = 1;
            rec(in+1);
            if(a[in] == '9') b[in] = '0';
            else b[in] = a[in] + 1;
            state = 2;
            rec(in+1);
            b[in] = a[in];
            state = 0;
            rec(in+1);
        } else if(state == 1) {
            b[in] = '9';
            rec(in+1);
        } else {
            b[in] = '0';
            rec(in+1);
        }
        b[in] = '?';
    } else {
        if(state == 0) {
            if(a[in] > b[in]) state = 1;
            else if(a[in] < b[in]) state = 2;
        }
        rec(in+1);
    }
    state = tstate;
}

void solve() {
    state = 0;
    md = MOD * (LL) MOD;
    cin>>a>>b;
    rec(0);
    cout<<ma<<" "<<mb<<endl;
}

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        REP(i, 1) {
    #endif
    int zz = 1, qq;
    SD(zz);
    qq = zz;
    while(zz--) {
        printf("Case #%d: ", qq-zz);
        solve();
    }
    #ifdef raaja
        }
    #endif
}
