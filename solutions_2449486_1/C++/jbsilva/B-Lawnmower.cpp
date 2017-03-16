// ============================================================================
//
//       Filename:  B-Lawnmower.cpp
//
//    Description:  Problem B. Lawnmower
//                  Qualification Round 2013
//
//        Version:  1.0
//        Created:  12/Apr/2013 21:10:24
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


bool bitmap[101][101];
int T, N, M; // T = Casos, N = linhas, M = colunas


// Todos os elementos do bitmap devem estar marcados para dar certo
inline bool verifica()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!bitmap[i][j])
                return false;
    return true;
}


int main()
{
    int height[101][101];
    int max_lin[101], max_col[101]; // max_lin[i] -> maior elemento da linha i

    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        memset(max_lin, 0, sizeof(max_lin));
        memset(max_col, 0, sizeof(max_col));
        memset(bitmap, 0, sizeof(bitmap));

        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &height[i][j]);

                if (height[i][j] > max_lin[i])
                    max_lin[i] = height[i][j];
                if (height[i][j] > max_col[j])
                    max_col[j] = height[i][j];
            }

        printf("Case #%d: ", caso);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (height[i][j] == max_lin[i] || height[i][j] == max_col[j])
                    bitmap[i][j] = 1;

        puts(verifica() ? "YES" : "NO");
    }

    return 0;
}

