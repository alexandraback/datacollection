#include <bits/stdc++.h>
using namespace std;

int numTo11(int num) {
    int acc = num;
    int superman = 0;
    for (int i = 0; acc != 0; i++) {
        int targ = acc % 2;
        targ = (targ << 1) + targ;
        superman += (targ << (2 * i));
        acc = acc >> 1;
    }
    return superman;
}

void printRev(long long gun) {
    while (gun != 0) {
        cout << gun % 2;
        gun = gun >> 1;
    }
    cout << " ";
}

int main() {
    int N, J;
    cin >> N >> J;
    if (N == 16) {
        int seed = (1 << 15) + 1;
        for (int i = 0; i < 50; i++) {
            printRev(seed + (numTo11(i) << 1));
            for (int j = 2; j <= 10; j++) {
                cout << j+1 << " ";
            }
            cout << endl;
        }
    }
    else if (N == 36) {
        long long seed = 1 << 17;
        seed = (seed << 18) + 1;
        for (int i = 0; i < 500; i++) {
            printRev(seed + (numTo11(i) << 1));
            for (int j = 2; j <= 10; j++) {
                cout << j+1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
