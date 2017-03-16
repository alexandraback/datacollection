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
        int c, d, v;
        cin >> c >> d >> v;
        vector <int> a(d+1);
        for (int i = 0; i < d; i++)
            cin >> a[i];
        a[d] = -1;
        int next = 1, sol = 0;
        for (int i = 0; next <= v; i++) {
            if(i < d && a[i] <= next) {
                next += a[i];
            }
            else {
                sol += 1;
                next *= 2;
                i--;
            }
        }
        cout << sol << endl;
    }
    return 0;
}