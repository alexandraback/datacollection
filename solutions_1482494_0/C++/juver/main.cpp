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

int cmp(PII const& a, PII const& b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    FOR (tt, t) {
        int n;
        cin >> n;

        vector<PII> stars(n);
        FOR (i, n) cin >> stars[i].first >> stars[i].second;

        sort(ALL(stars), &cmp);
        int res = 0;
        int acquired = 0;
        VI used(n);

        FOR (i, n) if (i == 0 || stars[i].first != stars[i - 1].first) {
            FOR (j, n) if (stars[j].first == stars[j].second && stars[j].first == stars[i].first)
                swap(stars[i], stars[j]);
        }

        FOR (i, n) {
            if (used[i]) continue;
            if (stars[i].first > res) {
                res = -1;
                break;
            }

            if (stars[i].first == stars[i].second) {
                acquired += 2;
                used[i] = 1;
                ++res;
            } else {
                ++acquired;
                ++res;
            }

            while (true) {
                bool ok = false;
                FOR (j, n) {
                    int delta = j > i ? 2 : 1;
                    if (!used[j] && stars[j].second <= acquired) {
                        ++res;
                        acquired += delta;
                        used[j] = 1;
                        ok = true;
                    }
                }
                if (!ok) break;
            }
        }

        if (count(ALL(used), 0) != 0)
            printf("Case #%d: Too bad\n", tt + 1);
        else
            printf("Case #%d: %d\n", tt + 1, res);
    }

    return 0;
}