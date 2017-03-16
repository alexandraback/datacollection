#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () {
    int t, k, c, s;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        cin >> k >> c >> s;
        cout << "Case #" << j << ":";
        for (int i = 1; i <= k; i++) {
            cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}
