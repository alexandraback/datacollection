#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <utility>
#include <string>

//#include <gmpxx.h>

using namespace std;

typedef long long ll;

int l[26], n[10];

void remove(int k, string number) {
    for (const char &c: number)
        l[c - 'A'] -= k;
}

int main() {
    int T;
    cin >> T;
    string s;
    for (int i = 0; i < T;) {
        memset(l, 0, sizeof(int) * 26);
        memset(n, 0, sizeof(int) * 10);
        cin >> s;
        for (const char &c: s)
            ++l[c - 'A'];
        s.clear();
        remove(n[0] = l['Z' - 'A'], "ZERO");
        remove(n[2] = l['W' - 'A'], "TWO");
        remove(n[8] = l['G' - 'A'], "EIGHT");
        remove(n[3] = l['T' - 'A'], "THREE");
        remove(n[6] = l['X' - 'A'], "SIX");
        remove(n[7] = l['S' - 'A'], "SEVEN");
        remove(n[5] = l['V' - 'A'], "FIVE");
        remove(n[9] = l['I' - 'A'], "NINE");
        remove(n[4] = l['R' - 'A'], "FOUR");
        remove(n[1] = l['O' - 'A'], "ONE");
        for (int k = 0; k < 26; ++k) {
            if (l[k]) throw "Error";
        }
        cout << "Case #" << (++i) << ": ";
        for (int k = 0; k < 10; ++k) {
            for (int m = n[k]; m--;)
                cout << ((char) ('0' + k));
        }
        cout << endl;
    }
    return 0;
}
