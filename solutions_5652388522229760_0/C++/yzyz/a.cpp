#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
bool seen[10];

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> n;

        cout << "Case #" << TC << ": ";
        if (n == 0) {
            cout << "INSOMNIA\n";
            continue;
        }

        for (int i = 0; i < 10; i++)
            seen[i] = false;

        int x = 0, num = 0;
        while (num < 10) {
            x += n;
            int y = x;
            while (y) {
                int d = y % 10;
                if (!seen[d]) {
                    seen[d] = true;
                    num++;
                }
                y /= 10;
            }
        }

        cout << x << '\n';
    }
}
