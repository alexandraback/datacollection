#include <cstdio>
#include <cstdlib>
#include <cstring>

char POS = '+';
char NEG = '-';


inline int flip(int n, int m) {
    return m > 0 ? 1 : 0;
}


int num_of_flips(char * S) {
    int n = strlen(S);
    int posx = 0;
    int negx = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (S[i] == POS) {
            posx = i + 1;
        } else {
            if (negx > 0 && posx > negx) {
                cnt++;
            }
            negx = i + 1;
        }

        if (posx > 0 && negx > posx) {
            cnt++;
            posx = 0;
        }
    }

    if (negx > 0) {
        cnt++;
    }
    return cnt;
}


int main() {
    int T;
    char S[101];
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        memset(S, 0, sizeof(S));
        scanf("%s", S);
        printf("Case #%d: %d\n", i + 1, num_of_flips(S));
    }
}
