#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Smax 20
#define MAX_TRIES 1000000

void solve(char *c, char *j)
{
    int length;
    int i, tries, min;
    int amin, bmin;
    char *finalc, *finalj;

    length = strlen(c);

    min = 0x7fffffff;
    for (tries = 0; tries < MAX_TRIES; ++tries) {
        char *a, *b;
        int vala, valb;

        a = strdup(c);
        b = strdup(j);
        for (i = 0; i < length; ++i) {
            if (a[i] == '?') a[i] = rand() % 10 + '0';
            if (b[i] == '?') b[i] = rand() % 10 + '0';
        }

        vala = atoi(a);
        valb = atoi(b);

        if (min > abs(vala - valb)) {
            min = abs(vala - valb);
            amin = vala;
            bmin = valb;
            finalc = a;
            finalj = b;
        }
        if (min == abs(vala - valb)) {
            if (vala < amin) {
                amin = vala;
                bmin = valb;
                finalc = a;
                finalj = b;
            }
            if (valb < bmin) {
                amin = vala;
                bmin = valb;
                finalc = a;
                finalj = b;
            }
        }
    }

    printf("%s %s", finalc, finalj);
}



int main()
{
    int t, i;
    char *c, *j;
    FILE *f;

    srand(time(NULL));
    f = fopen("game.in", "r");
    fscanf(f, "%d\n", &t);

    for (i = 0 ; i < t; ++i) {
        char string[2 * Smax + 1];

        fgets (string, 2 * Smax + 1, f);
        c = string;
        j = strchr(string, ' ');
        *j = 0;
        j++;

        printf("CASE #%d: ", i + 1);
        solve(c, j);

    }

    return 0;
}
