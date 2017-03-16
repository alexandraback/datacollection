#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <functional>
#include <bitset>

using namespace std;

long long reversed(long long num) {
    long long res = 0;
    while (num) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }

    return res;
}

void printans(int test, int ans) {
    cout << "Case #" << test << ": " << ans << endl;
}



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cases;
    cin >> cases;

    for (int test = 1; test <= cases; test++) {
        int r, c, w;
        cin >> r >> c >> w;

        int ans = 0;

        ans = r * (c / w) + w - 1;
        if (c % w != 0)
            ans += r;

        cout << "Case #" << test << ": " << ans << endl;
    }
}
