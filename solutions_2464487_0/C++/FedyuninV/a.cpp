#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unsigned long long l, r, t, m;
    cin >> m;
    forn (test, m) {
        cin >> r >> t;
        unsigned long long left = 1, right = min((unsigned long long)(1000000000), (1L << 63) / r);
        unsigned long long mid;
        unsigned long long temp;
        while (left != right) {
            mid = (left + right + 1) / 2;
            temp = (2 * r + 1) * mid + 2 * (mid - 1) * mid;
            if (temp <= t) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        cout << "Case #" << test + 1 << ": " << left << endl;
    }
	return 0;
}
