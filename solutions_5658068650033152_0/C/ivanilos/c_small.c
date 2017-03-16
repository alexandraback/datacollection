#include <stdio.h>

int main(void) {
    int t;
    int caso;
    int n, m;
    int k;
    int min;
    int aux;
    int cand;
    int delta;
    int i, j, p, q;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %d %d %d", &n, &m, &k);
        min = k;

        for (i = 5; i <= n && i <= m; i += 2) {
            aux = 0;
            cand = 0;
            for (j = 0; j <= (i + 1) / 2; j++) {
                cand += 2;
            }
            for (j = 0, p = 1; j < i / 2; j++, p += 2) {
                aux += p + p;
            }

            aux += i;
            if (aux < k) {
                cand += (k - aux);
            }
            if (cand < min) {
                min = cand;
            }
        }


        for (i = 0; i < n; i++) {
            for (p = i; p < n; p++) {
                for (j = 0; j < m; j++) {
                    for (q = j; q < m; q++) {
                        aux = (p - i + 1) * (q - j + 1);
                        cand = aux;
                        if (aux < k) {
                            if (i + 1 <= p - 1 && j + 1 <= q - 1) {
                                cand -= ((p - i - 1) * (q - j - 1));
                            }
                            /*printf("before cand = %d\n", cand);
                            printf("aux = %d, k - aux = %d, k = %d\n", aux, k - aux, k); */
                            cand += (k - aux);
                            /*printf("i = %d, p = %d, j = %d, q = %d\n", i, p, j, q);
                            printf("first cand = %d\n", cand); */
                            if (cand < min) {
                                min = cand;
                            }
                        } else {
                            cand = aux;
                            if (i + 1 <= p - 1 && j + 1 <= q - 1) {
                                cand -= ((p - i - 1) * (q - j - 1));
                                delta = aux - k;
                                aux -= k;
                                if (delta <= 4) {
                                    cand -= delta;
                                }
                            }

                            if (cand < min) {
                                min = cand;
                            }
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d\n", caso, min);
    }
    return 0;
}
