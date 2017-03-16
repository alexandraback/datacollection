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

int currMin = INF;

int solve(int A, VI &osm, int i, int curr) {
    if(i >= osm.size()) {
        currMin = min(currMin, curr);
        return 0;
    }

    if(curr >= currMin)
        return INF;

    if(A > osm[i]) {
        A += osm[i];
        return solve(A, osm, i+1, curr);
    } else {
        int del = solve(A, osm, i+1, curr+1)+1;

        int add = 0;
        while(A <= osm[i] && A != 1) {
            A *= 2;
            add++;
            A--;
        }
        if(A > osm[i]) {
            A += osm[i];
            add += solve(A, osm, i+1, curr+add);
            return min(add, del);
        } else {
            return del;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;

    REP(t, T) {
        currMin = INF;

        int A, N;
        cin >> A >> N;

        VI osm(N, 0);
        REP(i, N) {
            cin >> osm[i];
        }

        SORT(osm);

        printf("Case #%d: %d\n", (t+1), solve(A, osm, 0, 0));
    }

    return 0;
}

#endif // STDAFX_H

