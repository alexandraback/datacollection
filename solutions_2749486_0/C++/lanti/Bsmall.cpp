// Bsmall.cpp

#include <algorithm>
#include <iostream>
using namespace std;


void solve(int tcase)
{
    int X, Y; cin >> X >> Y;

    string ans;
    for (int i = 0; i < abs(X); ++i) {
        if (X >= 0) ans += "WE";
        else ans += "EW";
    }
    for (int i = 0; i < abs(Y); ++i) {
        if (Y >= 0) ans += "SN";
        else ans += "NS";
    }
    cout << "Case #" << tcase << ": ";
    cout << ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
}
