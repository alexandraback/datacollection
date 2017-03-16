#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

typedef long long ll;

int N;

vector<int> d;
vector<int> m;
vector<pair<int, int>> p;

int solve() {
    int size = p.size();
    sort(p.begin(), p.end());
    cout << size << endl;
    if (size <= 1) {
        return 0;
    }
#if 1
    cout << p[0].first << endl;
    cout << p[0].second << endl;
    cout << p[1].first << endl;
    cout << p[1].second << endl;
#endif
    if (p[0].first != p[1].first) {
        if (p[1].second == p[0].second) {
            return 0;
        } else if (p[1].second < p[0].second) {
            double time = ((360 - p[0].first) / 360.0) * -p[0].second;
            if (p[1].first + (360.0 * (time / -p[1].second)) >= 360.0) {
                return 0;
            } else {
                return 1;
            }
        } else {
            double time = ((360 - p[0].first) / 360.0) * -p[0].second;
            if (p[1].first + (360.0 * (time / -p[1].second)) <= 720.0) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        double time = ((360 - p[0].first) / 360.0) * -p[0].second;
        if (p[1].first + (360.0 * (time / -p[1].second)) <= 720.0) {
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("C-small-1-attempt3.in");
    ofstream out("C-small-1-attempt3.out");
#else
    ifstream in("C-large.in");
    ofstream out("C-large.out");
#endif
    
    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> N;
        d.clear();
        m.clear();
        p.clear();
        for (int n = 0; n < N; n++) {
            int D;
            int H;
            int M;
            in >> D >> H >> M;
            for (int h = 0; h < H; h++) {
                d.push_back(D);
                m.push_back(M + h);
                p.push_back(make_pair(D, -(M + h)));
            }
        }
        int ret = solve();
        out << "Case #" << t + 1 << ": " << ret << endl;
        cout << "Case #" << t + 1 << ": " << ret << endl;
    }
    getchar();
    return 0;
}
