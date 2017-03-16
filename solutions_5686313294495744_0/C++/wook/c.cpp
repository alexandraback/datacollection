#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

int T;
int n;
vector<string> x, y;
vector<int> a, b;
int D;

int cache[1 << 16];
int dp(int state)
{
    int &ans = cache[state];
    if(ans != -1) return ans;
    ans = 0;

    vector<bool> used_word_as_first(D);
    vector<bool> used_word_as_second(D);
    for(int i=0; i<n; ++i) if( state & (1<<i)) {
        used_word_as_first[a[i]] = true;
        used_word_as_second[b[i]] = true;
    }
    // pick unselected one
    for(int i=0; i<n; ++i) if( !(state & (1<<i)) ){
        int base = dp(state | (1<<i));

        // check if i is cheater
        if(used_word_as_first[a[i]] && used_word_as_second[b[i]])
            base ++;

        ans = max(ans, base);
    }
    return ans;
}

int go()
{
    // normalize
    map<string, int> dict;
    D = 0;

    a.clear(); b.clear();
    for(string &s : x) {
        if(dict.count(s) == 0) dict[s] = D++;
        //cout << s << "->" << dict[s] << endl;
        a.push_back(dict[s]);
    }
    for(string &s : y) {
        if(dict.count(s) == 0) dict[s] = D++;
        //cout << s << "->" << dict[s] << endl;
        b.push_back(dict[s]);
    }
    // for(int i=0; i<n; ++i) { printf("> %d %d\n", a[i], b[i]); }

    memset(cache, -1, sizeof cache);
    return dp(0);
}

int main() {
    cin >> T;
    for(int kase = 1; kase <= T; ++ kase)
    {
        cin >> n;
        x.resize(n);
        y.resize(n);
        for(int i=0; i<n; ++i) {
            cin >> x[i] >> y[i];
        }
        printf("Case #%d: %d\n", kase, go());
    }
    return 0;
}

