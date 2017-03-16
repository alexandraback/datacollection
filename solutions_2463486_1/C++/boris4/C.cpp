#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int tests;
vector<long long> p;

bool palin(long long x) {
    int d[15];
    int k = 0;
    while (x > 0) {
        d[k++] = (x % 10LL);
        x /= 10LL;
    }
    for (int i = 0; i + i < k; ++i)
        if (d[i] != d[k - 1 - i])
            return false;
    return true;
}

int main() {
    cin >> tests;
    p.clear();
    for (long long i = 1; i <= 10000000; ++i) {
        if (palin(i) && palin(i * i)) {
            p.push_back(i * i);
        }
    }
    int size = p.size();
    for (int test_id = 1; test_id <= tests; ++test_id) {
        long long a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (p[i] >= a && p[i] <= b) {
                ++cnt;
            }
        }
        cout << "Case #" << test_id << ": " << cnt << endl;
    }
    return 0;
}
