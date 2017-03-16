#include <bitset>
#include <iostream>

using namespace std;

const int BITS = 32;
const int ITER_SIZE = 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 32, j = 500;
    cout << "Case #1:" << endl;
    for (int i = 0; i < j; ++i) {
        bitset<BITS> b, num(i);
        b[0] = 1;
        b[n - 1] = 1;
        for (int p = 0; p < ITER_SIZE; ++p) {
            b[1 + 2 * p] = num[p];
            b[2 + 2 * p] = num[p];
        }
        cout << b.to_string();
        for (int base = 2; base <= 10; ++base) {
            cout << " " << base + 1;
        }
        cout << endl;
    }
    return 0;
}
