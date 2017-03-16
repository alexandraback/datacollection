/* This program should be run with its input piped from the input file and its output piped to the output file. */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int iNumTests;
    int iNumBlocks;
    double *piNaomiBlocks, *piKenBlocks;
    
    cin >> iNumTests;
    
    for (int test = 1; test <= iNumTests; ++test) {
        int iDeceitfulPoints = 0, iWarPoints = 0;
        
        cin >> iNumBlocks;
        
        piNaomiBlocks = new double[iNumBlocks];
        piKenBlocks   = new double[iNumBlocks];
        
        for (int i = 0; i < iNumBlocks; ++i) {
            cin >> piNaomiBlocks[i];
        }
        
        for (int i = 0; i < iNumBlocks; ++i) {
            cin >> piKenBlocks[i];
        }
        
        sort(piNaomiBlocks, piNaomiBlocks + iNumBlocks);
        sort(piKenBlocks, piKenBlocks + iNumBlocks);
        
        int iNaomiTop    = iNumBlocks - 1;
        int iNaomiBottom = 0;
        for (int iKenTop = iNaomiTop; iKenTop >= 0; --iKenTop) {
            if (piNaomiBlocks[iNaomiTop] > piKenBlocks[iKenTop]) {
                ++iDeceitfulPoints;
                --iNaomiTop;
            } else {
                ++iNaomiBottom;
            }
        }
        
        int iKenBottom = 0;
        for (int i = 0; i < iNumBlocks; ++i) {
            int j;
            for (j = iKenBottom; j < iNumBlocks; ++j) {
                if (piNaomiBlocks[i] < piKenBlocks[j]) {
                    piKenBlocks[j] = 0.0;
                    break;
                }
            }
            if (j == iNumBlocks) {
                for (j = iKenBottom; j < iNumBlocks; ++j) {
                    if (piKenBlocks[j] != 0.0) {
                        piKenBlocks[j] = 0.0;
                        iKenBottom = j + 1;
                        break;
                    }
                }
                ++iWarPoints;
            }
        }
        
        delete[] piNaomiBlocks;
        delete[] piKenBlocks;
        
        cout << "Case #" << test << ": " << iDeceitfulPoints << ' ' << iWarPoints << endl;
    }
    
    return 0;
}
