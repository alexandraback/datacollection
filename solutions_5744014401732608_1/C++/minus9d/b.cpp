#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <complex>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

void solve(void)
{
    ll B, M;
    cin >> B >> M;

    ll B2 = B-2;
    ll poss_mx = 1;
    while (B2) {
        poss_mx *= 2;
        --B2;
    }

    if (M > poss_mx) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE" << endl;

    if (M <= B - 1) {
        REP(b, B) {
            string s(B, '0');
            if (M > 0) {
                s[B - 1] = '1';
                --M;
            } 
            if (M > 0) {
                s[b + 1] = '1';
            }
            cout << s << endl;
        }
        return;
    }

    ll curr = 0;
    vector<ll> table(B + 1);
    vector<vector<int>> slides(B + 1, vector<int>(B + 1));

    FOR(b, 1, B) {
        slides[b][b + 1] = 1;
        slides[b][B] = 1;
    }

    B2 = B - 1;
    while (B2 >= 1) {
        ++curr;
        FOR(i, B2 + 2, B) {
            // if add
            ll curr2 = curr + table[i];
            curr2 += (B2 - 1);

            if (curr2 <= M) {
                slides[B2][i] = 1;
                curr += table[i];
            }
        }
        table[B2] = curr;
        --B2;
    }

    FOR(b1, 1, B + 1) {
        FOR(b2, 1, B + 1) {
            cout << slides[b1][b2];
        }
        cout << endl;
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test+1) << ": ";
        solve();
    }

    return 0;
}
