#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int T;
    char S[100];

    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s\n", S);
        int L = strlen(S);
        //printf("t: %d, %s, %d\n", t, S, L);
        int flips = 0;
        char prev = '+';
        for (int i = L-1; i >= 0; i--) {
            if (S[i] != prev) {
                flips++;
                prev = S[i];
            }
        }
        printf("Case #%d: %d\n", t, flips);
    }
    return 0;
}
