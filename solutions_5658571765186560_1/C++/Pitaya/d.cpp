#include <iostream>
#include <algorithm>

using namespace std;

bool solve(int n, int r, int c) {
    if ((r * c) % n != 0) {
        return false;
    }
    switch(n) {
        case 1: return true;
        case 2: return true;
        case 3: if (r >= 2) {
            return true;
        } else {
            return false;
        }
        case 4: if (r >= 3) {
            return true;
        } else {
            return false;
        }
        case 5: if (r >= 4 || (r == 3 && c >= 10)) {
            return true;
        } else {
            return false;
        }
        case 6: if (r >= 4) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int main() 
{
    int T, n, r, c, tmp;
    string str;

    cin >> T;
    for (int I = 0; I < T; ++I)
    {
        cin >> n >> r >> c;
        if (r > c) {
            tmp = r;
            r = c;
            c = tmp;
        }
        cout << "Case #" << I + 1 << ": ";
        if (solve(n, r, c)) {
            cout << "GABRIEL" << endl;
        } else {            
            cout << "RICHARD" << endl;
        }

    }
    return 0;
}