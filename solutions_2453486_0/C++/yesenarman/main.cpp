#include <string>
#include <iostream>

using namespace std;

const int di[] = {+1,  0, +1, +1};
const int dj[] = { 0, +1, +1, -1};

string a[5];

int winner(int i, int j, int di, int dj, int k, int w) {
    if (k==0) return w;
    if (i<0 || i>=4 || j<0 || j>=4 || a[i][j]=='.')
        return 0;
    if (a[i][j]=='T')
        return winner(i+di, j+dj, di, dj, k-1, w);
    if (w==0) w=a[i][j];
    if (w!=a[i][j]) return 0;
    return winner(i+di, j+dj, di, dj, k-1, w);
}

int find_winner() {
    for (int i=0; i<4; ++i)
        for (int j=0; j<4; ++j)
            for (int k=0; k<4; ++k) {
                int w = winner(i, j, di[k], dj[k], 4, 0);
                if (w != 0)
                    return w;
            }
    return 0;
}

void solve(int testcase) {
    printf("Case #%d: ", testcase);
    for (int i=0; i<4; ++i)
        cin >> a[i];
    int w = find_winner();
    if (w == 0) {
        bool completed = true;
        for (int i=0; i<4; ++i)
            for (int j=0; j<4; ++j)
                if (a[i][j] == '.') {
                    completed = false;
                    break;
                }
        puts(completed ? "Draw" : "Game has not completed");
    } else {
        printf("%c won\n", w);
    }
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i)
        solve(i);
    return 0;
}
