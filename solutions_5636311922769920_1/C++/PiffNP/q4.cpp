#include <stdio.h>
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        int k, c, s;
        fscanf(fp1, "%d%d%d", &k, &c, &s);
        if(k > c * s){
            fprintf(fp2, "Case #%d: IMPOSSIBLE\n", i + 1);
            continue;
        }
        int a[10005] = {0};
        long long ans[105];
        for(int j = 0; j < k; j++)
            a[j] = j;
        for(int j = k; j < c * s; j++)
            a[j] = 0;
        for(int j = 0; j < c * s; j += c){
            int q = j / c;
            ans[q] = 0;
            for(int p = j; p < j + c; p++)
                ans[q] = ans[q] * k + a[p];
        } 
        fprintf(fp2, "Case #%d:", i + 1);
        int r = k / c + (k % c != 0);
        for(int i = 0; i < r; i++)
            fprintf(fp2, " %lld", ans[i] + 1);
        fprintf(fp2, "\n");
    }
    return 0;
}
