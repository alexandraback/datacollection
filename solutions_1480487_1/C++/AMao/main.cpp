//
//  main.cpp
//  A
//
//  Created by 珏吉 杨 on 12-5-6.
//  Copyright (c) 2012年 zju. All rights reserved.
//

#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("A-large.txt", "r", stdin);
	freopen("output_large.txt", "w", stdout);
    int flag;
    double sum,rem,stand,remsum;
    int n,t,i,j;
    int s[200],checked[200];
    double res[200];
    scanf("%d",&t);
    for (j = 0;j<t;j++) {
        memset(checked, 0, 200);
        scanf("%d",&n);
        sum = 0;
        for (i = 0;i<n; i++) {
            scanf("%d",&s[i]);
            sum += s[i];
        }
        stand = sum*2/n;
        flag = 1;
        rem = n;
        remsum = sum;
        while (flag) {
            flag = 0 ;
            for (i = 0; i<n; i++) {
                if (s[i]>stand&&checked[i]!=1) {
                    checked[i]=1;
                    rem --;
                    flag =1;
                    remsum -= s[i];
                }
            }
            stand = (remsum+sum) / rem;
        }
        for (i = 0; i<n; i++) {
            if (checked[i]) {
                res[i] = 0;
            }
            else {
                res[i] = (stand - s[i])/sum *100;
            }
        }
        printf("Case #%d:",j+1);
        for (i = 0; i<n; i++) {
            printf(" %lf",res[i]);
        }
        printf("\n");
    }
    return 0;
}

