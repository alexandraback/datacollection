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

int main() {
    #ifdef raaja
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int zz, qq = 0;
    scanf("%d ", &zz);
    double c, f, x, ans, t1, t2, cs;
    while(qq++ < zz) {
        cin>>c>>f>>x;
        ans = 0.0;
        cs = 2;
        while(x > 0) {
            t1 = c / cs;
            t2 = x / cs;
            if(t1+x/(cs+f) < t2) cs += f, ans += t1;
            else ans += t2, x = 0;
        }
        printf("Case #%d: %.7f\n", qq, ans);
    }
}
