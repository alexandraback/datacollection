#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

uint64_t r, t;

bool test(uint64_t s) {
    if ((((2 * (r + s) - 1) * s) / s + 1) / 2 - r != s) return false;
    return ((2 * (r + s) - 1) * s <= t);
}

uint64_t binary(uint64_t lower, uint64_t upper) {
    uint64_t s = lower + (upper - lower) / 2;
    if (lower == s) return lower;
    if (test(s)) {
        if (!test(s + 1)) { return s; }
		return binary(s, upper);
	} else return binary(lower, s);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas;
    cin >> cas;
    for (int i = 0; i < cas; ++i) {
        cin >> r >> t;
        uint64_t res = binary(0, UINT64_MAX);
		cout << "Case #" << (i + 1) << ": " << res << "\n";
	}

    return 0;
}