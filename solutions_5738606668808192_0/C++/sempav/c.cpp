#include <bitset>
#include <iostream>

using namespace std;

const int BITS = 16;
const int ITER_SIZE = 6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 16, j = 50;
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
