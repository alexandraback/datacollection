#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <memory.h>
using namespace std;

typedef long long LL;

LL N;

LL reverse(LL x) {
    LL result = 0;
    for (; x; x /= 10)
        result = result * 10 + x % 10;
    return result;
}

vector<char> used(100000000);

LL solve() {
    cin >> N;
    if (N == 1)
        return 1;
    memset(&used[0], 0, used.size() * sizeof(used[0]));

    queue< pair<LL, LL> > q;
    q.push(make_pair(1LL, 1));
    used[1] = true;

    while (!q.empty()) {
        pair<LL, LL> p = q.front(); q.pop();
        if (p.first == N)
            return p.second;

        LL new_num = p.first + 1;
        if (!used[new_num]) {
            used[new_num] = true;
            q.push(make_pair(new_num, p.second + 1));
        }

        new_num = reverse(p.first);
        if (!used[new_num]) {
            used[new_num] = true;
            q.push(make_pair(new_num, p.second + 1));
        }
    }

    throw exception();
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

