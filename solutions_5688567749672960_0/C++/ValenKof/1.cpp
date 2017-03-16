#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

template<typename T> inline int sz(const T& x) { return (int) x.size(); }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }

vector<long long> buffer;

long long reverse_num(long long x) {
    buffer.clear();
    while (x) {
        buffer.pb(x % 10);
        x /= 10;
    }
    for (long long num : buffer) {
        x = x * 10 + num;
    }
    return x;
}

int solve() {
    long long n;
    cin >> n;
    unordered_set<long long> used;
    queue<pair<long long, int>> q;
    used.insert(1);
    q.push(mp(1, 1));
    long long max_num = 1;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        mx(max_num, top.first);
        if (top.first == n) {
            // debug(max_num);
            return top.second;
        }
        vector<long long> visit = {top.first + 1, reverse_num(top.first)};
        for (long long next : visit) {
            if (!used.count(next)) {
                used.insert(next);
                q.push({next, top.second + 1});
            }
        }
    }
    return - 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}