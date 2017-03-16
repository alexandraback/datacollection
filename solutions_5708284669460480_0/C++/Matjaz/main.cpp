#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
using namespace std;


int T;


int main() {
    
    scanf("%d",&T);
    
    for (int case_number=1;case_number<=T;case_number++){
        int K,L,S;
        
        int letter_count[30];
        
        char alphabet[105];
        char target[105];
        
        memset(letter_count, 0, sizeof(letter_count));
        
        scanf("%d %d %d",&K,&L,&S);
        
        scanf("%s",alphabet);
        scanf("%s",target);
        
        for (int i=0;i<K;i++) letter_count[alphabet[i]-'A']++;
        
        long double expected=1.0;
        
        for (int i=0;i<L;i++) expected*=((long double) letter_count[target[i]-'A'])/((long double)K);
        
        expected*=(S-L+1);
        
        int maximum_number=0;
        
        int best_leftover=L;
        
        for (int i=L-1;i>=1;i--){
            
            bool valid_prefix=true;
            
            for (int j=0;j<L;j++){
                
                if (i+j>=L) break;
                
                if (target[j]!=target[i+j]){
                    valid_prefix=false;
                    break;
                }
                
            }
            
            if (valid_prefix) best_leftover=i;
            
            
        }
        
        
        maximum_number=(S-L)/best_leftover+1;
        
        bool possible=true;
        
        for (int i=0;i<L;i++) if (letter_count[target[i]-'A']==0) possible=false;
        if (!possible) maximum_number=0;
        
       // printf("%d %.7Lf\n",maximum_number,expected);
        
        printf("Case #%d: %.7Lf\n",case_number,maximum_number-expected);
        
    }
    
    
    
   
    return 0;
}
