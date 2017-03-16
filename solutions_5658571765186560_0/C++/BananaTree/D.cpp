#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const string ALLOK = "GABRIEL";
const string NOTOK = "RICHARD";
int main() {
    int T, area, row, col;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        cin >> area >> row >> col;
        if (row < col) swap(row, col);     
        if ((row * col) % area) {
            cout << NOTOK << endl;
            continue;
        }        
        if (area <= 2) cout << ALLOK << endl;        
        if (area == 3) {
            assert(col != 4);
            if (col == 1) cout << NOTOK << endl;
            if (col == 2) {
                assert(row == 3);
                cout << ALLOK << endl;
            }
            if (col == 3) {                
                if (row == 3) cout << NOTOK << endl;
                if (row == 4) cout << ALLOK << endl;
            }            
        }
        if (area == 4) {
            if (row < 4 || col == 1) cout << NOTOK << endl;
            else {
                assert(row == 4 && col > 1);
                if (col == 2) cout << ALLOK << endl;
                if (col == 3) cout << NOTOK << endl;
                if (col == 4) cout << ALLOK << endl;
            }            
        }
    }
    return 0;
}
