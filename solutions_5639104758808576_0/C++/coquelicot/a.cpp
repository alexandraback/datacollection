#include <cstdio>

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        int l;
        scanf("%d", &l);

        char buf[l + 2];
        scanf("%s", buf);

        int mx = 0, sum = 0;
        for (int i = 0; i <= l; i++) {

            int num = buf[i] - '0';
            if (mx < i - sum)
                mx = i - sum;
            sum += num;

        }

        printf("Case #%d: %d\n", t, mx);

    }

}
