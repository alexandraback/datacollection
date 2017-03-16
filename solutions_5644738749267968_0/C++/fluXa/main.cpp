#include <cstdio>
#include <set>

using namespace std;

set<float> wKen;
set<float> wNaomi;
set<float> wKen2;
set<float> wNaomi2;

set<float>::iterator kenWar(float val) {
    // Ken look for a smallest larger entry than val
    set<float>::iterator iter = wKen.lower_bound(val);
    if (iter != wKen.end()) {
        return iter;
    } else {
        return wKen.begin();
    }
}

void handleOneCase() {
    int numBlocks;
    scanf("%d\n", &numBlocks);
    
    wNaomi.clear();
    for (int i = 0; i < numBlocks; ++i) {
        float tmp;
        scanf("%f", &tmp);
        wNaomi.insert(tmp);
    }
    scanf("\n");
    wKen.clear();
    for (int i = 0; i < numBlocks; ++i) {
        float tmp;
        scanf("%f", &tmp);
        wKen.insert(tmp);
    }
    scanf("\n");
   
    // backup copies
    wKen2 = wKen;
    wNaomi2 = wNaomi;
    // War
    
    int naomiWarScore = 0;
    for (int i = 0; i < numBlocks; ++i) {
        set<float>::iterator neomiMin = wNaomi.begin();
        float naomiVal = *neomiMin;
        wNaomi.erase(neomiMin);
        
        set<float>::iterator kenIt = kenWar(naomiVal);
        if (*kenIt < naomiVal) naomiWarScore++;
        wKen.erase(kenIt);
    }
    
    // Deceitful War
 
    wKen = wKen2;
    wNaomi = wNaomi2;
    int naomiDecWarScore = 0;
    for (int i = 0; i < numBlocks; ++i) {
        set<float>::iterator naomiChosen;
        set<float>::iterator naomiMin = wNaomi.begin();
        set<float>::iterator naomiMax = wNaomi.end(); naomiMax--;
  
        set<float>::iterator kenMin = wKen.begin();
        set<float>::iterator kenMax = wKen.end(); kenMax--;
        float naomiTold;
        
        if (*naomiMax > *kenMax) { // a win is possible use the lightest that is a heavier than ken's lightest he'll play
            naomiChosen = wNaomi.lower_bound(*kenMin);
            naomiTold = *kenMax + 0.0001f;
        } else {
            // A win is impossible as ken will always beat a stone
            // play the lightest stone but make ken play its heaviest
            naomiChosen = naomiMin;
            naomiTold = *kenMax - 0.0001f;
        }
        
        wNaomi.erase(naomiChosen);
        
        set<float>::iterator kenIt = kenWar(naomiTold);
        
        if (*kenIt < naomiTold) naomiDecWarScore++;
        wKen.erase(kenIt);
    }

    printf("%d %d", naomiDecWarScore, naomiWarScore);
}


int main(int argc, const char * argv[])
{
    int numCases = 0;
    scanf("%d\n", &numCases);
    
    for (int count = 1; count <= numCases; ++count) {
        printf("Case #%d: ", count);
        handleOneCase();
        printf("\n");
    }
    return 0;
}

