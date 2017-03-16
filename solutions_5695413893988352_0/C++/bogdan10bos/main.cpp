#include <bits/stdc++.h>

using namespace std;

#define FILE_IO

char a[105], b[105];

bool coincide(int x, char s[], int N)
{
    if(N == 1)
    {
        return ( (x == s[1] - '0') || s[1] == '?' );
    }
    else if(N == 2)
        return ( (x % 10 == s[2] - '0' || s[2] == '?') && (x / 10 == s[1] - '0' || s[1] == '?') );
    else
        return ( (x % 10 == s[3] - '0' || s[3] == '?') && (x / 100 == s[1] - '0' || s[1] == '?') && ( (x / 10) % 10 == s[2] - '0' || s[2] == '?' ) );

    return 0;
}

void printWithExactDigits(int a, int n)
{
    if(n == 1)
        printf("%d", a);
    else if(n == 2)
    {
        if(a <= 9)
            printf("0%d", a);
        else
            printf("%d", a);
    }
    else
    {
        if(a <= 9)
            printf("00%d", a);
        else if(a <= 99)
            printf("0%d", a);
        else
            printf("%d", a);
    }
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        int N = strlen(a + 1);
        int vmax = 0;
        if(N == 1)  vmax = 9;
        else if(N == 2) vmax = 99;
        else        vmax = 999;

        int n1, n2;
        n1 = n2 = 0;
        int dif = 10 * vmax;
        for(int i = 0; i <= vmax; i++)
            if( coincide(i, a, N) )
                for(int j = 0; j <= vmax; j++)
                {
                    int jj = i - j;
                    if(jj >= 0)
                    {
                        if( coincide(jj, b, N) )
                        {
                            if(dif > j)
                            {
                                dif = j;
                                n1 = i;
                                n2 = jj;
                            }
                            else if(dif == j && n1 > i)
                            {
                                n1 = i;
                                n2 = jj;
                            }
                            else if(dif == j && n1 == i && n2 > jj)
                                n2 = jj;
                            break;
                        }
                    }

                    jj = i + j;
                    if(jj <= vmax)
                    {
                        if( coincide(jj, b, N) )
                        {
                            if(dif > j)
                            {
                                dif = j;
                                n1 = i;
                                n2 = jj;
                            }
                            else if(dif == j && n1 > i)
                            {
                                n1 = i;
                                n2 = jj;
                            }
                            else if(dif == j && n1 == i && n2 > jj)
                                n2 = jj;
                            break;
                        }
                    }
                }

        printf("Case #%d: ", t);
        printWithExactDigits(n1, N);
        printf(" ");
        printWithExactDigits(n2, N);
        printf("\n");
    }

    return 0;
}
