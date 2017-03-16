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
    freopen("/Users/Mec0825/Documents/Google/2013/Qualification/A.txt", "r", stdin);
    freopen("/Users/Mec0825/Documents/Google/2013/Qualification/A-out.txt", "w", stdout);
    
    int numc;
    
    scanf("%d", &numc);
    
    for(int t = 0; t < numc; t++) {
        
        char input[4][4];
        
        for(int i = 0; i < 4; i++) scanf("%s", input[i]);
        
        int cnt, xcnt, ocnt, won;
        
        cnt = won = 0;
        
        for(int i = 0; i < 4; i++) {
            
            xcnt = ocnt = 0;
            
            for(int j = 0; j < 4; j++) {
                if(input[i][j] == 'X') {xcnt++; cnt++;}
                else if(input[i][j] == 'O') {ocnt++; cnt++;}
                else if(input[i][j] == 'T') {xcnt++; ocnt++; cnt++;}
            }
            
            if(xcnt == 4) won = 1;
            else if(ocnt == 4) won = 2;
            
            xcnt = ocnt = 0;
            
            for(int j = 0; j < 4; j++) {
                if(input[j][i] == 'X') {xcnt++;}
                else if(input[j][i] == 'O') {ocnt++;}
                else if(input[j][i] == 'T') {xcnt++; ocnt++;}
            }
            
            
            if(xcnt == 4) won = 1;
            else if(ocnt == 4) won = 2;

        }
        
        xcnt = ocnt = 0;
        
        for(int i = 0; i < 4; i++) {
            if(input[i][i] == 'X') {xcnt++;}
            else if(input[i][i] == 'O') {ocnt++;}
            else if(input[i][i] == 'T') {xcnt++; ocnt++;}
        }
        
        if(xcnt == 4) won = 1;
        else if(ocnt == 4) won = 2;
        
        xcnt = ocnt = 0;
        
        for(int i = 0; i < 4; i++) {
            if(input[3-i][i] == 'X') {xcnt++;}
            else if(input[3-i][i] == 'O') {ocnt++;}
            else if(input[3-i][i] == 'T') {xcnt++; ocnt++;}
        }
        
        if(xcnt == 4) won = 1;
        else if(ocnt == 4) won = 2;
        
        if(won == 1) printf("Case #%d: X won\n",t+1);
        else if(won == 2) printf("Case #%d: O won\n",t+1);
        else if(cnt == 16) printf("Case #%d: Draw\n",t+1);
        else printf("Case #%d: Game has not completed\n",t+1);
    }
    
    return 0;
}
