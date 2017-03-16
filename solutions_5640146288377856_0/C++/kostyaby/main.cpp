#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 22;

int r, c, w;
int f[MAXN];

int solve(int testcase) {
    cin >> r >> c >> w;
    for (int i = 0; i < w; i++) {
        f[i] = 0;
    }
    f[w] = w;
    for (int i = w + 1; i <= c; i++) {
        f[i] = r * c;
        for (int j = 1; j <= i; j++) {
            int left = j - 1;
            int right = i - j;
            if (max(left, right) >= w) {
                f[i] = min(f[i], f[left] + f[right] + 1);
            } else {
                f[i] = w + 1;
            }
        }
    }
    return f[c];
}

int main() {
	int cases; cin >> cases;
	for (int i = 0; i < cases; i++) {
        cout << "Case #" << i + 1 << ": " << solve(i + 1) << "\n";
    }
    return 0;
}