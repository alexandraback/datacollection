#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int CASETIME;
    cin >> CASETIME;
    vector<int> s;
    vector<int> s_ori;
    int sums;

    int n;
    int t;

    for (int casetime = 1; casetime <= CASETIME; casetime++) {
        cin >> n;
        sums = 0;
        s.clear();
        s_ori.clear();
        for (int i = 0; i < n; i++) {
            cin >> t;
            s.push_back(t);
            s_ori.push_back(t);
            sums += t;
        }

        sort(s.begin(), s.end());

        int water = sums;
        int waterneeded;
        double level = -1;
        for (int i = 1; i < n; i++) {
            int height = s[i] - s[i-1];
            waterneeded = height * i;
            if (water > waterneeded) {
                water -= waterneeded;
                continue;
            } else {
                level = double(water) / i + s[i - 1];
                break;
            }
        }
        if (level < -0.5) {
            level = double(water) / n + s[n - 1];
        }

        cout << "Case #" << casetime << ":";
        for (int i = 0; i < n; i++) {
            cout << ' ' << setprecision(10) << ((level - s_ori[i]) > 0 ? (level - s_ori[i])/sums*100 : 0);
        }
        cout << endl;
    }

    return 0;
}

