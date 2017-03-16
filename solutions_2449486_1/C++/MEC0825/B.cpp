//
//  main.cpp
//  Google
//
//  Created by Mec0825 on 13-4-13.
//  Copyright (c) 2013年 Mec0825. All rights reserved.
//

#include <iostream>

int main()
{
    freopen("/Users/Mec0825/Documents/Google/2013/Qualification/B-in.txt", "r", stdin);
    freopen("/Users/Mec0825/Documents/Google/2013/Qualification/B-out.txt", "w", stdout);
    
    int numc;
    
    scanf("%d", &numc);
    
    for(int t = 0; t < numc; t++) {
        
        int num[110][110];
        int numr[110];
        int numc[110];
        int nnum[110][110];
        
        int row, col;
        scanf("%d%d", &row, &col);
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                scanf("%d", &num[i][j]);
            }
        }
        
        memset(numc, 0, sizeof(numc));
        memset(numr, 0, sizeof(numr));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(num[i][j] >= numr[i]) numr[i] = num[i][j];
            }
        }
        
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                if(num[j][i] >= numc[i]) numc[i] = num[j][i];
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                nnum[i][j] = (numr[i] < numc[j] ? numr[i] : numc[j]);
            }
        }
        
        bool success = 1;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(num[i][j] != nnum[i][j]) success = 0;
            }
        }
        
        if(success) printf("Case #%d: YES\n",t+1);
        else printf("Case #%d: NO\n",t+1);
    }
    
    return 0;
}
