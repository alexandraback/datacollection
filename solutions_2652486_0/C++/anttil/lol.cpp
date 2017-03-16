#include <iostream>

using namespace std;

int t;
int n[10];

int main() {
    cin >> t >> t >> t >> t >> t;
    cout << "Case #1:\n";
    for (int i = 0; i < 100; i++) {
        int m2 = 0, m3 = 0, m5 = 0;
        for (int j = 0; j < 7; j++) {
            cin >> n[j];
            for (int a = 3; a <= 5; a++)
            for (int b = a; b <= 5; b++)
            for (int c = b; c <= 5; c++)
            if (n[j] == a*b*c) {
                cout << a << b << c << "\n";
                goto uusi;
            }
            if (n[j]%2 == 0 && m2 < 1) m2 = 1;
            if (n[j]%4 == 0 && m2 < 2) m2 = 2;
            if (n[j]%8 == 0 && m2 < 3) m2 = 3;
            if (n[j]%16 == 0 && m2 < 4) m2 = 4;
            if (n[j]%32 == 0 && m2 < 5) m2 = 5;
            if (n[j]%3 == 0 && m3 < 1) m3 = 1;
            if (n[j]%9 == 0 && m3 < 2) m3 = 2;
            if (n[j]%5 == 0 && m5 < 1) m5 = 1;
            if (n[j]%25 == 0 && m5 < 2) m5 = 2;
        }
        if (m2 == 5) {cout << "442\n"; goto uusi; }
        if (m3 == 2) {
            if (m5 == 1) {cout << "335\n"; goto uusi; }
            if (m2 == 2) {cout << "334\n"; goto uusi; }
            cout << "332\n"; goto uusi;
        }
        if (m5 == 2) {
            if (m3 == 1) {cout << "553\n"; goto uusi; }
            if (m2 == 2) {cout << "554\n"; goto uusi; }
            cout << "552\n"; goto uusi;
        }
        if (m3 == 1 && m5 == 1 && m2 == 2) {cout << "435\n"; goto uusi; }
        if (m3 == 1 && m5 == 1) {cout << "235\n"; goto uusi; }
        if (m3 == 1 && m2 == 4) {cout << "344\n"; goto uusi; }
        if (m3 == 1 && m2 == 3) {cout << "324\n"; goto uusi; }
        if (m3 == 1) {cout << "322\n"; goto uusi; }
        if (m5 == 1 && m2 == 4) {cout << "544\n"; goto uusi; }
        if (m5 == 1 && m2 == 3) {cout << "524\n"; goto uusi; }
        if (m5 == 1) {cout << "522\n"; goto uusi; }
        if (m2 == 4) {cout << "422\n"; goto uusi; }
        cout << "222\n";
        uusi: ;
    }
}
