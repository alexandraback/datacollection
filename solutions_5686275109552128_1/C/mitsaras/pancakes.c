#include <stdio.h>
#include <stdlib.h>

int main () {
    int T, t;

    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        int i, n;

        scanf("%d", &n);

        int max_stack = 0;
        int P[1000];

        for (i = 0; i < n; i++) {
            scanf("%d", P + i);
            if (P[i] > max_stack) max_stack = P[i];
        }

        int size;
        int best = max_stack;

        for (size = 2; size < max_stack; size++) {
            int minutes = 0;
        
            for (i = 0; i < n; i++)
                minutes += (P[i] - 1) / size; 

            if (best > minutes + size)
                best = minutes + size;
        }

        printf("Case #%d: %d\n", t, best);
    }
    return 0;
}
