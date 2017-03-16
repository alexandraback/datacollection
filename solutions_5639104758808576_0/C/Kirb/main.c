
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(a,b) (a > b ? b : a)
#define max(a,b) (a > b ? a : b)

int main(int p_Argc, char  **p_Argv)
{

    char* filename="D:\\Documents\\CodeJam\\codeJam\\small.txt";
//    char* filename="D:\\Documents\\CodeJam\\codeJam\\large.txt";
//    char* filename="D:\\Documents\\CodeJam\\codeJam\\test.txt";

    FILE* pFile = NULL;
    pFile = fopen(filename, "r");

    if (pFile == NULL){printf("Erreur lors de l'ouverture du fichier"); return 1;}
    int T,Smax;

    fscanf(pFile, "%i", &T); fgetc(pFile);

    int audience[1000]={0};
    int leve,invite;
    char c;
    for (int l=0;l<T;l++){

            fscanf(pFile,"%i",&Smax);
            fgetc(pFile);
            for (int j=0;j<=Smax;j++)
            {
                fscanf(pFile,"%c",&c);
                audience[j]=c-48;
            }
            fgetc(pFile);

            leve = audience[0];
            invite=0;

            for (int k=1;k<=Smax;k++)
            {
                if (audience[k] > 0){
                        if (k-leve > 0 ) {
                            invite += (k-leve);
                            leve += (k-leve);
                        }
                        leve += audience[k];}
            }

       printf("Case #%i: %i\n",l+1,invite);
    }

    fclose(pFile);

    return 0;

}





