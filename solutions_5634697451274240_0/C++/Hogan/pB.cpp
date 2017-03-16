#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);

    char in[110];
    for (int times = 0; times < T; times++) {
        scanf("%s", in);
        
        char c = in[0];
        int cnt = 0;
        for (int i = 0; in[i]; i++) {
            if (c != in[i]) {
                c = in[i];
                cnt += 1;
            }
        }

        if (c == '-') cnt += 1;
        printf("Case #%d: %d\n", times+1, cnt);
    }
}
