// ============================================================================
//
//       Filename:  a-osmos.cpp
//
//    Description:  Code Jam - Round 1B - Problem A - Osmos
//
//        Version:  1.0
//        Created:  04/May/2013 13:03:11
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstdlib>


int T, A, N, m, motes[101];


inline int comp_int(const void* a, const void* b)
{
    // Nao vai dar overlow, pois a > 0 e b > 0
    return (*(int*)a - * (int*)b);
}


// 3 possibilidades:
//  -> Absorver
//  -> Inserir mote
//  -> Remover mote
int joga(int tam, int idx, int oprtns)
{
    //printf("tam = %d, idx = %d, oprtns = %d\n", tam, idx, oprtns);

    if (oprtns > 100)
        return 100;

    // Absorver
    int i = idx;
    while (i < N && tam > motes[i])
    {
        tam += motes[i++];
        //printf("Absorveu. tam = %d\n", tam);
    }

    if (i == N)
        return oprtns;

    // Remover
    int remover = oprtns + (N - i);

    // Inserir
    int inserir = joga(tam+tam-1, i, oprtns+1);
    //printf("inserir = %d\n", inserir);
    //printf("remover = %d\n", remover);

    if (inserir < remover)
        return inserir;
    else
        return remover;
}


int main()
{
    scanf("%d", &T);

    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%d %d", &A, &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &motes[i]);

        qsort(motes, N, sizeof(int), comp_int);

        printf("Case #%d: %d\n", caso, joga(A, 0, 0));
    }

    return 0;
}

