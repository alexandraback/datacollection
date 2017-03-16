#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>



using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }



void Solution() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    set<vector<int>> was;
    multiset<pair<int, int>> f01, f02, f12, c01, c02, c12;
    vector<vector<int>> all;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int q = 0; q < c; ++q) {
                vector<int> v = {i, j, q};
                all.push_back(v);
            }
        }
    }
    const int iter = 1000;
    for (int i = 0; i < a; ++i) {
        vector<pair<int, int>> cand;
        for (int j = 0; j < b; ++j) {
            for (int q = 0; q < c; ++q) {
                int mx = 0;
                mx = max<int>(mx, f01.count(make_pair(i, j)));
                mx = max<int>(mx, f02.count(make_pair(i, q)));
                mx = max<int>(mx, f12.count(make_pair(j, q)));
                if (mx < k) {
                    cand.push_back(make_pair(j, q));
                }
            }
        }
        vector<vector<int>> best;
        for (int it = 0; it < iter; ++it) {
            vector<vector<int>> cur;
            random_shuffle(cand.begin(), cand.end());
            c01 = f01;
            c02 = f02;
            c12 = f12;
            for (const auto& bb : cand) {
                int j = bb.first;
                int q = bb.second;
                int mx = 0;
                mx = max<int>(mx, c01.count(make_pair(i, j)));
                mx = max<int>(mx, c02.count(make_pair(i, q)));
                mx = max<int>(mx, c12.count(make_pair(j, q)));
                if (mx < k) {
                    vector<int> v = {i, j, q};
                    cur.push_back(v);
                    c01.insert(make_pair(i, j));
                    c02.insert(make_pair(i, q));
                    c12.insert(make_pair(j, q));
                }
            }
            if (cur.size() > best.size()) {
                best = cur;
            }
        }
        for (const auto& v : best) {
            was.insert(v);
            f01.insert(make_pair(v[0], v[1]));
            f02.insert(make_pair(v[0], v[2]));
            f12.insert(make_pair(v[1], v[2]));
        }
    }
    cout << was.size() << endl;
    for (const auto& v : was) {
        cout << v[0] + 1 << ' ' << v[1] + 1 << ' ' << v[2] + 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
        cerr << "Case #" << i + 1 << ": Done!" << endl;
    }

    return 0;
}


