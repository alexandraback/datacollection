#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int ttt, t;

int i,j,tt,who;

string s[5];

char S;

int main()
{
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);    
    cin >> t;
    for (ttt = 1; ttt <= t; ttt++){
        printf("Case #%d: ",ttt);
        cin >> s[1];
        cin >> s[2];
        cin >> s[3];
        cin >> s[4];                        
        
        for (i=1;i<=4;i++)
            s[i] = '.'+s[i];
                                  
        who = 0;
        
        S = 'O';        
            
        for (i=1;i<=4;i++){             
            tt = 1;
            for (j=1;j<=4;j++)
                if ((s[i][j] != S) && (s[i][j] != 'T')) tt = 0;
            if (tt == 1) who = 1;
        }

        for (i=1;i<=4;i++){             
            tt = 1;
            for (j=1;j<=4;j++)
                if ((s[j][i] != S) && (s[j][i] != 'T')) tt = 0;
            if (tt == 1) who = 1;
        }
        
        tt = 1;
        for (i=1;i<=4;i++)
            if ((s[i][i] != S) && (s[i][i] != 'T')) tt = 0;
        if (tt == 1) who = 1;
        
        tt = 1;
        for (i=1;i<=4;i++)
            if ((s[i][5-i] != S) && (s[i][5-i] != 'T')) tt = 0;
        if (tt == 1) who = 1;        

        S = 'X';        
            
        for (i=1;i<=4;i++){             
            tt = 1;
            for (j=1;j<=4;j++)
                if ((s[i][j] != S) && (s[i][j] != 'T')) tt = 0;
            if (tt == 1) who = 2;
        }

        for (i=1;i<=4;i++){             
            tt = 1;
            for (j=1;j<=4;j++)
                if ((s[j][i] != S) && (s[j][i] != 'T')) tt = 0;
            if (tt == 1) who = 2;
        }
        
        tt = 1;
        for (i=1;i<=4;i++)
            if ((s[i][i] != S) && (s[i][i] != 'T')) tt = 0;
        if (tt == 1) who = 2;
        
        tt = 1;
        for (i=1;i<=4;i++)
            if ((s[i][5-i] != S) && (s[i][5-i] != 'T')) tt = 0;
        if (tt == 1) who = 2;                

        tt = 1;
        for (i=1;i<=4;i++)
            for (j=1;j<=4;j++)
                if (s[i][j] == '.') tt = 0;
        
        if (who == 0)    
        if (tt == 1) who = 3;
                
        if (who == 1) printf("O won\n"); else
        if (who == 2) printf("X won\n"); else        
        if (who == 3) printf("Draw\n"); else        
        printf("Game has not completed\n");        
    }
    return 0;
}
