#include <bits/stdc++.h>

using namespace std;
int n;
string stringsA[20];
string stringsB[20];

set<string> usedA;
set<string> usedB;
int main() {
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> stringsA[i] >> stringsB[i];
        }
        int max = -1;
        for (int i = 0; i < (1 << n); i++) {
            bitset<20> bits(i);
            usedA.clear();
            usedB.clear();
            for (int j = 0; j < n; j++) {
                if (bits[j] == 0) {
                    usedA.insert(stringsA[j]);
                    usedB.insert(stringsB[j]);
                    // cout << stringsA[j] << " " << stringsB[j] << endl;
                }
            }
            bool works = true;
            for (int j = 0; j < n; j++) {
                if (bits[j] == 1) {
                    if (usedA.count(stringsA[j]) == 0 || usedB.count(stringsB[j]) == 0) {
                        works = false;
                        break;
                    }
                }
            }
            // cout << bits << " " << bits.count() << " " << works << endl;
            if ((int)bits.count() > max && works) {
                max = bits.count();
            }
        }
        cout << "Case #" << t << ": " << max << endl;
    }   
}