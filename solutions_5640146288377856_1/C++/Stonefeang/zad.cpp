#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int dlu, n, m;

int szuk[25][25];
int dob[25][25];
int wyn;

//int tab[20];

//int wyn[11][11];

/*void rek(int v)
{
     if (v>m)
     {
             check();
             return;
     }
     tab[v]=0;
}*/

int main()
{
    /*wyn[10][10]=10;
    wyn[10][9]=10;
    wyn[10][8]=9;
    wyn[10][7]=8;
    wyn[10][6]=7;
    wyn[10][5]=6;
    wyn[10][4]=6;
    wyn[10][3]=
    wyn[10][2]=6;
    wyn[10][1]=10;*/
    for (int i=0; i<=20; i++)
    {
        for (int j=0; j<=20; j++)
        {
            szuk[i][j]=0;
            dob[i][j]=100;
        }
    }
    for (int i=1; i<=20; i++)
    {
        for (int j=1; j<=i; j++)
        {
            szuk[i][j]=i;
            dob[i][j]=i;
            for (int l=1; l<=i; l++)
            {
                szuk[i][j]=min(szuk[i][j], 1+szuk[l-1][j]+szuk[i-l][j]);
                dob[i][j]=min(dob[i][j], 1+min(szuk[l-1][j]+dob[i-l][j] , dob[l-1][j]+szuk[i-l][j]));
                //if (i==5 && j==2)
                //printf("%d i %d     %d i %d\n", szuk[l-1][j], dob[i-l][j], dob[l-1][j], szuk[i-l][j]);
            }
            if (j*2>=i)
            {
                         dob[i][j]=min(j+1, i);
            }
            //printf("%d %d  %d %d\n", i, j, dob[i][j], szuk[i][j]);
        }
    }
    //printf("%d %d\n", szuk[5][1], dob[5][1]);
    //printf("%d %d\n", szuk[1][2], dob[1][2]);
    //printf("%d %d\n", szuk[0][2], dob[0][2]);
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
              scanf("%d%d%d", &n, &m, &dlu);
              wyn=dob[m][dlu];
              for (int i=1; i<n; i++)
              wyn+=szuk[m][dlu];
              printf("Case #%d: %d\n", h, wyn);
              //rek(1);
    }
    return 0;
}
