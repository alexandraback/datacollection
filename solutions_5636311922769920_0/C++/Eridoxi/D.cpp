#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

ul K, C, S;

ul ipow(ul base, ul exp)
{
    ul result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }

    return result;
}

ul compute_pos(ul cpx) {
    ul result = 0;
    ul bs = 1;

    if (cpx == 1) return 0;

    for (ul i = 0; i < cpx - 1; ++i) {
        result += (cpx - i - 1) * bs;
        bs *= K;
    }
    return result;
}

ul compute_shift(ul shift, ul C) {
    ul result = 0;
    ul bs = 1;

    for (ul i=0; i < C; ++i) {
        result += (C) * bs;
        bs *= K;
    }
    
    return shift * result;
}

void solve(ul shift) {
    ul rem = K; // remaining values with no info
    ul sh = 0;

    while (rem > 0) {
        if (rem >= C) {
            cout << " " << (1 + compute_pos(C) + compute_shift(sh++, C));
            rem -= C;
        } else {
            ul target_pos = compute_pos(rem);
            target_pos = ipow(K, C - rem) * target_pos;
            target_pos += compute_shift(sh++, C);
            cout << " " << ++target_pos;
            rem = 0;
        }
    }
}


int main() {
    long long numcase;

    //freopen("exD", "r", stdin);
    //freopen("resD", "w", stdout);
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small.out", "w", stdout);
    //freopen("D-large.in", "r", stdin);
    //freopen("D-large.out", "w", stdout);

    cin >> numcase;
    for (long long i = 0; i < numcase; ++i) {
        cin >> K >> C >> S;
        cout << "Case #" << i + 1 << ":";
        
        if (K > S*C) {
            cout << " IMPOSSIBLE";
        } else {
            solve(0);
        }
        cout << endl;
    }

    return 0;
}
