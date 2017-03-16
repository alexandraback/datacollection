#define TOE
#ifdef TOE
#include "stdio.h"

int main()
{
    FILE *infile = fopen("/CodeJam/A.in", "r"),
         *outfile = fopen("/CodeJam/A.txt", "w");
    int T;
    fscanf(infile, "%d", &T);
    
    for (int t = 1; t <= T; t++) {
        char table[5][5] = {0};
        
        for (int i = 0; i < 4; i++) {
            fscanf(infile, "%s", table[i]);
        }
        
        bool isFull = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (table[i][j] == '.') {
                    isFull = false;
                }
        
        bool isXWon = false, isOWon = false;
        
        for (int i = 0; i < 4; i++)
        {
            bool xwon = true, owon = true;
            for (int j = 0; j < 4; j++) {
                xwon = xwon && (table[i][j] == 'X' || table[i][j] == 'T');
                owon = owon && (table[i][j] == 'O' || table[i][j] == 'T');
            }
            
            isXWon = isXWon || xwon;
            isOWon = isOWon || owon;
        }
        
        for (int i = 0; i < 4; i++)
        {
            bool xwon = true, owon = true;
            for (int j = 0; j < 4; j++) {
                xwon = xwon && (table[j][i] == 'X' || table[j][i] == 'T');
                owon = owon && (table[j][i] == 'O' || table[j][i] == 'T');
            }
            
            isXWon = isXWon || xwon;
            isOWon = isOWon || owon;
        }
        
        bool xwon = true, owon = true;
        for (int i = 0; i < 4; i++) {
            xwon = xwon && (table[i][i] == 'X' || table[i][i] == 'T');
            owon = owon && (table[i][i] == 'O' || table[i][i] == 'T');
        }
        isXWon = isXWon || xwon;
        isOWon = isOWon || owon;    
        
        xwon = true, owon = true;
        for (int i = 0; i < 4; i++) {
            xwon = xwon && (table[i][3 - i] == 'X' || table[i][3 - i] == 'T');
            owon = owon && (table[i][3 - i] == 'O' || table[i][3 - i] == 'T');
        }
        isXWon = isXWon || xwon;
        isOWon = isOWon || owon;
        
        fprintf(outfile, "Case #%d: ", t);
        if (isXWon) {
            fprintf(outfile, "X won\n");
        }
        else if (isOWon){
            fprintf(outfile, "O won\n");
        }
        else if (isFull){
            fprintf(outfile, "Draw\n");
        }
        else
            fprintf(outfile, "Game has not completed\n"); 
    }
    
    fclose(infile);
    fclose(outfile);
}

#endif