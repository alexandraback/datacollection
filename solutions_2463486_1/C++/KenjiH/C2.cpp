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

vector<long long> v;

inline bool palindrome(long long x) {
    long long z = x;
    long long y = 0;
    while (z) {
        y = y * 10 + z % 10;
        z /= 10;
    }
    return x == y;
}

void init() {
    long long x = 1;
    while (x*x <= 100000000000000) {
        if (palindrome(x) && palindrome(x*x)) {
            v.push_back(x*x);
            //cout << x*x << endl;
        }
        x++;
    }
}

int solve() {
    long long a, b;
    cin >> a >> b;

    int ret = 0;
    REP (i, v.size())
        if (a <= v[i] && v[i] <= b)
            ++ret;
    return ret;
}

int main() {
    init();

    int T;
    cin >> T;
    REP (i, T) {
        printf("Case #%d: %d\n", i+1, solve());
    }
}
