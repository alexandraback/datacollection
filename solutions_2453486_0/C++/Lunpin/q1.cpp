#include<iostream>
using namespace std;

int main () {
    int T;
    cin >> T;
    for (int cas=1; cas<=T; cas++) {
        /* Initial */
        char a[4][4];
        bool xWon=0, yWon=0, gameCompleted=1;
        int xCount, yCount;
        for (int i=0; i<4; i++)
        for (int j=0; j<4; j++) cin >> a[i][j];
        /* Determine Row */
        for (int i=0; i<4 && !xWon && !yWon; i++) {
            xCount = yCount = 0;
            for (int j=0; j<4; j++) {
                if (a[i][j]=='X') xCount++;
                else if (a[i][j]=='O') yCount++;
                else if (a[i][j]=='T') xCount++, yCount++;
                else if (a[i][j]=='.') {
                    gameCompleted = 0;
                    break;
                }
            }
            if (xCount == 4) xWon = 1;
            else if (yCount == 4) yWon = 1;
        }
        /* Determine Column */
        for (int j=0; j<4 && !xWon && !yWon; j++) {
            xCount = yCount = 0;
            for (int i=0; i<4; i++) {
                if (a[i][j]=='X') xCount++;
                else if (a[i][j]=='O') yCount++;
                else if (a[i][j]=='T') xCount++, yCount++;
                else if (a[i][j]=='.') {
                    gameCompleted = 0;
                    break;
                }
            }
            if (xCount == 4) xWon = 1;
            else if (yCount == 4) yWon = 1;
        }
        /* Determine Diagonal "\" */
        xCount = yCount = 0;
        for (int i=0; i<4 && !xWon && !yWon; i++) {
            if (a[i][i]=='X') xCount++;
            else if (a[i][i]=='O') yCount++;
            else if (a[i][i]=='T') xCount++, yCount++;
            else if (a[i][i]=='.') {
                gameCompleted = 0;
                break;
            }
        }
        if (xCount == 4) xWon = 1;
        else if (yCount == 4) yWon = 1;
        /* Determine Diagonal "/" */
        xCount = yCount = 0;
        for (int i=0; i<4 && !xWon && !yWon; i++) {
            if (a[i][3-i]=='X') xCount++;
            else if (a[i][3-i]=='O') yCount++;
            else if (a[i][3-i]=='T') xCount++, yCount++;
            else if (a[i][3-i]=='.') {
                 gameCompleted = 0;
                 break;
            }
        }
        if (xCount == 4) xWon = 1;
        else if (yCount == 4) yWon = 1;
        /* End */
        cout << "Case #" << cas << ": ";
        if (xWon) cout << "X won\n";
        else if (yWon) cout << "O won\n";
        else if (gameCompleted) cout << "Draw\n";
        else cout << "Game has not completed\n";
    }
    //system("pause");
}
