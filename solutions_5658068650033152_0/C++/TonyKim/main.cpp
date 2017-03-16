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
// Problem C.

int testcases; // 1~100







int main(int argc, const char * argv[])
{
    freopen("C-small-attempt1.in.txt","r",stdin);
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    

    scanf("%d", &testcases);
    for (int i=1; i<=testcases; i++) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        if (n>m) {
            int temp = m;
            m = n;
            n = temp;
        }
        // now  n <= m
        
        //bool space[1000][1000]={false,};
        
        int stone = 0;
        if (k<=4) {
            stone = k;
        }
        else if (n==1||n==2) {
            stone = k;
        }
        else if (k>=n*m-4) {
            stone = 2*(n+m)-8;
            int remaining = k - (n*m-4);
            stone += remaining;
        }
        else if (n==3){
            int completed = 5;
            stone = 4;
            while (completed!=k) {
                if (completed == k-1) {
                    completed+=1;
                    stone +=1;
                }
                else if (completed == k-2){
                    completed+=2;
                    stone +=2;
                }
                else {
                    completed+=3;
                    stone +=2;
                }
            }
            
        }
        else if (k==5||k==6||k==7){
            stone = k-1;
        }
        
        else {
            int completed = 8;
            stone = 6;

            while (completed!=k) {
                if (completed == k-1) {
                    stone +=1;
                    completed+=1;
                    break;
                }
                else {
                    completed +=2;
                    stone +=1;
                }
                
            }

        }

        printf("Case #%d: %d\n",i,stone);
        
    
        
    }
    
}


