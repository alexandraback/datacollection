#include <stdio.h>

long long int table[39 +1];

void init()
{
table[0] = 0LL;
table[1] = 1LL;
table[2] = 2LL;
table[3] = 3LL;
table[4] = 11LL;
table[5] = 22LL;
table[6] = 101LL;
table[7] = 111LL;
table[8] = 121LL;
table[9] = 202LL;
table[10] = 212LL;
table[11] = 1001LL;
table[12] = 1111LL;
table[13] = 2002LL;
table[14] = 10001LL;
table[15] = 10101LL;
table[16] = 10201LL;
table[17] = 11011LL;
table[18] = 11111LL;
table[19] = 11211LL;
table[20] = 20002LL;
table[21] = 20102LL;
table[22] = 100001LL;
table[23] = 101101LL;
table[24] = 110011LL;
table[25] = 111111LL;
table[26] = 200002LL;
table[27] = 1000001LL;
table[28] = 1001001LL;
table[29] = 1002001LL;
table[30] = 1010101LL;
table[31] = 1011101LL;
table[32] = 1012101LL;
table[33] = 1100011LL;
table[34] = 1101011LL;
table[35] = 1102011LL;
table[36] = 1110111LL;
table[37] = 1111111LL;
table[38] = 2000002LL;
table[39] = 2001002LL;
}

int main()
{   freopen("C-large-1.in", "r", stdin);
    freopen("out_C_large.txt", "w", stdout);
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
