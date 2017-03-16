#include<iostream>
#include<cstdlib>
#include<cstdio>



void work() {
    int n;
    int first[2000]={0},second[2000]={0},finish[2000] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d",&first[i],&second[i]);
    }
    int total =0,result = 0;
    bool change = true;
    while (change) {
        change = false;
        for (int i =0; i < n;i++)
            if (total >=second[i] && finish[i] < 2) {
//                printf("%d %d\n", total, i);
                total += 2 - finish[i];
                finish[i] = 2;
                change = true;
                result++;
            }
        if (!change) {
            int maxs = -1;
            int maxi =0;
            for (int i =0; i < n; i++)
                if (total >= first[i] && finish[i] < 1) {
                    if (second[i] > maxs) {
                        maxs = second[i];
                        maxi = i;
                    }
                }
            if (maxs >=0) {
                total += 1;
                finish[maxi] = 1;
                change = true;
                result ++;
            }
        }
    }
    for(int i =0; i < n; i++)
        if(finish[i] < 2){
            printf("Too Bad");
            return;
        }
    printf("%d", result);
}
            

int main() {
    int t;
    scanf("%d", &t);
    for(int i =1; i <=t;i++) {
        printf("Case #%d: ",i);
        work();
        printf("\n");
    }
}
