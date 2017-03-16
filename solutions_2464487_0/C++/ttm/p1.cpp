#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas;
    cin >> cas;
    for (int i = 0; i < cas; ++i) {
        int64_t r, t;
        cin >> r >> t;
        int rings = 0;
        while (((r + 1) * (r + 1) - r * r) <= t) {
            t -= ((r + 1) * (r + 1) - r * r);
            r += 2;
            rings += 1;
		}
		cout << "Case #" << (i + 1) << ": " << rings << "\n";
	}

    return 0;
}