#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int X, R, C;
        cin >> X >> R >> C;
        if(R > C)
            swap(R, C);
        bool canAlwaysPlace;
        if(X > 2 * R || X > C || X >= 7 || (R * C) % X != 0 || (R > 1 && X == 2 * R) || (R == 4 && X == 6))
            canAlwaysPlace = false;
        else if(X <= R || R == 1 || X == 3 || (X == 4 && R == 3) || (X == 5 && R == 3) || (R > 3 && X <= R + 1))
            canAlwaysPlace = true;
        else
            std::cout << "unknown " << X << " " << R << " " << C << "\n";
        cout << "Case #" << i << ": " << (canAlwaysPlace ? "GABRIEL" : "RICHARD") << "\n";
    }
}