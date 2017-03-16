#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int A;
    int B;
    int nb_digits;
    int out;
} S_VALEURS;



S_VALEURS valeurs[4096];
int nb_tests;
int i;

void charger_valeurs(FILE *fichier)
{
    char ligne[4096];
    char *valeur;
    char *indice;
    int j;

    fgets(ligne, 4096, fichier);
    nb_tests = atoi(ligne);

    for(i=0; i<nb_tests; i++)
    {
        fgets(ligne, 4096, fichier);
        valeur = ligne;

        indice = strstr(valeur, " ");
        *indice = 0;
        valeurs[i].A = atoi(valeur);
        valeurs[i].nb_digits = strlen(valeur);
        valeur = indice + 1;
        valeurs[i].B = atoi(valeur);

    }
}


void analyser_valeurs(void)
{
    int val_norm;
    int val_rare;
    int j, k, x;
    char val_char[64];
    char val_permut[64];
    int m;
    int tab_m[1024];
    int nb_m = 0;
    int skip;
    int w;

    for(i=0; i<nb_tests; i++)
    {
        valeurs[i].out = 0;
        // Parcours des valeurs possibles pour n
        for(j=valeurs[i].A; j<=valeurs[i].B; j++)
        {
            sprintf(val_char, "%d", j);
            nb_m = 0;
            // Recherche des valeurs possibles pour m
            for(x=1; x<valeurs[i].nb_digits; x++)
            {
                // Permutation
                for(k=1; k<valeurs[i].nb_digits; k++)
                {
                    val_permut[k] = val_char[k - 1];
                }
                val_permut[0] = val_char[valeurs[i].nb_digits - 1];
                val_permut[valeurs[i].nb_digits] = 0;
                strcpy(val_char, val_permut);
                m = atoi(val_permut);
                if((m > j) && (m <= valeurs[i].B))
                {

                    //if(i==28) printf("Couple: %d / %d / %s / %s\n", j, m, val_char, val_permut);

                    // Ajout de la paire si elle n'est pas déjà présente
                    skip = 0;
                    for(w=0; w<nb_m; w++)
                    {
                        if(tab_m[w] == m) skip = 1;
                    }
                    if(skip == 0)
                    {
                        tab_m[nb_m] = m;
                        nb_m++;
                        valeurs[i].out++;
                    }
                }
            }
        }
    }
}


void ecrire_resultats(FILE *fichier)
{
    for(i=0; i<nb_tests; i++)
    {
        fprintf(fichier, "Case #%d: %d\n", i+1, valeurs[i].out);
    }
}


int main(int argc,
         char *argv[])
{
    FILE               *fichier_in;              // Fichier d'entrée (flux)
    FILE               *fichier_out;             // Fichier de sortie (flux)

    // Ouverture fichier d'entrée
    fichier_in = fopen("./exo3.in", "r");
    if(fichier_in == NULL)
    {
        printf("ERREUR OUVERTURE FICHIER IN\n");
        return(-1);
    }

    // Ouverture fichier de sortie
    fichier_out = fopen("./exo3.out", "w+");
    if(fichier_out == NULL)
    {
        printf("ERREUR OUVERTURE FICHIER OUT\n");
        return(-1);
    }

    // Chargement des paramètres d'entrée
    charger_valeurs(fichier_in);

    // Calcul des paramètres de sortie
    analyser_valeurs();

    // Ecriture du fichier
    ecrire_resultats(fichier_out);

    // Fermeture des fichiers
    fclose(fichier_in);
    fclose(fichier_out);

    return(0);
}
