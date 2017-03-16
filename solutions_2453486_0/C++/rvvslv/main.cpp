#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream cin("/Users/mac/topcoder/A-small-attempt0.in.txt");
    ofstream cout("/Users/mac/topcoder/res.txt");
    
    int N;
    cin >> N;
    
    for (int CT = 0; CT < N; CT ++) {
        string b[4];
        for (int i = 0; i < 4; i ++)
            cin >> b[i];
        
        cout << "Case #" << (CT + 1) << ": ";
        
        char winner = 'T';
        string players = "XO";
        for (int p = 0; p < 2; p ++) {
            char pch = players[p];
            
            for (int i = 0; i < 4; i ++) {
                bool isLine = true;
                for (int j = 0; j < 4; j ++)
                    if (b[i][j] != pch && b[i][j] != 'T') {
                        isLine = false;
                        break;
                    }
                if (isLine)
                    winner = pch;
            }
            
            for (int i = 0; i < 4; i ++) {
                bool isVertical = true;
                for (int j = 0; j < 4; j ++)
                    if (b[j][i] != pch && b[j][i] != 'T') {
                        isVertical = false;
                        break;
                    }
                if (isVertical)
                    winner = pch;
            }
            
            bool isDiag = true;
            for (int j = 0; j < 4; j ++)
                if (b[j][j] != pch && b[j][j] != 'T') {
                    isDiag = false;
                    break;
                }
            if (isDiag)
                winner = pch;
            
            bool isDiag2 = true;
            for (int j = 0; j < 4; j ++)
                if (b[4 - j - 1][j] != pch && b[4 - j - 1][j] != 'T') {
                    isDiag2 = false;
                    break;
                }
            if (isDiag2)
                winner = pch;
        }
        
        if (winner != 'T') {
            cout << winner << " won" << endl;
            continue;
        }
        
        int emptyCells = 0;
        
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                if (b[i][j] == '.')
                    emptyCells ++;

        if (emptyCells > 0)
            cout << "Game has not completed" << endl;
        else
            cout << "Draw" << endl;
    }
    return 0;
}