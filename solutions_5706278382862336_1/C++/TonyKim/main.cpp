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


long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}







int main(int argc, const char * argv[])
{
    freopen("A-large.in.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    scanf("%d", &testcases);
    for (int i=1; i<=testcases; i++) {
        long long int p,q;
        scanf("%lld/%lld",&p, &q);
        bool impossible = false;
        int cnt=1;
        int checkq = 0;
        
        
        int gcdnumber;
        
        gcdnumber = gcd(p,q);
        p = p/gcdnumber;
        q = q/gcdnumber;
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
        
        
        if (!impossible) {
            printf("Case #%d: %d\n",i, cnt);
        }
        else {
            printf("Case #%d: impossible\n",i);
        }
    
        
    }
    
}


