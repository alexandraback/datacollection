// ============================================================================
//
//       Filename:  Problem_A-Tic_Tac_Toe_Tomek.cpp
//
//    Description:  Problem A. Tic-Tac-Toe-Tomek
//                  Qualification Round 2013
//
//        Version:  1.0
//        Created:  12/Apr/2013 20:05:40
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


char tab[5][5];


char vencedor(int soma)
{
    switch (soma)
    {
        case (4 * (int)'X'):
        case (3 * (int)'X' + (int)'T'):
            return 'X';
        case (4 * (int)'O'):
        case (3 * (int)'O' + (int)'T'):
            return 'O';
        default:
            return 'Z';
    }
}


char verifica()
{
    int soma;
    char v;

    // Horizontal
    for (int i = 0; i < 4; i++)
    {
        soma = 0;
        for (int j = 0; j < 4; j++)
            soma += (int)tab[i][j];
        if ((v = vencedor(soma)) != 'Z')
            return v;
    }

    // Vertical
    for (int j = 0; j < 4; j++)
    {
        soma = 0;
        for (int i = 0; i < 4; i++)
            soma += (int)tab[i][j];
        if ((v = vencedor(soma)) != 'Z')
            return v;
    }

    // Diagonal '\'
    soma = 0;
    for (int i = 0; i < 4; i++)
        soma += (int)tab[i][i];
    if ((v = vencedor(soma)) != 'Z')
        return v;

    // Diagonal '/'
    soma = 0;
    for (int i = 3, j = 0; i >= 0; i--, j++)
        soma += (int)tab[i][j];
    if ((v = vencedor(soma)) != 'Z')
        return v;

    return 'Z';
}


int main()
{
    int T;
    scanf("%d ", &T);

    for (int caso = 1; caso <= T; caso++)
    {
        bool tem_ponto = false;

        printf("Case #%d: ", caso);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%c", &tab[i][j]);
                if (tab[i][j] == '.')
                    tem_ponto = true;
            }
            getchar(); // \n
        }

        /* DEBUG
        putchar('\n');
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                printf("%c ", tab[i][j]);
            putchar('\n');
        }
        */

        switch (verifica())
        {
            case 'X':
                printf("X won\n"); break;
            case 'O':
                printf("O won\n"); break;
            case 'Z':
                if (tem_ponto)
                    printf("Game has not completed\n");
                else
                    printf("Draw\n");
        }

        getchar(); // \n
    }

    return 0;
}

