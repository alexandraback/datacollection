#pragma comment(linker, "/STACK:16777216")

#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <ctime> 
#include <float.h> 

using namespace std; 

#define REP(i, from, to) for (int i = (from); i < (to); ++i) 
#define FOR(i, n) REP(i, 0, (n)) 
#define ALL(x) x.begin(), x.end() 
#define SIZE(x) (int)x.size() 
#define PB push_back 
#define MP make_pair 

typedef long long i64; 
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef vector<string> VS; 
typedef vector<VS> VVS; 
typedef pair<int, int> PII; 

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    FOR (tt, t) {
        int a, b;
        cin >> a >> b;

        vector<double> p(a);
        FOR (i, a) cin >> p[i];

        vector<double> partialPrefix(a + 1, 1);
        FOR (i, a) {
            partialPrefix[i + 1] = p[i];
            partialPrefix[i + 1] *= partialPrefix[i];
        }

        double allRight = 1;
        FOR (i, a) {
            allRight *= p[i];
        }

        double res = 0;
        /// Enter
        res = 1 + b + 1;
        /// Finish
        res = min(res,
             (b - a + 1) * allRight + // all right
            (b - a + 1 + b + 1) * (1 - allRight)); // wrong + retype
        ///
        REP (i, 1, a + 1) {
            int prefixLength = a - i;
            int remLength = b - prefixLength;

            double cur = 0;
            cur += (i + remLength + 1) * partialPrefix[prefixLength]; /// prefix right and remaining
            cur += (i + remLength + 1 + b + 1) * (1 - partialPrefix[prefixLength]);

            res = min(res, cur);
        }

        printf("Case #%d: %.8lf\n", tt + 1, res);
    }

    return 0;
}