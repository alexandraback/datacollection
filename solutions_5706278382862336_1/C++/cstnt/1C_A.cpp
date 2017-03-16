#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
typedef pair<int, int> PII;

#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define FILLCHAR(a, x) memset(a, x, sizeof(a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()

LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}


LL run() {
    LL P, Q;
    string input;
    cin >> input;
    int pos = find(ALL(input), '/') - input.begin();
    istringstream iss1(input.substr(0, pos));
    istringstream iss2(input.substr(pos + 1));
    iss1 >> P;
    iss2 >> Q;

    LL g = gcd(P, Q);

    P /= g;
    Q /= g;

    if ((1LL << 40) % Q != 0) return -1;

    P *= (1LL << 40) / Q;

    int maxP = -1;
    FOR(k,1,41) {
        if (P < (1LL << k)) {
            maxP = k - 1;
            break;
        }
    }

    return 40 - maxP;
}
int main() {
    int t;
    cin >> t;
    REP(i,t) {
        LL ret = run();
        if (ret == -1) {
            cout << "Case #" << i + 1 << ": " << "impossible" << endl;
        } else {
            cout << "Case #" << i + 1 << ": " << ret << endl;
        }
    }
}
