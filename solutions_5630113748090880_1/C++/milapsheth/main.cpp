#include <iostream>

using std::cin;
using std::cout;

void main2(int);

int main() {
    int t;

    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        main2(i);
    }
}
