#include <iostream>
#include <cstdio>
using namespace std;

int n,r,c,l;
char t[7][7];
char tt[7][7];
char v[7][7];
int bejart;

int test(int x, int y)
{
    if (!(x > 0 && x <= r && y > 0 && y <= c)) return 0;
    if (tt[x][y] == 'o') return 0;
    tt[x][y] = 'o'; bejart++;
    //printf("%d %d\n", x, y);
    int db = 0;
    for (int i = x - 1; i<=x+1; i++)
    {
        for (int j = y - 1; j<=y+1; j++)
        {
            if (tt[i][j] != '.' && tt[i][j] != 'o') db++;
        }
    }
    if (db > 0) return 0;
    for (int i = x - 1; i<=x+1; i++)
    {
        for (int j = y - 1; j<=y+1; j++)
        {
            if (tt[i][j] == '.') test(i, j);
        }
    }
    return 0;
}

int v1,v2;

int tester(int hanyures)
{
    int i = 1;
    int j = 1;
    while (i <= r && j <= c)
    {
        int db = 0;
        for (int ii = i - 1; ii<=i+1; ii++)
        {
            for (int jj = j - 1; jj<=j+1; jj++)
            {
                if (ii > 0 && ii <= r && jj > 0 && jj <= c && tt[ii][jj] != '.' && tt[ii][jj] != 'o') db++;
            }
        }
        //printf("proba %d %d  %d\n", i, j, db);
        if (db == 0)
        {
            //for (int iii = 0; iii<=6; iii++) for (int jjj = 0; jjj<=6; jjj++) if (tt[iii][jjj] == 'o') tt[iii][jjj] = '.';
            bejart = 0;
            v1 = i; v2 = j;
            test(i, j);
            if (bejart == hanyures) return 1;
            else return 0;
        }
        if (j < c) j++; else {i++; j=1;}
    }
    if (hanyures == 1)
    {
        return 1;
    }
    return 0;
}

int tombki()
{
    for (int i = 1; i<=r; i++)
    {
        for (int j = 1; j<=c; j++)
        {
            printf("%c", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int bt(int x, int y, int bomba, int ures, int sorbomba)
{
    /*printf("%d %d %d %d %d\n", x, y, bomba, ures, sorbomba);
    for (int i = 1; i<=r; i++)
    {
        for (int j = 1; j<=c; j++)
        {
            if (i <= x && (i < x || j < y)) printf("%c", t[i][j]); else printf("_");
        }
        printf("\n");
    }*/
    if (x>r)
    {
        //tombki();
        if (bomba != l) return 0;
        for (int i = 0; i<=r+1; i++)
        {
            for (int j = 0; j<=c+1; j++)
            {
                tt[i][j] = t[i][j];
                //if (t[i][j] == '*') db++;
            }
        }
        //printf("bomba  %d\n", bomba);
        if (ures == 1)
        {
            for (int i = 1; i<=r; i++)
            {
                for (int j = 1; j<=c; j++)
                {
                    v[i][j] = t[i][j];
                    if (t[i][j] == '.') v[i][j] = 'c';
                }
            }
            return 1;
        }
        if (tester(ures) == 0) return 0;
        else
        {
            for (int i = 1; i<=r; i++)
            {
                for (int j = 1; j<=c; j++)
                {
                    v[i][j] = t[i][j];
                }
            }
            v[v1][v2] = 'c';
            return 1;
        }
    }

    int x0 = x; int y0 = y;
    if (y0<c) y0++; else {x0++; y0=1;}


    /*if (y == 1 && x > 1)
    {
        if (ures > c - sorbomba && sorbomba == 0 && r*c-ures>l) return 0;
        sorbomba = 0;
    }*/
    if (r*c-ures < l) return 0;

    if (bomba > l) return 0;

    if (bomba < l)
    {
        t[x][y] = '*';
        if (bt(x0, y0, bomba+1, ures, sorbomba+1) == 1) return 1;
    }

    t[x][y] = '.';
    if (bt(x0, y0, bomba, ures+1, sorbomba) == 1) return 1;


    return 0;
}






int main()
{
    scanf("%d", &n); FILE *out = fopen("ki.txt", "w");
    int errortimes = 0;
    for (int ii = 1; ii<=n; ii++)
    {
        for (int i = 0; i<=6; i++) for (int j = 0; j<=6; j++) { t[i][j] = '.'; tt[i][j] = '.'; v[i][j] = '.'; }
        scanf("%d%d%d", &r, &c, &l);
        printf("%d\n", ii);
        //printf("%d %d %d:\n", r, c, l);

        //tt[1][1] = '.'; tt[2][1] = '.'; tt[3][1] = '*';
        //tester(2);


        if (bt(1, 1, 0, 0, 0) == 0)
        {
            //printf("Case #%d: %d %d %d\nImpossible\n", ii, r, c, r*c-l);
            fprintf(out, "Case #%d:\nImpossible\n", ii);
            //else printf("sporol\n");
        }
        else
        {
            fprintf(out, "Case #%d:\n", ii);
            //printf("Case #%d: %d %d %d\n", ii, r, c, r*c-l);
            int db = 0;
            for (int i = 1; i<=r; i++)
            {
                for (int j = 1; j<=c; j++)
                {
                    fprintf(out, "%c", v[i][j]);
                    //printf("%c", v[i][j]);
                    if (v[i][j] == '*') db++;
                }
                //printf("\n");
               fprintf(out, "\n");
            }
            //if (db == l) printf("good\n"); else { printf("ERROR !!!\n"); errortimes++; }
        }

    }
    //printf("%d\n", errortimes);





    return 0;
}
