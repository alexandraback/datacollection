// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

long long solve() {
    long long E, R;
    int N;
    cin >> E >> R >> N;
    vector<long long> V(N);
    for (auto &v : V) cin >> v;

    long long answer = 0;
    deque<long long> amount, gain;
    amount.push_back( E );
    gain.push_back( V[0] );

    for (int n=1; n<N; ++n) {
        // zober energiu ktoru uz nebudu moct pouzit
        long long take = R;
        while (take > 0) {
            if (amount.front() > take) {
                answer += gain.front() * take;
                amount.front() -= take;
                take = 0;
            } else {
                answer += gain.front() * amount.front();
                take -= amount.front();
                amount.pop_front();
                gain.pop_front();
            }
        }
        // pridaj novu energiu
        long long add = R;
        while (!gain.empty() && gain.back() <= V[n]) {
            add += amount.back();
            amount.pop_back();
            gain.pop_back();
        }
        amount.push_back(add);
        gain.push_back(V[n]);
    }
    while (!gain.empty()) {
        answer += amount.front() * gain.front();
        amount.pop_front();
        gain.pop_front();
    }
    return answer;
}

int main() {
    int T; cin >> T;
    for (int t=1; t<=T; ++t) cout << "Case #" << t << ": " << solve() << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
