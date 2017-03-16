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
typedef pair<i64, i64> PII; 

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    FOR (tt, t) {
        double D;
        int n, A;

        cin >> D >> n >> A;

        vector<double> t(n), x(n);
        FOR (i, n) cin >> t[i] >> x[i];

        vector<double> a(A);
        FOR (i, A) cin >> a[i];

        printf("Case #%d:\n", tt + 1);
        FOR (i, A) {
            double carSpeed = (x[n - 1] - x[0]) / (t[n - 1] - t[0]);
            double tl = 1e-8, tr = max((D - x[0]) / carSpeed, sqrt(2 * D / a[i]));
            double res = 0;

            FOR (iters, 100) {
                double time = (tl + tr) / 2;

                double xcar = x[0] + carSpeed * time;
                double xmy = a[i] * time * time / 2;

                if (xmy > xcar + 1e-8) tr = time;
                else tl = time;
            }

            if (n == 1)
                tl = sqrt(2 * D / a[i]);
            res = tl;
            double xcar = x[0] + carSpeed * tl;
            if (xcar < D) {
                res += (D - xcar) / carSpeed;
            }

            printf("%.8lf\n", res);
        }
    }
    
    return 0;
}