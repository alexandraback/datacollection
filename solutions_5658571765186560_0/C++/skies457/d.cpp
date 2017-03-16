#include <iostream>
using namespace std;

int ans[5][5][5];

int main()
{
    ans[2][1][1] = ans[2][1][3] = ans[2][3][3] = 1;
    ans[3][1][1] = ans[3][1][2] = ans[3][1][3] = ans[3][1][4] = ans[3][2][2] = ans[3][2][4] = ans[3][4][4] = 1;
    ans[4][1][1] = ans[4][1][2] = ans[4][1][3] = ans[4][1][4] = ans[4][2][2] = ans[4][2][3] = ans[4][2][4] = ans[4][3][3] = 1;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int X,R,C;
        cin >> X >> R >> C;
        cout << "Case #" << i + 1 << ": ";
        if(R > C) swap(R, C);
        if(ans[X][R][C])
            cout << "RICHARD" << endl;
        else
            cout << "GABRIEL" << endl;
    }
    return 0;
}
