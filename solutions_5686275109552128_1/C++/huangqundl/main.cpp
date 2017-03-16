#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> dist;

int split(int total, int d) {
    if (total%d == 0) {
        return total / d - 1;
    }
    else {
        return total / d;
    }
}

void solve() {
    dist.clear();

    int D = 0;
    int max = 0;

    cin >> D;
    for (int i=0; i<D; i++) {
        int tmp;
        cin >> tmp;
        dist[tmp]++;
        if (tmp > max) {
            max = tmp;
        }
    }

    int ret = max;
    for (int d=max; d>=1; d--) {
        int special = 0;
        unordered_map<int, int>::iterator it;
        for (it=dist.begin(); it!=dist.end(); it++) {
            special += split(it->first, d) * it->second;
        }
        if (special+d < ret) {
            ret = special + d;
        }
    }

    cout << ret << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
