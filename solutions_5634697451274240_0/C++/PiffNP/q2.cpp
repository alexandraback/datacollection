#include <stdio.h>
int main(){
    int t;
    FILE *fp1, *fp2;
    if((fp1 = fopen("a.in", "r")) == NULL)
        return 1;
    fp2 = fopen("a.out", "w");
    fscanf(fp1, "%d", &t);
    for(int i = 0; i < t; i++){
        int n, k, q;
        char s[100];
        fscanf(fp1, "%s", s);
        int ans = 0;
        int p = 0;
        if(s[0] == '-'){
            ans++;
            for(p = 0; s[p] == '-'; p++);
        }
        while(s[p] != '\0'){
            if(s[p] == '+'){
                p++;
                continue;
            } else {
                ans += 2;
                for(; s[p] == '-'; p++);
            }
        }
        fprintf(fp2, "Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
