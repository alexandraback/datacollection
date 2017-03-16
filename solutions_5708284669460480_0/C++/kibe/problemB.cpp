#include <stdio.h>
#include <string.h>

int m;

int procura(char s1[], char s2[]) {
    int i, j, res, aux;
    aux = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        res = 0;
        for (j = 0; s1[i + j] != '\0' && s2[j] != '\0'; j++) {
            if (s1[i + j] == s2[j]) {
                res++;
            } else {
                break;
            }
        }
        if (res == strlen(s2)) {
            aux++;
        }
    }
    if (aux > m)
        m = aux;
    return aux;
}

int solve(char s[], char obj[], char keys[], int k, int l, int d) {
    int i, res = 0;

    if (d == l) {
        s[d] = '\0';
        return procura(s, obj);
    }
    for (i = 0; i < k; i++) {
        s[d] = keys[i];
        res = res + solve(s, obj, keys, k, l, d + 1);
    }
    return res;
}

int main() {
    int t, c, k, l, s, a, i;
    char keys[103], obj[103], aux[103];
    float res;

    c = 1;
    scanf("%d", &t);
    while (t--) {
        m = 0;
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s", keys);
        scanf("%s", obj);
        a = 1;
        for (i = 0; i < s; i++)
            a = a * k;
        res = solve(aux, obj, keys, k, s, 0) / (float) a;
        res = m - res;
        printf("Case #%d: %f\n", c, res);
        c++;
    }
    return 0;
}
