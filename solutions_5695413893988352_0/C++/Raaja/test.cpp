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

void solve() {
    string a, b;
    cin>>a>>b;
    string c = a, d = b;
    //cout<<a<< " "<<b<<endl;
    int n = a.length(), state = 0;
    REP(i, n) {
        if(state == 0) {
            if(a[i] == b[i] && a[i] == '?') a[i] = b[i] = '0';
            else if(a[i] == '?') a[i] = b[i];
            else if(b[i] == '?') b[i] = a[i];
            else if(a[i] < b[i]) state = 1;
            else if(a[i] > b[i]) state = -1;
        } else if(state == 1) {
            if(a[i] == '?') a[i] = '9';
            if(b[i] == '?') b[i] = '0';
        } else {
            if(a[i] == '?') a[i] = '0';
            if(b[i] == '?') b[i] = '9';
        }
    }
    int mnd = MOD, mna = -1, mnb = -1;
    REP(i, 1000) REP(j, 1000) {
        if(fn(c, i) && fn(d, j) && abs(i-j) < mnd) mnd = abs(i-j), mna = i, mnb = j;
    }
    RREP(i, n) {
        a[i] = mna%10 + '0';
        b[i] = mnb%10 + '0';
        mna /= 10;
        mnb /= 10;
    }
    cout<<a<<" "<<b<<endl;
    //cout<<mna<<" "<<mnb<<endl;
    //assert(fn(a, mna) && fn(b, mnb));
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
