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

bool palindrome(int x) {
    int z = x;
    int y = 0;
    while (z) {
        y = y * 10 + z % 10;
        z /= 10;
    }
    return x == y;
}

int solve() {
    int a, b;
    cin >> a >> b;
    int ret = 0;
    for (int i = a; i <= b; i++) {
        int s = sqrt(i) + 0.5;
        if (s*s == i && palindrome(i) && palindrome(s))
            ++ret;
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    REP (i, T) {
        printf("Case #%d: %d\n", i+1, solve());
    }
}
