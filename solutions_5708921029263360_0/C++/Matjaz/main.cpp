//
//  main.cpp
//  outfits
//
//  Created by Matjaz Leonardis on 08/05/2016.
//  Copyright © 2016 Matjaz Leonardis. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int T,J,P,S,K;

int pairCount[10][10][3];

int jacket[30];
int pants[30];
int suits[30];

//
//9 22102794
//18 62580637
//27 134217727


//7 22102544
//14 62512176
//21 134217235
//22 134217239
//23 134217247
//24 134217279
//25 134217343
//26 134217471
//27 134217727

int precomputedBestNumber[10] = {9,18,27,27,27,27,27,27,27,27};
int precomputedBestConfiguration[10] = {22102794,62580637,134217727,134217727,134217727,134217727,134217727,134217727,134217727,134217727};

int main(int argc, const char * argv[]) {
    
    scanf("%d",&T);
    
    for (int caseNumber = 1; caseNumber <= T; caseNumber++){
        scanf("%d %d %d %d",&J,&P,&S,&K);
        
        int total = 0;
        
        for (int i=0;i<J;i++)
            for (int j=0;j<P;j++)
                for(int k=0;k<S;k++){
                    jacket[total] = i;
                    pants[total] = j;
                    suits[total] = k;
                    total++;
                }
        int bestNumber = 0;
        int bestConfiguration = 0;
        
        if (J == 3 && P == 3 && S == 3){
            bestNumber = precomputedBestNumber[K-1];
            bestConfiguration = precomputedBestConfiguration[K-1];
        } else {
        
        for (int i = 0;i < (1<<total);i++){
            memset(pairCount, 0, sizeof(pairCount));
            bool good = true;
            
            for (int j=0;j<total;j++) if (( i & (1<<j)) != 0) {
                pairCount[jacket[j]][pants[j]][0]++;
                pairCount[jacket[j]][suits[j]][1]++;
                pairCount[pants[j]][suits[j]][2]++;
                if (pairCount[jacket[j]][pants[j]][0] > K || pairCount[jacket[j]][suits[j]][1] > K || pairCount[pants[j]][suits[j]][2] > K){
                    good = false;
                    break;
                }
            }
            
            if (good && __builtin_popcount(i) > bestNumber){
                bestNumber = __builtin_popcount(i);
                bestConfiguration = i;
            }
        }
        }
        printf("Case #%d: %d\n",caseNumber,bestNumber);
        for (int i=0;i<total;i++) if ((bestConfiguration & (1<<i)) != 0){
            printf("%d %d %d\n",jacket[i]+1,pants[i]+1,suits[i]+1);
        }
        
        if (J == 3 && P == 3 && S == 3) fprintf(stderr, "%d %d\n",bestNumber,bestConfiguration);
        
        fprintf(stderr, "Done case %d\n",caseNumber);
    }
    

    return 0;
}
