/* 
 * File:   main.cpp
 * Author: tyg3r
 *
 * Created on 13. duben 2013, 1:09
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

char board[5][5];
int main(int argc, char** argv) {
    
    int n;
    
    scanf("%d\n", &n);
    for(int caseN = 1; caseN <= n; caseN++) {
        for(int i = 0; i < 4; i++) {
            scanf("%s\n", board[i]);
        }
        scanf("\n");
        bool Owins = false;
        bool Xwins = false;
        int Os;
        int Xs;
        int Ts;
        for(int i = 0; i < 4; i++) {
            Os = Xs = Ts = 0;
            for(int j = 0; j < 4; j++) {
                if(board[i][j] == 'O') Os++;
                if(board[i][j] == 'X') Xs++;
                if(board[i][j] == 'T') Ts++;
            }
            if(Os == 4 || (Os == 3 && Ts == 1)) {
                Owins = true;
                break;
            } else if(Xs == 4 || (Xs == 3 && Ts == 1)) {
                Xwins = true;
                break;
            }
            Os = Xs = Ts = 0;
            for(int j = 0; j < 4; j++) {
                if(board[j][i] == 'O') Os++;
                if(board[j][i] == 'X') Xs++;
                if(board[j][i] == 'T') Ts++;
            }
            if(Os == 4 || (Os == 3 && Ts == 1)) {
                Owins = true;
                break;
            } else if(Xs == 4 || (Xs == 3 && Ts == 1)) {
                Xwins = true;
                break;
            }
        }
        Os = Xs = Ts = 0;
        for(int i = 0; i < 4; i++) {
            if(board[i][i] == 'O') Os++;
            if(board[i][i] == 'X') Xs++;
            if(board[i][i] == 'T') Ts++;
        }
        if(Os == 4 || (Os == 3 && Ts == 1)) {
            Owins = true;
        } else if(Xs == 4 || (Xs == 3 && Ts == 1)) {
            Xwins = true;
        }
        Os = Xs = Ts = 0;
        for(int i = 0; i < 4; i++) {
            if(board[i][3-i] == 'O') Os++;
            if(board[i][3-i] == 'X') Xs++;
            if(board[i][3-i] == 'T') Ts++;
        }
        if(Os == 4 || (Os == 3 && Ts == 1)) {
            Owins = true;
        } else if(Xs == 4 || (Xs == 3 && Ts == 1)) {
            Xwins = true;
        }
        
        
        if(Owins) {
            printf("Case #%d: O won\n", caseN);
        } else if(Xwins) {
            printf("Case #%d: X won\n", caseN);
        } else {
            bool draw = true;
            for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) if(board[i][j] == '.') draw = false;
            if(draw) printf("Case #%d: Draw\n", caseN);
            else printf("Case #%d: Game has not completed\n", caseN);
        }
    }
    return 0;
}

