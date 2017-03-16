#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("D-small-attempt0.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, k, c, s;
    cin >> testcases;
    for (int id = 1; id <= testcases; id++) {
        cin >> k >> c >> s;
        long long a[101];
        long long now = 1;
        int chang = s;
        for (int i = 0; i < s; i++) {
            a[i] = 1;
            long long ji = 1;
            if (now > k) continue;
            for (long long j = 0; j < c; j++) {
                if (now > k) {
                    chang = i + 1;
                    break;
                }
                a[i] += (now - 1) * ji;
                ji *= k;
                now++;
            }
        }
        cout << "Case #" << id << ":";
        if (now <= k) {
            cout << " IMPOSSIBLE" << endl;
        } else {

            for (int j = 0; j < chang; j++) {
                if (j > 0 && (a[j] == a[j-1] || a[j] == a[0])) break;
                cout << " " << a[j];

            }
            cout << endl;
        }
    }

}
