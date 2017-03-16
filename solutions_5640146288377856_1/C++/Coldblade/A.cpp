#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cout << "Case #" << tc + 1<< ": ";
        int r, c, w;
        cin >> r >> c >> w;
        cout << (int(c/w) * (r-1) + int((c-1)/w) + w) << endl;
    }
    return 0;
}