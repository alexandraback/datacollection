#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

char a[4][4];
char* judge(){
    int empty = 0;
    for (int i = 0; i < 4; i++){
        int xwon = 0;
        int owon = 0;
        for (int j= 0; j < 4; j++){
            if(a[i][j] == 'X')
                xwon++;
            else if (a[i][j] == 'O')
                    owon++;
                else if (a[i][j] == 'T') {
                        xwon++;
                        owon++;
                        }
                        else empty++;
        }
        if (xwon == 4)
            return "X won";
        if (owon == 4)
            return "O won";
    }
     for (int j= 0; j < 4; j++){
        int xwon = 0;
        int owon = 0;
        for (int i = 0; i < 4; i++){
            if(a[i][j] == 'X')
                xwon++;
            else if (a[i][j] == 'O')
                    owon++;
                else if (a[i][j] == 'T') {
                        xwon++;
                        owon++;
                        }
        }
        if (xwon == 4)
            return "X won";
        if (owon == 4)
            return "O won";
    }
    int xwon = 0;
    int owon = 0;
    for (int i = 0; i < 4; i++){
        if(a[i][i] == 'X')
                xwon++;
            else if (a[i][i] == 'O')
                    owon++;
                else if (a[i][i] == 'T') {
                        xwon++;
                        owon++;
                        }
        if (xwon == 4)
            return "X won";
        if (owon == 4)
            return "O won";
    }
    xwon = 0;
    owon = 0;
    for (int i = 0; i <4; i++){
        if(a[i][3-i] == 'X')
                xwon++;
            else if (a[i][3-i] == 'O')
                    owon++;
                else if (a[i][3-i] == 'T') {
                        xwon++;
                        owon++;
                        }
        if (xwon == 4)
            return "X won";
        if (owon == 4)
            return "O won";
    }
    if (empty != 0)
        return "Game has not completed";
    return "Draw";

}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int n;
    char ch;
    scanf("%d\n",&n);
    for(int k = 0; k < n; k++){
        for(int i = 0; i <4; i++){
            for(int j = 0; j < 4; j++){
                scanf("%c",&a[i][j]);
                while(a[i][j]!='X'&&a[i][j]!='O'&&a[i][j]!='T'&&a[i][j]!='.')scanf("%c",&a[i][j]);
            }
         }

        printf("Case #%d: %s\n",k+1,judge());
    }
    return 0;
}
