#include <iostream>

using namespace std;

int digits(int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    return 9; // :p
}
int p10(int n) {
    switch (n) {
        case 0: return 1;
        case 1: return 10;
        case 2: return 100;
        case 3: return 1000;
        case 4: return 10000;
        case 5: return 100000;
        case 6: return 1000000;
        case 7: return 10000000;
        case 8: return 100000000;
        case 9: return 1000000000;
        default: return 0;
    }
}

int rotate(int n, int d) {
    int D = p10(d-1);
    int top = n / D;
    return (n % D) * 10 + top;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        int A, B;
        cin >> A >> B;
        int total = 0;
        for (int j = A+1; j <= B; ++j) {
            // find new pairs between A and j
            // aka find new (n, j) >= A
            int d = digits(j);
            int m = j;
            do {
                m = rotate(m, d);
                if (A <= m && m < j) {
                    ++total;
                }
            } while (m != j);
        }
        cout << total << endl;
    }
}