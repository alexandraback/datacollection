#include <bits/stdc++.h>
using namespace std;
#define SD(a) scanf("%d", &a)
int fre[30];
int fuckit(char z)
{
    return z - 'A';
}
char str[3000];
int a[20];
//ONETWOTHREEFOURFIVESIXSEVENEIGHTNINE
int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("outputki3.txt", "w", stdout);
    int tcase, t, i, j;
    SD(tcase);
    for(t = 1; t <= tcase; t++)
    {
        memset(fre, 0, sizeof(fre));
        memset(a, 0, sizeof(a));
        scanf("%s", str);
        int len = strlen(str);
        for(i = 0; i < len; i++) fre[fuckit(str[i])]++;



        a[0] = fre[fuckit('Z')];
        //printf("de %d %d %d %d\n", fre[fuckit('Z')], fre[fuckit('E')], fre[fuckit('R')], fre[fuckit('O')]);

        fre[fuckit('Z')] -= a[0];
        fre[fuckit('E')] -= a[0];
        fre[fuckit('R')] -= a[0];
        fre[fuckit('O')] -= a[0];

        a[8] = fre[fuckit('G')];
        fre[fuckit('E')] -= a[8];
        fre[fuckit('I')] -= a[8];
        fre[fuckit('G')] -= a[8];
        fre[fuckit('H')] -= a[8];
        fre[fuckit('T')] -= a[8];

        a[6] = fre[fuckit('X')];
        fre[fuckit('S')] -= a[6];
        fre[fuckit('I')] -= a[6];
        fre[fuckit('X')] -= a[6];

        a[4] = fre[fuckit('U')];
        fre[fuckit('F')] -= a[4];
        fre[fuckit('O')] -= a[4];
        fre[fuckit('U')] -= a[4];
        fre[fuckit('R')] -= a[4];

        a[5] = fre[fuckit('F')];
        fre[fuckit('F')] -= a[5];
        fre[fuckit('I')] -= a[5];
        fre[fuckit('V')] -= a[5];
        fre[fuckit('E')] -= a[5];

        a[7] = fre[fuckit('V')];
        fre[fuckit('S')] -= a[7];
        fre[fuckit('V')] -= a[7];
        fre[fuckit('N')] -= a[7];
        fre[fuckit('E')] -= a[7]*2;

        a[2] = fre[fuckit('W')];
        fre[fuckit('T')] -= a[2];
        fre[fuckit('W')] -= a[2];
        fre[fuckit('O')] -= a[2];

        a[3] = fre[fuckit('R')];
        fre[fuckit('T')] -= a[3];
        fre[fuckit('H')] -= a[3];
        fre[fuckit('R')] -= a[3];
        fre[fuckit('E')] -= a[3]*2;

        a[9] =fre[fuckit('I')];
        fre[fuckit('N')] -= a[9]*2;
        fre[fuckit('I')] -= a[9];
        fre[fuckit('E')] -= a[9];

        a[1] = fre[fuckit('E')];
        fre[fuckit('O')] -= a[1];
        fre[fuckit('N')] -= a[1];
        fre[fuckit('E')] -= a[1];



        printf("Case #%d: ", t);
        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < a[i]; j++) printf("%d", i);
        }
        printf("\n");

    }
}
