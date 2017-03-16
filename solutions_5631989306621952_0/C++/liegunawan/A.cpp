#include <iostream>
#include <cstring>

using namespace std;

bool fallAsleep(int D[]);

void doCase(int iCase) {
    printf("Case #%d: ", iCase);
    
    char S[1010]; scanf("%s", S);
    int L = strlen(S);
    
    char R[1010]; memset(R, 0, sizeof(R));
    R[0] = S[0];
    char T[1010];
    
    for (int i=1; i<L; i++) {
        if (S[i] >= R[0]) {
            strcpy(T, R);
            R[0] = S[i];
            strcpy(&R[1], T);
        } else {
            R[i] = S[i];
        }
    }
    
    printf("%s\n", R);
}

int main(void) {
    int T; scanf("%d", &T);
    for (int i=1; i<=T; i++) doCase(i);
    return 0;
}