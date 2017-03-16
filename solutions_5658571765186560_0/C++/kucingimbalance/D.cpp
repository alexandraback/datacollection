#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SZ(a) (int)a.size()
#define MP make_pair
#define PB push_back

int X, R, C;

int vis[25][(1<<20)+5];
int memo[25][(1<<20)+5];

int main() {
    cin.sync_with_stdio(false);
    int ntc;
    cin >> ntc;
    for (int i = 1; i <= ntc; ++i) {
        cin >> X >> R >> C;
        cout << "Case #" << i << ": ";
        if (X > 6 || (R*C)%X != 0) {
            cout << "RICHARD" << endl;
        }
        else if (min(R,C) >= X) {
            cout << "GABRIEL" << endl;
        }
        else if (max(R,C) < X) {
            cout << "RICHARD" << endl;
        }
        else {
            int mini = min(R,C);
            if (X == 2) {
                cout << "GABRIEL" << endl;
            }
            if (X == 3) {
                if (mini < 2) 
                    cout << "RICHARD" << endl;
                else 
                    cout << "GABRIEL" << endl;
            }
            if (X == 4 || X == 5 || X == 6) {
                if (mini < 3)
                    cout << "RICHARD" << endl;
                else
                    cout << "GABRIEL" << endl;
            }
        }
        
    }
}
