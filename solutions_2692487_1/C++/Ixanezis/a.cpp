#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstring>

using namespace std;

long long s[1000011];
int n;

int main() {
    int t; cin >> t;
    for (int e=0; e<t; ++e) {
        long long curSize;
        cin >> curSize >> n;
        for (int i=0; i<n; i++)
            cin >> s[i];

        sort(s, s+n);

        int best = 100010101;
        int curAdd = 0;
        if (curSize == 1) {
            best = n;
            curAdd = n;
        }

        for (int i=curAdd; i<n; i++) {
            if (s[i] < curSize) {
                curSize += s[i];
                if (i == n-1) {
                    best = min(best, curAdd);
                }
            } else {
                best = min(best, n - i + curAdd);
                while (curSize <= s[i]) {
                    curSize += curSize - 1;
                    ++curAdd;
                }
                curSize += s[i];
            }
        }

        cout << "Case #" << e+1 << ": " << best << endl;
    }

    return 0;
}
