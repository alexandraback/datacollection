//
//  main.cpp
//  codejam_A
//
//  Created by Chao on 4/9/16.
//  Copyright © 2016 Chao. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n = 0, caseIndex = 1;
    scanf("%d", &n);
    while (caseIndex <= n){
        int num = 0;
        scanf("%d",&num);
        if (num == 0){
            printf ("Case #%d: INSOMNIA\n", caseIndex);
            caseIndex += 1;
            continue;
        }
        int mask = 0;
        int i = 1;
        while (mask != 0x3FF){
            long long cur = num * i;
            while (cur > 0){
                int dig = cur % 10;
                if ((((1<<dig) & mask)>>dig) == 0){
                    mask |=1<<dig;
                }
                cur /= 10;
            }
            i+=1;
        }
        printf ("Case #%d: %d\n", caseIndex,(i-1)*num);
        caseIndex += 1;
    }
    
    return 0;
}
