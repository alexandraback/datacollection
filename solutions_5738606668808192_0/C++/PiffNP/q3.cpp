#include <stdio.h>
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        int n, J;
        long long power[10];
        fscanf(fp1, "%d%d", &n, &J);
        for(int j = 2; j <= 10; j++){
            power[j] = 1;
            for(int k = 0; k < n / 2; k++)
                power[j] *= j;
            power[j]++;
        }
        fprintf(fp2, "Case #%d:\n", i + 1);
        for(int j = 0; j < J; j++){
            for(int k = 0; k < 2; k++){
                fprintf(fp2, "1");
                for(int p = (1 << (n / 2 - 3)); p > 0; p >>= 1)
                    fprintf(fp2, "%d", (p & j? 1: 0));
                fprintf(fp2, "1");
            }
            for(int k = 2; k <= 10; k++)
                fprintf(fp2, " %lld", power[k]);
            fprintf(fp2, "\n");
        }
    }
    return 0;
}
