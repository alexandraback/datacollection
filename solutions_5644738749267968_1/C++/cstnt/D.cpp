#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef long long LL;

int DoWar(vector<double> a, vector<double> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int pos = 0;
    int ret = 0;
    for (int i = 0; i < a.size(); i++) {
        while (pos < b.size() && b[pos] <= a[i]) pos++;

        if (pos < b.size()) {
            pos++;
        } else {
            ret++;
        }
    }

    return ret;
}

void solve() {
    int N;
    cin >> N;

    vector<double> a, b;
    for (int i = 0; i < N; i++) {
        double tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        double tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    cout << N - DoWar(b, a) << " " << DoWar(a, b) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

