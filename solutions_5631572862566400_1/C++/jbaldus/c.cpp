
#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <cstdio>
#include <cstdint>
#include <cmath>

typedef long long ll;

using namespace std;

class union_find
{
public:
    union_find(int n): parent(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    void combine(int i, int j) {
        parent[find(i)] = find(j);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
private:
    vector<int> parent;
};

void solve(int)
{
    int n;
    cin >> n;
    vector<int> f(n);
    for (int& i: f) {
        cin >> i;
        --i;
    }

    union_find u(n);
    for (int i = 0; i < n; ++i) {
        u.combine(i, f[i]);
    }
    vector<int> c(n, -1);
    vector<vector<int>> components(n);
    for (int i = 0; i < n; ++i) {
        c[i] = u.find(i);
        components[c[i]].push_back(i);
    }

    size_t sum = 0, maximum = 0;
    for (const vector<int>& v: components) {
        if (!v.size()) continue;
        vector<char> in_circle(n, false);
        vector<int> circle;

        size_t m = 0;
        for (int start: v) {
            int next = start;
            do {
                next = f[next];
                circle.push_back(next);
            } while (next != start && circle.size() <= n);

            if (next == start) break;
            else circle.clear();
        }

        if (!circle.size()) continue;

        m = max(circle.size(), m);

        for (int i: circle) in_circle[i] = true;
        vector<size_t> x(n, 0);
        for (int i: v) {
            size_t s = 0, j = i;
            while (!in_circle[j]) {
                j = f[j];
                ++s;
            }
            x[j] = max(x[j], s);
        }

        if (circle.size() == 2) m = max(m, circle.size() + x[circle[0]] + x[circle[1]]);

        maximum = max(maximum, m);
        if (circle.size() == 2) sum += circle.size() + x[circle[0]] + x[circle[1]];
    }

    maximum = max(maximum, sum);
    cout << maximum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
