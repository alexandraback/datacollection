
#ifndef STDAFX_H
#define STDAFX_H

#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<string> VS;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<VD>     VVD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

const double EPS = 10e-9;
const double PI = acos(-1.0);
const LL INF = (1LL << 30);

using namespace std;

template<typename T>
string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

map<int, string> dir[2];

int sign(int x) {
    if(x > 0)
        return 1;
    else if(x < 0)
        return -1;
    else
        return 0;
}

string go(int X, int Y, int XX, int YY) {
    if(XX != X) {
        string mv = dir[0][sign(X-XX)];
        return mv+go(X, Y, XX+sign(X-XX), YY);
    }
    if(YY != Y) {
        string mv = dir[1][sign(Y-YY)];
        return mv+go(X, Y, XX, YY+sign(Y-YY));
    }
    return "";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    dir[0] = {{1, "WE"}, {-1, "EW"}};
    dir[1] = {{1, "SN"}, {-1, "NS"}};

    int T;
    cin >> T;
    REP(t, T) {
        int X, Y;
        cin >> X >> Y;

        string res = "";
        int XX = 0, YY = 0;
        res = res+go(X, Y, XX, YY);
        assert(res.size() < 500);
        printf("Case #%d: %s\n", (t+1), res.c_str());
    }

    return 0;
}

#endif // STDAFX_H
