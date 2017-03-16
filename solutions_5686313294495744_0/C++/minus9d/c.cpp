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

bool ok(vector<pair<string, string>>& fakes, vector<pair<string, string>>& reals)
{
    for (auto& f : fakes) {
        auto f1 = f.first;
        auto f2 = f.second;

        bool f1exist = false;
        bool f2exist = false;

        for (auto& r : reals) {
            auto r1 = r.first;
            auto r2 = r.second;

//            if (f1 == r2 || f2 == r1) return false;

            if (r1 == f1) f1exist = true;
            if (r2 == f2) f2exist = true;
        }

        if (f1exist == false || f2exist == false) return false;
    }

    return true;
}

void solve(vector<pair<string, string>>& strs, int N)
{
    int ret = 0;
    REP(i, (1 << N)) {
        // bit 1 .. fake
        // bit 0 .. real
        vector<pair<string,string>> reals;
        vector<pair<string,string>> fakes;
        REP(j, N) {
            if (i & (1 << j)) {
                fakes.push_back(strs[j]);
            }
            else {
                reals.push_back(strs[j]);
            }
        }
        if (ok(fakes, reals)) {
            ret = max(ret, SIZE(fakes));
        }
    }
    cout << ret;
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test+1) << ": ";

        int N;
        cin >> N;

        vector<pair<string, string>> strs(N);
        REP(n, N) {
            string s1, s2;
            cin >> s1 >> s2;
            strs[n] = mp(s1, s2);
        }

        solve(strs, N);
        cout << endl;
    }

    return 0;
}
