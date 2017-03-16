#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
int T,t;
char s[4][5];
bool checkwin(char xo)
{
    char te[4][5];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(s[i][j]=='T')
                te[i][j]=xo;
            else
                te[i][j]=s[i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        if(te[i][0]==xo&&te[i][1]==xo&&te[i][2]==xo&&te[i][3]==xo)
            return true;
    }

    for(j=0;j<4;j++)
    {
        if(te[0][j]==xo&&te[1][j]==xo&&te[2][j]==xo&&te[3][j]==xo)
            return true;
    }
    if(te[0][0]==xo&&te[1][1]==xo&&te[2][2]==xo&&te[3][3]==xo)
            return true;
    if(te[0][3]==xo&&te[1][2]==xo&&te[2][1]==xo&&te[3][0]==xo)
            return true;
    return false;
}

bool checkfill()
{
    int i,j,num;
    num=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(s[i][j]=='.')
                return false;
        }
    }
    return true;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("A-large.in","r");
    fout=fopen("out.txt","w");
    fscanf(fin,"%d",&T);
    for(t=1;t<=T;t++)
    {
        fscanf(fin,"%s%s%s%s",s[0],s[1],s[2],s[3]);
        fprintf(fout,"Case #%d: ",t);
        if(checkwin('X'))
        {
            fprintf(fout,"X won\n");
            //printf("X won\n");
        }
        else if(checkwin('O'))
        {
             fprintf(fout,"O won\n");
             //printf("O won\n");
        }
        else if(checkfill())
        {
            fprintf(fout,"Draw\n");
            //printf("Draw\n");
        }
        else
            fprintf(fout,"Game has not completed\n");
            //printf("Game has not completed\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
