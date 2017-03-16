#include <cstdio>
#include <cstdlib>
#include <cstring>

int nine[15];

void createNine() {
    nine[0] = 0;
    nine[1] = 9;
    nine[2]  = nine[1]  + 8         + 1 + 8         + 2;
    nine[3]  = nine[2]  + 8         + 1 + 98        + 2;
    nine[4]  = nine[3]  + 98        + 1 + 98        + 2;
    nine[5]  = nine[4]  + 98        + 1 + 998       + 2;
    nine[6]  = nine[5]  + 998       + 1 + 998       + 2;
    nine[7]  = nine[6]  + 998       + 1 + 9998      + 2;
    nine[8]  = nine[7]  + 9998      + 1 + 9998      + 2;
    nine[9]  = nine[8]  + 9998      + 1 + 99998     + 2;
    nine[10] = nine[9]  + 99998     + 1 + 99998     + 2;
    nine[11] = nine[10] + 99998     + 1 + 999998    + 2;
    nine[12] = nine[11] + 999998    + 1 + 999998    + 2;
    nine[13] = nine[12] + 999998    + 1 + 9999998   + 2;
    nine[14] = nine[13] + 9999998   + 1 + 9999998   + 2;
}

int main() {
    createNine();

    int T;
    scanf("%d", &T);

    for (int times = 1; times <= T; times++) {
        char in[15];
        scanf("%s", in);
        int len = strlen(in);
        int ans = 0;
        if (in[len - 1] == '0') {
            sprintf(in, "%lld", atoll(in) - 1); 
            len = strlen(in);
            ans += 1;
        }

        char tmp[15];
        for (int i = len / 2; i < len; i++) {
            tmp[i - len / 2] = in[i];
        }
        tmp[len - len / 2] = 0;
        int lv = atoi(tmp);

        for (int i = len / 2 - 1; i >= 0; i--) {
            tmp[len / 2 - 1 - i] = in[i];
        }
        tmp[len / 2] = 0;
        int hv = atoi(tmp);

        if (len == 1) ans += lv;
        else if (hv == 1) ans += lv + 1 + nine[len - 1];
        else ans += hv + lv + 1 + nine[len - 1];
        
        printf("Case #%d: %d\n", times, ans);
    }
}
