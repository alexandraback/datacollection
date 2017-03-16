#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int X, R, C;
        cin >> X >> R >> C;
        int result = 1;

        if (
            (X > R && X > C) ||
            (X - 1 > 0 && (X - 1 > R || X - 1 > C)) ||
            ((R * C) % X != 0)
        ) {
            result = -1;
        }

        cout << "Case #" << (t + 1) << ": " << (result == -1 ? "RICHARD" : "GABRIEL") << endl;
    }

    return 0;
}
