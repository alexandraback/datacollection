#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int N;
    int S;
    int p;
    int val[4096];
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
        valeurs[i].N = atoi(valeur);
        valeur = indice + 1;

        indice = strstr(valeur, " ");
        *indice = 0;
        valeurs[i].S = atoi(valeur);
        valeur = indice + 1;

        indice = strstr(valeur, " ");
        *indice = 0;
        valeurs[i].p = atoi(valeur);
        valeur = indice + 1;

        for(j=0; j<valeurs[i].N; j++)
        {
            indice = strstr(valeur, " ");
            if(indice != NULL) *indice = 0;
            valeurs[i].val[j] = atoi(valeur);
            if(indice != NULL) valeur = indice + 1;
        }
    }
}


void analyser_valeurs(void)
{
    int val_norm;
    int val_rare;
    int j;

    for(i=0; i<nb_tests; i++)
    {
        valeurs[i].out = 0;
        // Calcul de la valeur à obtenir
        if(valeurs[i].p == 0)
        {
            valeurs[i].out = valeurs[i].N;
            continue;
        }

        val_norm = (valeurs[i].p - 1) * 3;
        val_rare = (valeurs[i].p - 1) + (valeurs[i].p - 1) + (valeurs[i].p - 2);
        if(valeurs[i].p == 1) val_rare = 1;
        for(j=0; j<valeurs[i].N; j++)
        {
            if(valeurs[i].val[j] > val_norm)
            {
                valeurs[i].out++;
            }
            else if(valeurs[i].val[j] >= val_rare)
            {
                if(valeurs[i].S > 0)
                {
                    valeurs[i].S = valeurs[i].S - 1;
                    valeurs[i].out++;
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
    fichier_in = fopen("./exo2.in", "r");
    if(fichier_in == NULL)
    {
        printf("ERREUR OUVERTURE FICHIER IN\n");
        return(-1);
    }

    // Ouverture fichier de sortie
    fichier_out = fopen("./exo2.out", "w+");
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
