#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, R, C, mine, n;
int a[51][51];

int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        printf("Case #%d:\n", uu);
        scanf("%d%d%d", &R, &C, &mine);
        n = R * C - mine;
        if (R == 1)
        {
           printf("c");
           for (int i = 1; i < n; i++) printf(".");
           for (int i = 1; i <= mine; i++) printf("*");
           printf("\n");
           continue;
        }
        if (C == 1)
        {
           printf("c\n"); 
           for (int i = 1; i < n; i++) printf(".\n");
           for (int i = 1; i <= mine; i++) printf("*\n");
           continue;
        }
        if (n == 1)
        {
           for (int i = 1; i <= R; i++)    
           {
               for (int j = 1; j <= C; j++)
                   if (i == 1 && j == 1) printf("c");
                   else printf("*");
               printf("\n");
           }
           continue;
        }
        memset(a, 0, sizeof(a));
        bool ok = false;
        for (int i = 2; i <= C; i++)
        {
            int A = n / i, B = 0;
            if (n % i) B = 1; 
            if (A < 2 || A + B > R) continue;
            if (i != 2 && (n % i) == 1 && A != 2)
            {
                for (int j = 1; j < A; j++) 
                    for (int k = 1; k <= i; k++)
                        a[j][k] = 1;
                for (int k = 1; k < i; k++) a[A][k] = 1;
                a[A + 1][1] = a[A + 1][2] = 1;
                ok = true;
                break;
            } 
            if ((n % i) != 1) 
            {
                for (int j = 1; j <= A; j++) 
                    for (int k = 1; k <= i; k++)
                        a[j][k] = 1;
                for (int k = 1; k <= n % i; k++) a[A + 1][k] = 1;
                ok = true;
                break;
            }
        }
        if (!ok) 
        for (int i = 2; i <= R; i++)
        {
            int A = n / i, B = 0;
            if (n % i) B = 1; 
            if (A < 2 || A + B > C) continue;
            if (i != 2 && (n % i) == 1 && A != 2)
            {
                for (int j = 1; j < A; j++) 
                    for (int k = 1; k <= i; k++)
                        a[k][j] = 1;
                for (int k = 1; k < i; k++) a[k][A] = 1;
                a[1][A + 1] = a[2][A + 1] = 1;
                ok = true;
                break;
            } 
            if ((n % i) != 1) 
            {
                for (int j = 1; j <= A; j++) 
                    for (int k = 1; k <= i; k++)
                        a[k][j] = 1;
                for (int k = 1; k <= n % i; k++) a[k][A + 1] = 1;
                ok = true;
                break;
            }
        }
        if (!ok) printf("Impossible\n");
        else
            for (int i = 1; i <= R; i++)
            {
                 for (int j = 1; j <= C; j++)
                     if (i == 1 && j == 1) printf("c");
                     else if (a[i][j]) printf(".");
                          else printf("*");
                 printf("\n");
            }
    }
}
                           
                    
