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

void solve(VI const& a, map<int, PII>& result, VI& res1, VI& res2) {
    int const n = SIZE(a);
    int const fullMask = (1 << n) - 1;
    VI sums(fullMask + 1);

    FOR (mask, fullMask + 1) {
        int sum = 0;
        FOR (i, n) if (mask & (1 << i))
            sum += a[i];
        
        sums[mask] = sum;
    }

    FOR (f, fullMask + 1) FOR (s, fullMask + 1) if ((f & s) == 0) {
       result[sums[f] - sums[s]] = MP(f, s);

       if (sums[f] == sums[s] && f && s) {
           FOR (i, n) {
               if (f & (1 << i))
                   res1.PB(a[i]);
               if (s & (1 << i))
                   res2.PB(a[i]);
           }

           return;
       }
    }
}

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    FOR (tt, t) {
        int n;
        cin >> n;

        VI a, b;
        FOR (i, n) {
            int value;
            cin >> value;
            if (i < n / 2)
                a.PB(value);
            else
                b.PB(value);
        }

        map<int, PII> first, second;
        VI res1, res2;
        
        solve(a, first, res1, res2);
        if (res1.empty() && res2.empty())
            solve(b, second, res1, res2);
        
        if (res1.empty() && res2.empty()) {
            for (map<int, PII>::const_iterator it = first.begin(); it != first.end(); ++it) {
                int const diff1  = it->first;
                map<int, PII>::const_iterator it2 = second.find(-diff1);
                if (it2 != second.end()) {
                   FOR (i, SIZE(a)) {
                       if (it->second.first & (1 << i))
                           res1.PB(a[i]);
                       if (it->second.second& (1 << i))
                           res2.PB(a[i]);
                   }
                   
                   FOR (i, SIZE(b)) {
                       if (it2->second.first & (1 << i))
                           res1.PB(b[i]);
                       if (it2->second.second& (1 << i))
                           res2.PB(b[i]);
                   }

                   break;
                }
            }
        }

        printf("Case #%d:\n", tt + 1);
        if (!res1.empty() && !res2.empty()) {
            FOR (i, SIZE(res1)) {
                if (i) printf(" ");
                printf("%d", res1[i]);
            }
            printf("\n");
            FOR (i, SIZE(res2)) {
                if (i) printf(" ");
                printf("%d", res2[i]);
            }
            printf("\n");
        } else {
            printf("Impossible\n");
        }
        
    }
    
    return 0;
}