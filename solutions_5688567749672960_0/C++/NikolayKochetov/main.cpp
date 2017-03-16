#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define size_t long long

size_t rev(size_t val) {
    size_t ans = 0;
    while (val) {
        ans = 10 * ans + val % 10;
        val /= 10;
    }
    return ans;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    out.sync_with_stdio(false);
    int t;
    in >> t;
    for (int qqqqqq = 0; qqqqqq < t; qqqqqq++) {
        size_t n;
        in >> n;
        queue<pair<size_t, size_t>> q;
        q.push(make_pair(n, 1));
        map<size_t, size_t> m;
        m[n] = 1;
        while (!q.empty()) {
            size_t val = q.front().first;
            size_t l = q.front().second;
            q.pop();
            if (val == 1) {
                m[1] = min(m[1], l);
            } else {
                size_t val2;
                size_t ll;
                if (val % 10 == 1) {
                    val2 = val - 10;
                    ll = l + 10;
                }
                else if (val % 10 == 0) {
                    val2 = val - 9;
                    ll = l + 9;
                }
                else {
                    val2 = val - (val % 10) + 1;
                    ll = l + (val % 10) - 1;
                }
                if (m[val2] == 0 || m[val2] > ll) {
                    m[val2] = ll;
                    q.push(make_pair(val2, ll));
                }
                val2 = rev(val);
                if (val % 10 && m[val2] == 0 || m[val2] > l + 1) {
                    m[val2] = l + 1;
                    q.push(make_pair(val2, l + 1));
                }
            }
        }
        out << "Case #" << qqqqqq + 1 << ": " << m[1] << '\n';
    }
    return 0;
}