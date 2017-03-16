#include<iostream>
#include<cstdio>
using namespace std;

int main()  {
    int T, i, j, k;
    char board[10][10], win;
    int pl_x, pl_y;
    bool draw;

    freopen("A-large.in", "r", stdin);
    freopen("A-large.txt", "w", stdout);

    cin >> T;
    for(i=1; i<=T; i++) {
        for(j=0; j<4; j++)
            scanf("%s", board[j]);

        win = '.';
        for(j=0; j<4; j++)  {
            pl_x = pl_y = 0;
            for(k=0; k<4; k++)  {
                switch(board[j][k]) {
                    case 'X': pl_x++; break;
                    case 'O': pl_y++; break;
                    case 'T': pl_x++; pl_y++; break;
                }
            }
            if(pl_x == 4)   { win = 'X'; break; }
            else if(pl_y == 4)  { win = 'O'; break; }

            pl_x = pl_y = 0;
            for(k=0; k<4; k++)  {
                switch(board[k][j]) {
                    case 'X': pl_x++; break;
                    case 'O': pl_y++; break;
                    case 'T': pl_x++; pl_y++; break;
                }
            }
            if(pl_x == 4)   { win = 'X'; break; }
            else if(pl_y == 4)  { win = 'O'; break; }
        }
        if(win == '.')  {
            pl_x = pl_y = 0;
            for(j=0; j<4; j++)  {
                switch(board[j][j])   {
                    case 'X': pl_x++; break;
                    case 'O': pl_y++; break;
                    case 'T': pl_x++; pl_y++; break;
                }
            }
            if(pl_x == 4)   { win = 'X'; }
            else if(pl_y == 4)  { win = 'O'; }
        }
        if(win == '.')  {
            pl_x = pl_y = 0;
            for(j=0; j<4; j++)  {
                switch(board[j][3-j])   {
                    case 'X': pl_x++; break;
                    case 'O': pl_y++; break;
                    case 'T': pl_x++; pl_y++; break;
                }
            }
            if(pl_x == 4)   { win = 'X'; }
            else if(pl_y == 4)  { win = 'O'; }
        }
        if(win == 'X')  cout << "Case #" << i << ": " << "X won\n";
        else if(win == 'O') cout << "Case #" << i << ": " << "O won\n";
        else    {
            draw = true;
            for(j=0; draw && j<4; j++)
                for(k=0; draw && k<4; k++)
                    if(board[j][k] == '.')
                        draw = false;
            if(draw)    cout << "Case #" << i << ": "  << "Draw\n";
            else        cout << "Case #" << i << ": "  << "Game has not completed\n";
        }
    }

    return 0;
}
