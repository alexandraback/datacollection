#include <stdio.h>
#include <string.h>

#define MAX 64

char mapa[MAX][MAX];
void problem(void);

int main(int argc, char *argv[])
{
    int total, t;
    scanf("%d", &total);
    for (t = 0; t < total; ++t)
    {
        printf("Case #%d:", t+1);
        problem();
    }
    return 0;
}

int expand(int x, int y, int r, int c, int *rem)
{
    int max_r;
    int max_c;
    int i, k;
    int count = 0;
    max_r = r <= x+1? x: x+1;
    max_c = c <= y+1? y: y+1;

    if (mapa[x][y] == '*')
        return 1;

    for (i = x-1 >= 0? x-1: x; i < x+2 && i < r; ++i)
        for (k = y-1 >= 0? y-1: y; k < y+2 && k < c; ++k)
            if (mapa[i][k] == '*')
                count++;
    if (count <= *rem)
    {
        for (i = x-1 >= 0? x-1: x; i < x+2 && i < r; ++i)
            for (k = y-1 >= 0? y-1: y; k < y+2 && k < c; ++k)
        /*for (i = x; i < x+2 && i < r; ++i)*/
            /*for (k = y; k < y+2 && k < c; ++k)*/
        /*for (i = x; i < max_r; ++i)*/
            /*for (k = y; k < max_c; ++k)*/
                if (mapa[i][k] == '*')
                {
                    mapa[i][k] = '.';
                    (*rem)--;
                }
    }
    else
        return 1;
    return 0;
}

int first_exp(int r, int c, int *rem)
{
    int i;

    for (i = 0; i < r || i < c; ++i)
    {
        expand(i, 0, r, c, rem);
        expand(0, i, r, c, rem);
    }
    return 0;
}

int second_exp(int r, int c, int *rem)
{
    int i, k;
    for (i = 1; i < r; ++i)
        for (k = 1; k < c; ++k)
            if (expand(i, k, r, c, rem))
                if (rem == 0)
                    return 0;
                else
                    return 1;
    return 0;
}

void print_map(int r, int c)
{
    int i, k;
    for (i = 0; i < r; ++i)
    {
        for (k = 0; k < c; ++k)
            printf("%c", mapa[i][k]);
        printf("\n");
    }
}

void problem(void)
{
    int r, c, m;
    int rem;

    scanf("%d", &r);
    scanf("%d", &c);
    scanf("%d", &m);
    memset(mapa, '*', sizeof(mapa));
    rem = r*c - m - 1;
    mapa[0][0] = 'c';

    printf("\n");
    first_exp(r, c, &rem);
    second_exp(r, c, &rem);
    if (rem)
        printf("Impossible\n");
    else
        print_map(r, c);
}
