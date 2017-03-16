#include <stdio.h>
#define LEN 2600
int height[LEN];
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        for(int j = 0; j < LEN; j++)
            height[j] = 0;
        int k;
        fscanf(fp1, "%d", &k);
        int l  = 2 * k - 1;
        for(int j = 0; j < l; j++)
            for(int p = 0; p < k; p++){
                int tmp;
                fscanf(fp1, "%d", &tmp);
                height[tmp]++;
            }
        fprintf(fp2, "Case #%d:", i + 1);
        for(int j = 0; j < LEN; j++)
            if(height[j] % 2 != 0)
                fprintf(fp2, " %d", j);
        fprintf(fp2, "\n");
    }
    return 0;
}
