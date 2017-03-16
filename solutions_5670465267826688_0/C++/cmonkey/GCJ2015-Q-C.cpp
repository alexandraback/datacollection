#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[20010];

char rule(char a, char b){
    char sign = 1;
    if (a < 0) {sign *= -1; a = -a;}
    if (b < 0) {sign *= -1; b = -b;}
    if (a == 1) return sign * b;
    if (b == 1) return sign * a;
    if (a == b) return sign * -1;
    if (a == 'i'){
        switch (b){
            case 'j': return sign * 'k';
            case 'k': return sign * -1 * 'j';
        }
    }else if (a == 'j'){
        switch (b){
            case 'i': return sign * -1 * 'k';
            case 'k': return sign * 'i';
        }
    }else if (a == 'k'){
        switch (b){
            case 'i': return sign * 'j';
            case 'j': return sign * -1 * 'i';
        }
    }
    printf("error input %d, %d\n", a, b);
    return 1;
}

int main(){
    int t, T, L, X;
    int i, j, k;
    char res, left, mid, right;
    FILE* fin = fopen("C-small-attempt1.in", "r");
    FILE* fout = fopen("C.out", "w");
    fscanf(fin, "%d", &T);
    for (t = 1; t <= T; t++){
        fscanf(fin, "%d%d", &L, &X);
        fscanf(fin, "%s", str);

        for (i = 1, j = L; i < X; i++, j += L){
            memcpy(str + j, str, L);
        }
        L = j;

        for (i = 0, res = 1; i < L; i++) res = rule(res, str[i]);
        if (res == -1 && L >= 3){
            for (i = 0, left = 1; i < L; i++){
                left = rule(left, str[i]);
                if (left == 'i') break;
            }
            for (j = L - 1, right = 1; j >= 0; j--){
                right = rule(str[j], right);
                if (right == 'k') break;
            }
            if (i + 1 < j && i < L && j >= 0){
                for (k = i + 1, mid = 1; k < j; k++){
                    mid = rule(mid, str[k]);
                }
                if (mid == 'j'){
                    fprintf(fout, "Case #%d: YES\n", t);
                    continue;
                }else{
                    printf("Case %d: %d, %d, %d = %d\n", t, left, mid, right,
                           rule(rule(left, mid), right));
                }
            }
        }
        fprintf(fout, "Case #%d: NO\n", t);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
