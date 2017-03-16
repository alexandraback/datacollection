//
//  main.cpp
//  C
//
//  Created by Matjaz Leonardis on 02/05/2015.
//  Copyright (c) 2015 Matjaz Leonardis. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int T;

int main() {
    
    scanf("%d",&T);
    
    for (int case_n=1;case_n<=T;case_n++){
        int N;
        scanf("%d",&N);
        int nH=0;
        
        vector<pair<long long,long long> > walker;
        
        for (int i=0;i<N;i++){
            
            long long D,H,M;
            
            scanf("%lld %lld %lld",&D,&H,&M);
            
            for (int j=0;j<H;j++) walker.push_back(make_pair((M+j)*(360-D), (M+j)));
            
        }
        
        sort(walker.begin(),walker.end());
        
        
        if (nH>2){
        
        // How many of the original hikers do we cross before they pass the 0 line for the first time
        
        
        
      //  long long res=nH;
        
        for (int i=0;i<nH;i++){
            
            
            
            
            
        } } else{
            
            if ( walker[1].first >= walker[0].first+walker[0].second*360 ) printf("Case #%d: %ld\n",case_n,1L); else printf("Case #%d: %ld\n",case_n,0L);
            continue;
            
        }
        
      //  printf("Case #%d: %lld\n",case_n,res);
        
        
    }
    
   
    return 0;
}
