#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

bool check(int X, int R, int C)
{
    if (R*C % X)
        return false;
    if (R < C) {
        int tmp = R;
        R = C;
        C = tmp;
    }
    if (X > R)
        return false;
    if (C > 3)
        return X < 7;
    if (C == 3)
        return X < 6;
    if (C == 2)
        return X < 4;
    if (C == 1)
        return X < 3;
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int X, R, C;
        cin >> X >> R >> C;
        cout << "Case #" << testcase+1 << ": ";
        cout << (check(X, R, C) ? "GABRIEL" : "RICHARD");
        cout << endl;
    }
    return 0;
}

// vim: set sw=4:
