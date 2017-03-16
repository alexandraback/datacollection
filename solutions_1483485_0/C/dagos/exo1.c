#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char translation[256];
char caractere[128];


typedef struct {
    char in[128];
    char out[128];
} S_VALEURS;

S_VALEURS valeurs[32];
int nb_tests;
int i;

void charger_valeurs(FILE *fichier)
{
    char ligne[256];

    for(i=0; i<256; i++) translation[i] = 0;

    // ejp mysljylc kd kxveddknmc re jsicpdrysi
    // our language is impossible to understand

    // rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
    // there are twenty six factorial possibilities

    // de kr kd eoya kw aej tysr re ujdr lkgc jv
    // so it is okay if you want to just give up

    translation[' '] = ' ';
    translation['a'] = 'y';
    translation['b'] = 'h';
    translation['c'] = 'e';
    translation['d'] = 's';
    translation['e'] = 'o';
    translation['f'] = 'c';
    translation['g'] = 'v';
    translation['h'] = 'x';
    translation['i'] = 'd';
    translation['j'] = 'u';
    translation['k'] = 'i';
    translation['l'] = 'g';
    translation['m'] = 'l';
    translation['n'] = 'b';
    translation['o'] = 'k';
    translation['p'] = 'r';
    translation['q'] = 'z';
    translation['r'] = 't';
    translation['s'] = 'n';
    translation['t'] = 'w';
    translation['u'] = 'j';
    translation['v'] = 'p';
    translation['w'] = 'f';
    translation['x'] = 'm';
    translation['y'] = 'a';
    translation['z'] = 'q';

    fgets(ligne, 128, fichier);
    nb_tests = atoi(ligne);

    for(i=0; i<nb_tests; i++)
    {
        fgets(ligne, 128, fichier);
        strcpy(valeurs[i].in, ligne);
    }
}


void analyser_valeurs(void)
{
    int j;
    char val;
    for(i=0; i<nb_tests; i++)
    {
        for(j=0; j<strlen(valeurs[i].in); j++)
        {
            val = translation[valeurs[i].in[j]];
            if((valeurs[i].in[j] == 10) || (valeurs[i].in[j] == 13)) continue;
            if(val == 0)
            {
                printf("ERREUR TRANSLATION: %c!!!!!\n", valeurs[i].in[j]);
            }
            valeurs[i].out[j] = val;
        }
        valeurs[i].out[j] = 0;
    }
}


void ecrire_resultats(FILE *fichier)
{
    for(i=0; i<nb_tests; i++)
    {
        fprintf(fichier, "Case #%d: %s\n", i+1, valeurs[i].out);
    }
}


int main(int argc,
         char *argv[])
{
    FILE               *fichier_in;              // Fichier d'entrée (flux)
    FILE               *fichier_out;             // Fichier de sortie (flux)

    // Ouverture fichier d'entrée
    fichier_in = fopen("./exo1.in", "r");
    if(fichier_in == NULL)
    {
        printf("ERREUR OUVERTURE FICHIER IN\n");
        return(-1);
    }

    // Ouverture fichier de sortie
    fichier_out = fopen("./exo1.out", "w+");
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
