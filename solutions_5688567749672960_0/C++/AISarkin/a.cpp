#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAX_V = 10000005;

int dist[MAX_V], q[MAX_V], size_q;

int rev(int x) {
    int ans = 0;

    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }

    return ans;
}

int main() {
    memset(dist, -1, sizeof(dist));

    dist[1] = 0;

    q[size_q++] = 1;

    for (int i = 0; i < size_q; i++) {
        int x = q[i];

        if (x + 1 < MAX_V && dist[x + 1] < 0) {
            dist[x + 1] = dist[x] + 1;
            q[size_q++] = x + 1;
        }

        if (rev(x) < MAX_V && dist[rev(x)] < 0) {
            dist[rev(x)] = dist[x] + 1;
            q[size_q++] = rev(x);
        }
    }

    int tests;

    cin >> tests;

    for (int test_id = 1; test_id <= tests; test_id++) {
        int x;

        cin >> x;

        cout << "Case #" << test_id << ": " << dist[x] + 1 << endl;
    }

    return 0;
}
