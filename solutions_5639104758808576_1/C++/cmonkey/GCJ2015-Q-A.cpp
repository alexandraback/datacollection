#include <cstdlib>
#include <cstdio>

char shy[1010];
int main(){
    int T, t, smax, sum, ans, i;

    FILE* fin = fopen("A-large.in", "r");
    FILE* fout = fopen("A-large.out", "w");
    fscanf(fin, "%d", &T);
    for (t = 1; t <= T; t++){
        fscanf(fin, "%d %s", &smax, shy);
        ans = sum = 0;
        for (i = 0; shy[i] && i <= smax; i++){
            if (shy[i] == '0') continue;
            if (sum < i){
                ans += i - sum;
                sum = i;
            }
            sum += shy[i] - '0';
        }
        fprintf(fout, "Case #%d: %d\n", t, ans);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
