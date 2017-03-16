#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

string check_winner(string line)
{
    int O = 0, T = 0, X = 0;
    for (int i = 0; i < line.size(); i++){
        if (line[i] == 'O')
            O++;
        else if (line[i] == 'T')
            T++;
        else if (line[i] == 'X')
            X++;
        else return "";
    }
    if (O && X) return "";
    return O ? "O" : "X";
}

int main()
{
    string file;
    cin>>file;
    FILE* fp = fopen(file.c_str(), "r");
    FILE* fp_out = fopen("out.txt", "w");
    
    assert(fp != NULL);
    assert(fp_out != NULL);
    
    int T;
    fscanf(fp, "%d", &T);

    for (int cas = 1; cas <= T; cas++){
        char mp[10][10];
        for (int i = 0; i < 4; i++){
                fscanf(fp, "%s", mp[i]);
        }
        
        int t;
        string winner, d1, d2;
        for (int i = 0; i < 4; i++){
            string row;
            for (int j = 0; j < 4; j++)
                row += mp[i][j];
            winner = check_winner(row);
            if (winner != "")
                goto final;
        }
        
        for (int j = 0; j < 4; j++){
                string col;
                for (int i = 0; i < 4; i++){
                    col += mp[i][j];
                }
                winner = check_winner(col);
                if (winner != "") goto final;
        }
        
        for (int i = 0; i < 4; i++)
            d1 += mp[i][i];
        winner = check_winner(d1);
        if (winner != "") goto final;
        
        for (int i = 0; i < 4; i++)
            d2 += mp[i][3 - i];
        winner = check_winner(d2);
        if (winner != "") goto final;
        
        t = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                t += (mp[i][j] == '.');
        
final:
        fprintf(fp_out, "Case #%d: ", cas);
        if (winner != "")
            fprintf(fp_out, "%s won\n", winner.c_str());
        else fprintf(fp_out, "%s\n", t ? "Game has not completed" : "Draw");
    }
    fclose(fp);
    fclose(fp_out);
    return 0;
}