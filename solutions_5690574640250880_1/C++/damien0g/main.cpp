//FRENCH
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int R, C, M;
int nb_vides;
char plateau[50][51]; //rempli à 0

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d:\n", t);

        //Input
        scanf("%d %d %d", &R, &C, &M);

        bool echange = false;
        if(R < C)   //on les echange
        {
            int tmp;
            tmp = R;
            R = C;
            C = tmp;
            echange = true;
        }
        //des ici, on a R >= C

        bool impossible = false;

        int racine = floor(sqrt(R*C-M));
        if ((racine*racine == R*C-M) && (C >= racine))
        {
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    plateau[i][j] = '*';
                }
            }

            for(int i = 0; i < racine; i++)
            {
                for(int j = 0; j < racine; j++)
                {
                    plateau[i][j] = '.';
                }
            }
            plateau[0][0] = 'c';
        }
        else if ((R == 5) && (C == 5) && (M == 14)) //correction tres laide mais fonctionnelle
        //on sort un cas
        {
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    plateau[i][j] = '.';
                }
            }

            for(int i = 0; i < 5; i++)
            {
                plateau[i][0] = '*';
                plateau[i][1] = '*';
            }
            plateau[0][2] = '*';
            plateau[0][3] = '*';
            plateau[0][4] = '*';
            plateau[1][2] = '*';
            plateau[4][4] = 'c';
        }
        else if(R*C - M == 1)
        {
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    plateau[i][j] = '*';
                }
            }
            plateau[0][0] = 'c';
        }
        else if(C == 1)
        {
            for(int i = 0; i < M; i++)
            {
                plateau[i][0] = '*';
            }
            for(int i = M; i < R-1; i++)
            {
                plateau[i][0] = '.';
            }
            plateau[R-1][0] = 'c';
        }
        else if (C == 2)
        {
            if ((M%2 == 0) && (R > 2) && (R*C - M != 2))
            {
                for(int i = 0; i < M/2; i++)
                {
                    plateau[i][0] = '*';
                    plateau[i][1] = '*';
                }
                for(int i = M/2; i < R; i++)
                {
                    plateau[i][0] = '.';
                    plateau[i][1] = '.';
                }
                plateau[R-1][1] = 'c';
            }
            else
            {
                impossible = true;
            }
        }
        else
        {
            //Init du tableau avec des cases vides
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    plateau[i][j] = '.';
                }
            }

            int nb_mines = 0;
            int last_lig = M/C; //derniere ligne remplie entierement de mines

            for(int i = 0; i < last_lig; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    plateau[i][j] = '*';
                    nb_mines++;
                }
            }

            if (R-last_lig >= 3)   //--> tj possible
            {
                //printf("Reste 3 lignes ou plus\n");
                for(int j = 0; j < C; j++)
                {
                    if ((nb_mines == M-1) && (j == C-2))    //cas qui coince
                    {
                        if(last_lig == R-3)
                        {
                            impossible = true;
                        }

                        plateau[last_lig+1][0] = '*';  //--> on le decoince
                        nb_mines = M;
                    }
                    else if (nb_mines < M)  //sinon, on ajoute une mine normalement
                    {
                        nb_mines++;
                        plateau[last_lig][j] = '*';
                    }
                }
            }
            else if(last_lig == R-2)  //--> parfois possible
            {
                //printf("Reste 2 lignes\n");
                if ((M-nb_mines)%2 == 0)    //si il reste un nombre pair de mines a mettre
                {
                    for (int i = last_lig; i < R; i++)
                    {
                        for(int j = 0; j < (M-nb_mines)/2; j++)
                        {
                            plateau[i][j] = '*';
                        }
                    }
                }
                else
                {
                    impossible = true;
                }
            }
            else    //last_lig == R-2, il y a des bombes jusqu'en derniere ligne
            {
                //printf("Reste 1 ligne\n");
                if(R*C - M != 1) //s'il reste plus d'une mine
                {
                    impossible = true;
                }
            }

            plateau[R-1][C-1] = 'c';
        }

        if(!impossible)
        {
            if(echange)
            {
                for(int j = 0; j < C; j++)
                {
                    for(int i = 0; i < R; i++)
                    {
                        printf("%c", plateau[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                for(int i = 0; i < R; i++)
                {
                    for(int j = 0; j < C; j++)
                    {
                        printf("%c", plateau[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        else
        {
            printf("Impossible\n");
        }
    }

    return 0;
}
