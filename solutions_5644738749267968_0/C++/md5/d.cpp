#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_NB_MASSES = 1000;

bool pris[MAX_NB_MASSES];
double massesNao[MAX_NB_MASSES];
double massesKen[MAX_NB_MASSES];
int nbMasses;

int JouerFourbe() {  
    int gaucheKen = 0, droiteKen = nbMasses - 1;
    int nbPoints = 0;
  
    for (int iMasse = 0; iMasse < nbMasses; iMasse++) {
        if (massesNao[iMasse] > massesKen[gaucheKen]) {
            gaucheKen++;
            nbPoints++;
        } else
            droiteKen--;
    }
  
    return nbPoints;
}

int JouerNormal() {
    for (int iMasse = 0; iMasse < nbMasses; iMasse++)
        pris[iMasse] = false;
    
    int nbPoints = 0;
    
    for (int iMasseNao = 0; iMasseNao < nbMasses; iMasseNao++) {
        int iPremiereMasse = -1, iMasseDessus = -1;
    
        for (int iMasseKen = 0; iMasseKen < nbMasses; iMasseKen++)
            if (!pris[iMasseKen]) {
                if (iPremiereMasse == -1)
                    iPremiereMasse = iMasseKen;
                
                if (massesKen[iMasseKen] > massesNao[iMasseNao]) {
                    iMasseDessus = iMasseKen;
                    break;
                }
            }
        
        if (iMasseDessus == -1) {
            pris[iPremiereMasse] = true;
            nbPoints++;
        }
        else
            pris[iMasseDessus] = true;
    }
    
    return nbPoints;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    
    for (int iTest = 1; iTest <= nbTests; iTest++) {
        scanf("%d", &nbMasses);
      
        for (int iMasse = 0; iMasse < nbMasses; iMasse++)
            scanf("%lf", &massesNao[iMasse]);

        for (int iMasse = 0; iMasse < nbMasses; iMasse++)
            scanf("%lf", &massesKen[iMasse]);

        sort(massesNao, massesNao + nbMasses);
        sort(massesKen, massesKen + nbMasses);
        
        printf("Case #%d: %d %d\n", iTest, JouerFourbe(), JouerNormal());
    }
    
    return 0;
}
