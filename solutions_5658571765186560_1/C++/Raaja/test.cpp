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
using namespace std;

#define SD(i) scanf("%d", &(i))
#define SDD(i, j) scanf("%d%d", &(i), &(j))
#define SDDD(i, j, k) scanf("%d%d%d", &(i), &(j), &(k))
#define SDDDD(i, j, k, l) scanf("%d%d%d%d", &(i), &(j), &(k), &(l))
#define SL(i) scanf("%lld", &(i))
#define SC(i) scanf(" %c", &(i))
#define SS(i) scanf(" %s", &(i))
#define PD(i) printf("%d\n", i)
#define PL(i) printf("%lld", i)
#define PC(i) printf("%c", i)
#define PS(i) printf("%s", i)
#define PN printf("\n");

#define FOR(i,a,b) for(int i=a;i<b;++i)
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

void solve() {
    int x, r, c;
    SDDD(x, r, c);
    if(r < c) swap(r, c);
    bool flag = false;
    if(x >= 7 || x > 2*c || r*c % x || x >= r+c || x > r) flag = true;
    else if(x == 4) {
        if(c < 3) flag = true;
    } else if(x > 4) {
        int mr = x/2+1, mc = (x+1)/2;
        if(r-mr < 2 && c-mc < 2) flag = true;
        else if(r == mr || c == mc) {
            if(r == mr) swap(r, c), swap(mr, mc);
            int ur = r/2, lr = (r-1)/2;
            bool tf = true;
            FOR(i, ur+1, r) {
                if(r-i-1 <= lr) break;
                if((i*c-ur)%x == 0 && ((r-i-1)*c-lr)%x == 0) tf = false;
            }
            flag = tf;
        }
    }
    if(flag) PS("RICHARD");
    else PS("GABRIEL");
    PN;
}

void solve1() {
    int x, r, c;
    SDDD(x, r, c);
    if(r < c) swap(r, c);
    bool flag = false;
    if(x >= 7 || x > 2*c || r*c % x || x >= r+c || x > r) flag = true;
    else if(x == 4) {
        if(c < 3) flag = true;
        else flag = false;
    }
    if(flag) PS("RICHARD");
    else PS("GABRIEL");
    PN;
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
        //solve1();
    }
    #ifdef raaja
        }
    #endif
}
