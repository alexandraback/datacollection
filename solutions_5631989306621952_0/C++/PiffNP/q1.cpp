#include <stdio.h>
#define LEN 2000
char s[LEN];
char a[LEN], b[LEN];
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        fscanf(fp1, "%s", s);
        int max = -1;
        int l, r;
        l = -1, r = -1;
        for(int j = 0; s[j] != '\0'; j++)
           if((int)s[j] >= max){
               max = s[j];
               a[++l] = s[j];
           } else {
               b[++r] = s[j];
           }
        fprintf(fp2, "Case #%d: ", i + 1);
        for(; l >= 0; l--)
            fprintf(fp2, "%c", a[l]);
        for(int j = 0; j <= r; j++)
            fprintf(fp2, "%c", b[j]);
        fprintf(fp2, "\n");
    }
    return 0;
}
