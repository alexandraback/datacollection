#include <cstdio>
#include <cstring>

int main() {

    int T;
    scanf("%d", &T);

    double prob[110][110];
    double exp[110][110];

    for (int t = 1; t <= T; t++) {

        int k, s, l;
        scanf("%d%d%d", &k, &l, &s);

        char key[k + 2];
        char tag[s + 2];
        scanf("%s %s", key + 1, tag + 1);

        if (strspn(tag + 1, key + 1) != (size_t)l) {
            printf("Case #%d: 0.0\n", t);
            continue;
        }

        int mat[l + 2];
        mat[0] = -1, mat[1] = 0;
        for (int i = 2; i <= l; i++) {
            mat[i] = mat[i - 1];
            while (mat[i] >= 0 && tag[mat[i] + 1] != tag[i])
                mat[i] = mat[mat[i]];
            mat[i]++;
            //fprintf(stderr, "mat[%d] = %d\n", i, mat[i]);
        }

        for (int i = 0; i <= s; i++)
            for (int j = 0; j <= l; j++) {
                prob[i][j] = exp[i][j] = 0;
            }

        prob[0][0] = 1;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j <= l; j++) {
                if (prob[i][j] < 1e-10)
                    continue;
                for (int u = 1; u <= k; u++) {
                    int to = j;
                    while (to >= 0 && tag[to + 1] != key[u])
                        to = mat[to];
                    to++;
                    prob[i + 1][to] += prob[i][j] / k;
                }
            }
            for (int j = 0; j <= l; j++) {
                if (prob[i][j] < 1e-10)
                    continue;
                for (int u = 1; u <= k; u++) {
                    int to = j;
                    while (to >= 0 && tag[to + 1] != key[u])
                        to = mat[to];
                    to++;
                    exp[i + 1][to] += (prob[i][j] / k / prob[i + 1][to]) * (exp[i][j] + (to == l ? 1 : 0));
                }
            }
        }

        int need = l;
        for (int i = 1; i <= k; i++) {
            int to = l;
            while (to >= 0 && tag[to + 1] != key[i])
                to = mat[to];
            to++;
            if (l - to + 1 < need)
                need = l - to + 1;
        }
        //fprintf(stderr, "need=%d\n", need);
        int max = (s - l) / need + 1;
        //fprintf(stderr, "max=%d\n", max);

        double ans = 0;
        for (int i = 0; i <= l; i++)
            ans += exp[s][i] * prob[s][i];
        printf("Case #%d: %.9f\n", t, max - ans);

    }

}
