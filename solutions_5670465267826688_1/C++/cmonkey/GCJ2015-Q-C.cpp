#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[50010];

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

char bipower(char a, long long x){
    char res = 1;
    while(x){
        if (x & 1) res = rule(res, a);
        a = rule(a, a);
        x >>= 1;
    }
    return res;
}

int main(){
    int t, T;
    long long L, X, i, j, k, n;
    char res, left, mid, right;
    FILE* fin = fopen("C-large.in", "r");
    FILE* fout = fopen("C-large.out", "w");
    fscanf(fin, "%d", &T);
    for (t = 1; t <= T; t++){
        fscanf(fin, "%lld %lld", &L, &X);
        fscanf(fin, "%s", str);

        for (i = 0, res = 1; i < L; i++) res = rule(res, str[i]);
        res = bipower(res, X);
        if (res != -1 || L * X < 3){
            fprintf(fout, "Case #%d: NO\n", t);
            continue;
        }

        k = X > 4 ? 4 : X;
        for (i = 1, j = L; i < k; i++, j += L){
            memcpy(str + j, str, L);
        }
        n = j;

        for (i = 0, left = 1; i < n; i++){
            left = rule(left, str[i]);
            if (left == 'i') break;
        }
        for (j = n - 1, right = 1; j >= 0; j--){
            right = rule(str[j], right);
            if (right == 'k') break;
        }
        if (i < n && j >= 0 && left == 'i' && right == 'k'){
            if (i + 1 < j + (X - k) * L){
                fprintf(fout, "Case #%d: YES\n", t);
                continue;
            }
        }
        fprintf(fout, "Case #%d: NO\n", t);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
