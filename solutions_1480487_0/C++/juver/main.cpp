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
        int n;
        cin >> n;

        VI points(n);
        FOR (i, n) cin >> points[i];

        int const allPoints = accumulate(ALL(points), 0);
        vector<double> res(n);
        
        FOR (i, n) {
            double l = 0, r = 1.0;
            FOR (iters, 100) {
                double const m = (l + r) / 2;
                double const curPoints = points[i] + allPoints * m;
                double remPoints = (1 - m) * allPoints;

                VI otherPoints = points;
                otherPoints.erase(otherPoints.begin() + i);

                bool ok = true;
                sort(ALL(otherPoints));
                FOR (j, SIZE(otherPoints)) {
                    double const needAudience = max(0.0, curPoints - otherPoints[j]);
                    if (needAudience > remPoints) {
                        ok = false;
                        break;
                    }

                    remPoints -= needAudience;
                }

                if (!ok) r = m;
                else l = m;
            }

            res[i] = l;
        }

        printf("Case #%d:", tt + 1);
        FOR (i, n) printf(" %.6lf", res[i] * 100);
        printf("\n");
        
    }
    
    return 0;
}