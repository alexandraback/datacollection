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
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RREP(i,n) RFOR(i,n-1,0)
#define ECH(it, v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define MKP make_pair
#define MOD 1000000007
typedef long long LL;
typedef unsigned long long uLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

int n, n1, t1, t2, ind;
double a1[1000], a2[1000], tt;

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int zz, qq = 0;
    scanf("%d ", &zz);
    while(qq++ < zz) {
        scanf("%d ", &n);
        n1 = n, t1 = t2 = 0;
        REP(i, n) scanf("%lf ", &a1[i]);
        REP(i, n) scanf("%lf ", &a2[i]);
        sort(a1, a1+n);
        while(n--) {
            tt = 15;
            ind = -1;
            REP(i, n+1) if(a2[i] > a1[n] && a2[i] < tt) tt = a2[i], ind = i;
            if(ind == -1) REP(i, n+1) if(a2[i] < tt) tt = a2[i], ind = i;
            swap(a2[ind], a2[n]);
            if(a1[n] > a2[n]) t1++;
        }
        n = n1;
        sort(a2, a2+n);
        //reverse(a1, a1+n);
        //reverse(a2, a2+n);
        while(n--) {
            ind = -1;
            tt = 0;
            REP(i, n+1) if(a1[i]>tt) tt = a1[i], ind = i;
            if(a1[ind] > a2[n]) {
                t2++;
                swap(a1[ind], a1[n]);
            } else {
                ind = -1;
                tt = 15;
                REP(i, n+1) if(a1[i]<tt) tt = a1[i], ind = i;
                swap(a1[ind], a1[n]);
            }
        }
        printf("Case #%d: %d %d\n", qq, t2, t1);
    }
}
