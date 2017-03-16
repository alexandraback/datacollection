#include<cstdio>

using namespace std;

int main(){
    int T;
    int N;
    int digs[10];

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", t);
            continue;
        }
        for (int i = 0; i <= 9; i++) {
            digs[i] = 0;
        }
        int rem = 10;
        long long sum = 0;
        while (rem > 0) {
            sum += N;
            int curr = sum;
            while (curr > 0) {
                int d = curr % 10;
                if (digs[d] == 0) {
                    digs[d] = 1;
                    rem--;
                }
                curr /= 10;
            }    
        }
        printf("Case #%d: %lld\n", t, sum);
    }
    return 0;
}
