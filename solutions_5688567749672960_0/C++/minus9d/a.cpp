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

int rev(int a) {
    string s = to_string(a);
    reverse(ALL(s));
    return stoi(s);
}

int solve__(int n)
{
    if (n < 10) {
        return n;
    }
    if (n % 10 == 1) {
        int res = 1;
        n /= 10;

    }

    return 777;
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    const int mx = 1000000;
    vector<int> res(mx+1, 0);
    queue<pair<int, int>> q;
    q.push(mp(1,1));
    while (!q.empty()) {
        auto p = q.front(); q.pop();

        auto n = p.first;
        auto cnt = p.second;

        if (n > mx) continue;
        if (res[n] != 0) continue;
    
        res[n] = cnt;

        // add 1
        if (n + 1 <= mx && res[n + 1] == 0) {
            q.push(mp(n + 1, cnt + 1));
        }
        int rev_n = rev(n);
        if (rev_n <= mx && res[rev_n] == 0) {
            q.push(mp(rev_n, cnt + 1));
        }
    }
    
    for (int test = 0; test < TEST_NUM; ++test){
        int N;
        cin >> N;

        cout << "Case #" << (test + 1) << ": ";
        cout << res[N];
        cout << endl;
    }

    return 0;
}

