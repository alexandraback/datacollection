#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <utility>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <memory>
#include <sstream>
#include <cctype>
#include <unistd.h>
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define RREP(i,e,n) for(int i=(int)n-1;i>=(int)(e);--i)
#define rrep(i,n) RREP(i,0,n)
#define foreach(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;


void solve(){
    int a, b;
    cin >> a >> b;
    vector<double> ps;
    rep(i, a){
        double x;
        cin >> x;
        ps.pb(x);
    }
    double res = b+2;
    double prob = 1;
    rep(i, a + 1){
        int bs = a - i;
        double tmp = 2.0 * bs + b - a + 1;
        tmp += (1 - prob) * (b + 1);
        res = min(tmp, res);

        prob *= ps[i];
    }
    cout << res << endl;
}
int main(void){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
