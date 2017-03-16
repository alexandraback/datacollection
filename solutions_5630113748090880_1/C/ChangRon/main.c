//
//  main.c
//  codejam_2016_round_2_2
//
//  Created by JerryChang on 2016/4/16.
//  Copyright © 2016年 Ron. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T;
    int N;
    int i;
    int j;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d",&N);
        int height[2505];
        int k=0;
        for(k=0;k<2505;k++){
            height[k]=0;
        }
        for(j=0;j<2*N-1;j++){
            for(k=0;k<N;k++){
                int input;
                scanf("%d",&input);
                height[input]++;
            }
        }
        printf("Case #%d:",i);
        for(j=1;j<=2500;j++){
            if(height[j]%2==1){
                printf(" %d",j);
            }
        }
        printf("\n");
    }
    
    
    return 0;
}
