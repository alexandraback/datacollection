#include <algorithm>
#include <cstdio>
#include <cstdlib> // TODO
using namespace std;

const int MAX_NB_LINS = 50;
const int MAX_NB_COLS = 50;
const int nbDirs = 8;
const int dirLin[nbDirs] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dirCol[nbDirs] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool dejaVu[MAX_NB_LINS][MAX_NB_COLS];
char grille[MAX_NB_LINS][MAX_NB_COLS];
int nbLins, nbCols, nbMines;

inline bool DansGrille(int iLin, int iCol) {
    return iLin >= 0 && iLin < nbLins && iCol >= 0 && iCol < nbCols;
}

int CompterMinesVoisins(int iLin, int iCol) {
    int nbMinesVoisins = 0;
    
    for (int iDir = 0; iDir < nbDirs; iDir++) {
        int dLin = iLin + dirLin[iDir];
        int dCol = iCol + dirCol[iDir];
        
        if (DansGrille(dLin, dCol) && grille[dLin][dCol] == '*')
            nbMinesVoisins++;
    }
    
    return nbMinesVoisins;
}

void Parcourir(int iLin, int iCol) {        
    if (CompterMinesVoisins(iLin, iCol) > 0)
        return;
        
    for (int iDir = 0; iDir < nbDirs; iDir++) {
        int dLin = iLin + dirLin[iDir];
        int dCol = iCol + dirCol[iDir];
        
        if (DansGrille(dLin, dCol) && grille[dLin][dCol] != '*' && !dejaVu[dLin][dCol]) {
            dejaVu[dLin][dCol] = true;
            Parcourir(dLin, dCol);
        }
    }
}

bool TesterGagnant() {
    if (nbMines == nbLins * nbCols - 1)
        return true;
        
    for (int iLin = 0; iLin < nbLins; iLin++)
        for (int iCol = 0; iCol < nbCols; iCol++)
            dejaVu[iLin][iCol] = false;

    bool parcouru = false;

    for (int iLin = 0; iLin < nbLins && !parcouru; iLin++)
        for (int iCol = 0; iCol < nbCols && !parcouru; iCol++)
            if (grille[iLin][iCol] == '.' && CompterMinesVoisins(iLin, iCol) == 0) {
                dejaVu[iLin][iCol] = true;
                Parcourir(iLin, iCol);
                parcouru = true;
            }

    for (int iLin = 0; iLin < nbLins; iLin++)
        for (int iCol = 0; iCol < nbCols; iCol++)
            if (!dejaVu[iLin][iCol] && grille[iLin][iCol] == '.')
                return false;

    return true;
}

bool GenererGrille(int iLin, int iCol, int iMine) {
    if (iMine < 0)
        return false;

    if (iLin == nbLins)
        return iMine == 0 && TesterGagnant();
    
    int succCol = (iCol + 1) % nbCols;
    int succLin = iLin + (iCol + 1) / nbCols;
    
    grille[iLin][iCol] = '*';
    
    if (GenererGrille(succLin, succCol, iMine - 1))
        return true;
    
    grille[iLin][iCol] = '.';
    return GenererGrille(succLin, succCol, iMine);
}

void GenererClic() {
    for (int iLin = 0; iLin < nbLins; iLin++)
        for (int iCol = 0; iCol < nbCols; iCol++)
            if (grille[iLin][iCol] == '.' && (nbMines == nbLins * nbCols - 1 || CompterMinesVoisins(iLin, iCol) == 0)) {
                grille[iLin][iCol] = 'c';
                return;
            }
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    
    for (int iTest = 1; iTest <= nbTests; iTest++) {
        scanf("%d%d%d", &nbLins, &nbCols, &nbMines);
        
        for (int iLin = 0; iLin < nbLins; iLin++)
            for (int iCol = 0; iCol < nbCols; iCol++)
                grille[iLin][iCol] = '.';
        
        printf("Case #%d:\n", iTest);
        
        if (GenererGrille(0, 0, nbMines)) {
            GenererClic();
            
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
