//
//  main.cpp
//  AlgorithmStudy
//
//  Created by Young Seok Kim on 1/9/14.
//  Copyright (c) 2014 Young Seok Kim. All rights reserved.
//





#include <stdio.h>
#include <string.h>


// Codejam 2014 round1C
// Problem A.

int testcases; // 1~100





int main(int argc, const char * argv[])
{
    freopen("A-small-attempt2.in.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    scanf("%d", &testcases);
    for (int i=1; i<=testcases; i++) {
        int p,q;
        scanf("%d/%d",&p, &q);
        bool impossible = false;
        int cnt=1;
        int checkq = 0;
        checkq = q;
        
        while (checkq!=0) {
            if (checkq ==1) {
                break;
            }
            if (checkq%2==1){
                impossible = true;
                break;
            }
            else {
                checkq = checkq / 2;
            }
        }
        
        while (true) {
            int temp = q/2;
            if (p-temp >= 0) {
                break;
            }
            else {
                cnt++;
                q = q/2;
            }
        }
        
        
        
        
        
        
        /*
        while (true) {
            int temp = q/2;
            if (q%2==1) {
                impossible = true;
                break;
            }
            else if (p-temp >= 0) {
                break;
            }
            else {
                cnt++;
                q = q/2;
            }
            
            
        }
        */
        
        if (!impossible) {
            printf("Case #%d: %d\n",i, cnt);
        }
        else {
            printf("Case #%d: impossible\n",i);
        }
    
        
    }
    
}


