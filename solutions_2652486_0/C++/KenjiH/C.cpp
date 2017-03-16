#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

int T, R;
int N, M, K;

int toInt(vector<int> v) {
    int ret = 0;
    REP (i, v.size())
        ret = 10 * ret + v[i];
    return ret;
}

bool check(vector<int> x, vector<int> y) {
    REP (i, y.size()) {
        int ret = 1;
        REP (j, x.size())
            if (rand() % 2)
                ret *= x[j];
        if (ret != y[i])
            return false;
    }
    return true;
}

void solve() {
    vector<int> x(K);
    REP (i, K)
        cin >> x[i];
    
    vector<int> y(N);
    map<int, int> guess;
    REP (i, 5000000) {
        REP (j, N)
            y[j] = rand() % (M - 1) + 2;
        sort(y.begin(), y.end());

        if (check(y, x))
            guess[toInt(y)]++;
    }

    int ret = -1;
    EACH (itr, guess) {
        if (ret == -1)
            ret = itr->first;
        else if (itr->second > guess[ret])
            ret = itr->first;
    }
    
    if (ret == -1) {
        vector<int> dummy(N, 2);
        ret = toInt(dummy);
    }

    cout << ret << endl;
}

int main() {
    cin >> T >> R;
    cin >> N >> M >> K;

    cout << "Case #1:" << endl;
    REP (i, R) {
        cerr << "case = " << i << endl;
        solve();
    }

    return 0;
}
