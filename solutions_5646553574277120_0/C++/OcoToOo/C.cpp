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

typedef long long LL;
typedef pair<int, int> PII;

#define INF INT_MAX
#define LL_INF LLONG_MAX

int C;
int D;
int V;

vector<int> v;

bool dfs(int index, int goal, int now) {
    if (index == v.size()) {
        if (now == goal) {
            return true;
        } else {
            return false;
        }
    }
    if (now > goal) {
        return false;
    }
    if (dfs(index + 1, goal, now + v[index])) {
        return true;
    }
    if (dfs(index + 1, goal, now)) {
        return true;
    }
    return false;
}

int solve() {
    for (int i = 1; i <= V; i++) {
        if (!dfs(0, i, 0)) {
            v.push_back(i);
            sort(v.begin(), v.end());
        }
    }
    return v.size() - D;
}

//#define SAMPLE
//#define LARGE

int main() {

#ifdef SAMPLE
    ifstream in("C-sample.in");
    ofstream out("C-sample.out");
#else
#ifndef LARGE
    ifstream in("C-small-attempt0.in");
    ofstream out("C-small-attempt0.out");
#else
    ifstream in("C-large.in");
    ofstream out("C-large.out");
#endif
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> C >> D >> V;
        v.clear();
        for (int d = 0; d < D; d++) {
            int n; in >> n;
            v.push_back(n);
        }
        int ret = solve();
        out << "Case #" << t + 1 << ": " << ret << endl;
    }
    return 0;
}
