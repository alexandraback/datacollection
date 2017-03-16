#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        bool possible = true;
        int x, r, c;
        cin >> x >> r >> c;
        if(r*c%x != 0)
            possible = false;
        if(max(r,c) < x)
            possible = false;
        if(x >= 7)
            possible = false;
        switch(x) {
            case 3:
                if(min(r,c) == 1)
                    possible = false;
                break;
            case 4:
                if(min(r,c) <= 2)
                    possible = false;
                break;
            case 5:
                if(min(r,c) <= 2)
                    possible = false;
                if(min(r,c) == 3 && max(r,c) == 5)
                    possible = false;
                break;
            case 6:
                if(min(r,c) <= 3)
                    possible = false;
                break;
        }
        cout << "Case #" << t << ": ";
        if(possible)
            cout << "GABRIEL" << endl;
        else
            cout << "RICHARD" << endl;
    }
    return 0;
}
