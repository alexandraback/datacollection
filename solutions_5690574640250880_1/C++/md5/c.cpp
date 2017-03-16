#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_NB_LINS = 50;
const int MAX_NB_COLS = 50;
enum { TYPE_LIN, TYPE_COL };

char grille[MAX_NB_LINS][MAX_NB_COLS];
int nbLins, nbCols, nbMines;

void PlacerFigure(int nbLinsFig, int nbColsFig, int ajoutFig, int typeAjout) {
    for (int iLin = 0; iLin < nbLinsFig; iLin++)
        for (int iCol = 0; iCol < nbColsFig; iCol++)
            grille[iLin][iCol] = '.';
    
    if (typeAjout == TYPE_LIN)
        for (int iCol = 0; iCol < ajoutFig; iCol++)
            grille[nbLinsFig][iCol] = '.';
    else
        for (int iLin = 0; iLin < ajoutFig; iLin++)
            grille[iLin][nbColsFig] = '.';
        
    grille[0][0] = 'c';
}

bool PlacerMines() {
    int nbPlaces = nbLins * nbCols - nbMines;

    if (nbPlaces == 1) {
        PlacerFigure(0, 0, 0, 0);
        return true;
    } else if (nbLins == 1) {
        PlacerFigure(0, nbPlaces, 0, 0);          
        return true;
    } else if (nbCols == 1) {
        PlacerFigure(nbPlaces, 0, 0, 0);
        return true;
    }

    for (int iDiv = 2; iDiv <= nbPlaces; iDiv++) {
        int coteA = iDiv;
        int coteB = nbPlaces / iDiv;
        int reste = nbPlaces % iDiv;
        
        if (coteA == 1 || coteB == 1 || reste == 1)
            continue;

        int ajout = reste != 0;

        if (coteA + ajout <= nbLins && coteB <= nbCols && reste <= nbCols) {
            PlacerFigure(coteA, coteB, reste, TYPE_LIN);
            return true;
        } else if (coteA <= nbLins && coteB + ajout <= nbCols && reste <= nbLins) {
            PlacerFigure(coteA, coteB, reste, TYPE_COL);
            return true;
        } else if (coteB + ajout <= nbLins && coteA <= nbCols && reste <= nbCols) {
            PlacerFigure(coteB, coteA, reste, TYPE_LIN);
            return true;
        } else if (coteB <= nbLins && coteA + ajout <= nbCols && reste <= nbLins) {
            PlacerFigure(coteB, coteA, reste, TYPE_COL);
            return true;
        }
    }
    
    return false;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    
    for (int iTest = 1; iTest <= nbTests; iTest++) {
        scanf("%d%d%d", &nbLins, &nbCols, &nbMines);
        
        for (int iLin = 0; iLin < nbLins; iLin++)
            for (int iCol = 0; iCol < nbCols; iCol++)
                grille[iLin][iCol] = '*';
        
        printf("Case #%d:\n", iTest);
        
        if (PlacerMines()) {
            for (int iLin = 0; iLin < nbLins; iLin++) {
                for (int iCol = 0; iCol < nbCols; iCol++)
                    putchar(grille[iLin][iCol]);
            
                putchar('\n');
            }
        } else
            puts("Impossible");
    }
    
    return 0;
}
