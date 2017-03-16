#include <iostream>

using namespace std;

int main() {
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        printf("Case #%d:", i+1);
        int K, C, S;

        cin >> K >> C >> S;


        if (S == K) {
            for (int j = 1; j <= K; j++) {
                printf(" %d", j);
            }
            printf("\n");
        } else {
            printf(" IMPOSSIBLE\n");
        }


    }
}
