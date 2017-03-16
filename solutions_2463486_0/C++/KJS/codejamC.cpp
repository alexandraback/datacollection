#include <stdio.h>

long long int table[39 +1];

void init()
{
table[0] = 0;
table[1] = 1;
table[2] = 2;
table[3] = 3;
table[4] = 11;
table[5] = 22;
table[6] = 101;
table[7] = 111;
table[8] = 121;
table[9] = 202;
table[10] = 212;
table[11] = 1001;
table[12] = 1111;
table[13] = 2002;
table[14] = 10001;
table[15] = 10101;
table[16] = 10201;
table[17] = 11011;
table[18] = 11111;
table[19] = 11211;
table[20] = 20002;
table[21] = 20102;
table[22] = 100001;
table[23] = 101101;
table[24] = 110011;
table[25] = 111111;
table[26] = 200002;
table[27] = 1000001;
table[28] = 1001001;
table[29] = 1002001;
table[30] = 1010101;
table[31] = 1011101;
table[32] = 1012101;
table[33] = 1100011;
table[34] = 1101011;
table[35] = 1102011;
table[36] = 1110111;
table[37] = 1111111;
table[38] = 2000002;
table[39] = 2001002;
}

int main()
{   freopen("C-small-attempt0.in", "r", stdin);
    freopen("out_C.txt", "w", stdout);
    init();

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);

        int rindex = 39;
        while (rindex > 0) {
            if (b >= table[rindex]*table[rindex])
                break;
            rindex--;
        }

        int lindex = 1;
        while (lindex <= 39) {
            if (a <= table[lindex]*table[lindex])
                break;
            lindex++;
        }

        printf("Case #%d: %d\n", t, rindex - lindex +1);
    }
    return 0;
}
