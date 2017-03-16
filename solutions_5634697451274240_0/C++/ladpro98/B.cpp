#include <bits/stdc++.h>

using namespace std;

const int N = 101;

map<string, int> d;

int n;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        bitset<N> s;
        bitset<N> dest;
        string str; cin >> str;
        n = str.size();
        for (int i = 0; i < n; ++i) if (str[i] == '-') s.set(i);
        queue<bitset<N> > Q;
        Q.push(s);
        d.clear();
        d[s.to_string()] = 0;
        while (!Q.empty() && !d.count(dest.to_string())) {
            bitset<N> u = Q.front(); Q.pop();
            bitset<N> x;
            for (int i = 0; i < n; ++i) {
                x.set(i);
                bitset<N> v = u ^ x;
                if (d.count(v.to_string())) continue;
                d[v.to_string()] = d[u.to_string()] + 1;
                Q.push(v);
            }
        }
        cout << "Case #" << it << ": " << d[dest.to_string()] << endl;
    }
    return 0;
}
