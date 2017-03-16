#include <stdio.h>
#include <cstring>
#define MAX_NUM 2000000
#define CN2(X) ((X)*((X)-1)/2)

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        bool Used[MAX_NUM + 1] = { false };
        int Answer = 0;
        int Begin, End;
        scanf("%d %d", &Begin, &End);
        for (int j = Begin; j <= End; j++) {
            int Count = 1;
            Used[j] = true;
            char S[10] = "";
            sprintf(S, "%d", j);
            int Len = strlen(S);
            for (int k = 1; k < Len; ++k) {
                char SS[10] = "";
                strcpy(SS, S + 1);
                SS[Len - 1] = S[0];
                if (SS[0] != '0') {
                    int M;
                    sscanf(SS, "%d", &M);
                    if ((M >= Begin) && (M <= End))
                    {
                        if (!Used[M]) {
                            Used[M] = true;
                            Count++;
                        }
                    }
                }
                strcpy(S, SS);
            }
            Answer += CN2(Count);
        }
        printf("Case #%d: %d\n",i,Answer);
    }
    return 0;
}

