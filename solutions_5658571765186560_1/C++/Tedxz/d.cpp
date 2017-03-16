#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_P = 1007;

int T, ans;
int r, c, x;

bool check(int r, int c, int x) {
    if (r < c) {
        int t = r;
        r = c;
        c = t;
    }
    
    if (r * c % x != 0)
        return true;

    if (x > r)
        return true;
        
    if (x >= 2 * c + 1)
        return true;

    if (x >= 7)
        return true;
        
    if (x == 1)
        return false;
    if (x == 6 && c == 3)
        return true;
    if (c >= 3 && x <= 3) 
        return false;
    if (x <= 2)
        return false;
    if (c >= x && x < 7)
        return false;
    if (c == 2 && x == 4) return true;
    //if ( x <= 4) return false;
    
    //cout << r << " " << c << " " << x << endl;
    
    return false;
}

int main() {
    freopen("D-large.in", "r", stdin);
    freopen("d.txt", "w", stdout);
    for (x = 1; x <= 20; ++x)
            for (r = 1; r <= 20; ++r)
        for (c = r; c <= 20; ++c)
                check(r, c, x);
        
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> x >> r >> c;
        cout << "Case #" << cs << ": ";
        if (check(r, c, x)) {
            cout << "RICHARD" << endl;
        } else {
            cout << "GABRIEL" << endl;
        }
    }

    return 0;
}
