#include <iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

int main()
{
    int t, i, j;
    char n[100][200], l;
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");
    FILE * pFile;
    pFile = fopen ("A-small-attempt0.in" , "r");
    fin>>t;
    for(i=0;i<=t;i++)
    {
        fgets(n[i], 200, pFile);
    }
    for(i=1;i<=t;i++)
    {
        for(j=0;n[i][j];j++)
        {
            l=n[i][j];
            switch(l) {
                case 'y':
                    n[i][j]='a';
                    break;
                case 'n':
                    n[i][j]='b';
                    break;
                case 'f':
                    n[i][j]='c';
                    break;
                case 'i':
                    n[i][j]='d';
                    break;
                case 'c':
                    n[i][j]='e';
                    break;
                case 'w':
                    n[i][j]='f';
                    break;
                case 'l':
                    n[i][j]='g';
                    break;
                case 'b':
                    n[i][j]='h';
                    break;
                case 'k':
                    n[i][j]='i';
                    break;
                case 'u':
                    n[i][j]='j';
                    break;
                case 'o':
                    n[i][j]='k';
                    break;
                case 'm':
                    n[i][j]='l';
                    break;
                case 'x':
                    n[i][j]='m';
                    break;
                case 's':
                    n[i][j]='n';
                    break;
                case 'e':
                    n[i][j]='o';
                    break;
                case 'v':
                    n[i][j]='p';
                    break;
                case 'z':
                    n[i][j]='q';
                    break;
                case 'p':
                    n[i][j]='r';
                    break;
                case 'd':
                    n[i][j]='s';
                    break;
                case 'r':
                    n[i][j]='t';
                    break;
                case 'j':
                    n[i][j]='u';
                    break;
                case 'g':
                    n[i][j]='v';
                    break;
                case 't':
                    n[i][j]='w';
                    break;
                case 'h':
                    n[i][j]='x';
                    break;
                case 'a':
                    n[i][j]='y';
                    break;
                case 'q':
                    n[i][j]='z';
                    break;
            }
        }
        fout<<"Case #"<<i<<": "<<n[i];
    }
    return 0;
}
