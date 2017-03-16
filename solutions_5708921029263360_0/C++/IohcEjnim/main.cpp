#include <stdio.h>

int T, J, P, S, K;
int fill[11][11][11];

int min(int a, int b) {return a < b ? a : b;}

int main()
{
    freopen("/Users/IohcEjnim/Downloads/C-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/IohcEjnim/Downloads/result.txt", "w", stdout);
    int tn, i, j, k;
    scanf("%d", &T);
    
    for (tn = 1; tn <= T; tn++)
    {
        scanf("%d %d %d %d", &J, &P, &S, &K);
        for (i = 0; i < J; i++)
            for (j = 0; j < P; j++)
                for (k = 0; k < S; k++)
                    fill[i][j][k] = 0;
        
        for (i = 0; i < min(S, K); i++)
            fill[0][0][i] = 1;
        for (i = 0; i < P; i++)
            for (j = 0; j < S; j++)
                fill[0][i][j] = fill[0][0][(j-i+S)%S];
        for (i = 0; i < J; i++)
            for (j = 0; j < P; j++)
                for (k = 0; k < S; k++)
                    fill[i][j][k] = fill[0][(j-i+P)%P][k];
        
        printf("Case #%d: %d\n", tn, J*P*min(S, K));
        for (i = 0; i < J; i++)
            for (j = 0; j < P; j++)
                for (k = 0; k < S; k++)
                    if (fill[i][j][k]) printf("%d %d %d\n", i+1, j+1, k+1);
    }
}