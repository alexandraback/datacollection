#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long C, D, V;
vector<long long> ds;

long long solve() {
    long long next = 1;
    int used = 0;
    while (next <= V) {
        if (used >= ds.size() || ds[used] > next) {
            ds.insert(ds.begin() + used, next);
        }
        used++;
        long long sum = 0;
        for (int i = 0; i < used; i++) {
            sum += ds[i];
        }
        next = sum * C + 1;
    }

    return ds.size() - D;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> C >> D >> V;
        ds.clear();
        for (int i = 0; i < D; i++) {
            long long d;
            cin >> d;
            ds.push_back(d);
        }
        long long ans = solve();


        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
