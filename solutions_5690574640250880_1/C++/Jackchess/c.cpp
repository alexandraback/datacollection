#include <cstdio>
char a[100][100];
int r, c, m;

void inline prt()
{
    for(int i = 0; i < r; ++i)
        puts(a[i]);
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int k = 1; k <= T; ++k)
    {
        scanf("%d%d%d", &r, &c, &m);
        int t = 0;
        printf("Case #%d:\n", k);

        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
                a[i][j] = '*';
            a[i][c] = 0;
        }

        a[0][0] = 'c';
        int cnt = r*c-m;

        if(cnt == 1)
        {
            prt();
            continue;
        }

        if(r == 1)
        {
            for(int i = 1; i < cnt; ++i)
                a[0][i] = '.';
            prt();
            continue;
        }

        if(c == 1)
        {
            for(int i = 1; i < cnt; ++i)
                a[i][0] = '.';
            prt();
            continue;
        }



        if(cnt % 2 == 1) goto F2;




        if(cnt < 4)
        {
            puts("Impossible");
            continue;
        }

        a[0][1] = a[1][0] = a[1][1] = '.';
        cnt -= 4;
        if(cnt == 0) goto F1;

        for(int i = 2; i < r; ++i)
        {
            a[i][0] = a[i][1] = '.';
            t += 2;
            if(t == cnt) goto F1;
        }

        for(int j = 2; j < c; ++j)
        {
            a[0][j] = a[1][j] = '.';
            t += 2;
            if(t == cnt) goto F1;
        }

        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j) if(a[i][j] == '*')
            {
                a[i][j] = '.';
                ++ t;
                if(t == cnt) goto F1;
            }

F1:
        prt();
        continue;

F2:
        if(cnt < 9 || r < 3 || c < 3)
        {
            puts("Impossible");
            continue;
        }

                  a[0][1] = a[0][2] = '.';
        a[1][0] = a[1][1] = a[1][2] = '.';
        a[2][0] = a[2][1] = a[2][2] = '.';
        cnt -= 9;
        if(cnt == 0) goto F1;

        for(int i = 3; i < r; ++i)
        {
            a[i][0] = a[i][1] = '.';
            t += 2;
            if(t == cnt) goto F1;
        }

        for(int j = 3; j < c; ++j)
        {
            a[0][j] = a[1][j] = '.';
            t += 2;
            if(t == cnt) goto F1;
        }

        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j) if(a[i][j] == '*')
            {
                a[i][j] = '.';
                ++ t;
                if(t == cnt) goto F1;
            }
    }
}

