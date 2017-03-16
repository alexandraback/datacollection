#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXL = 10000;

const int mtab[][4] = {
    { 0, 1, 2, 3 },
    { 1, 4, 3, 6 },
    { 2, 7, 4, 1 },
    { 3, 2, 5, 4 }
};

int mulq(int q1, int q2)
{
    int sign = (q1 & 4) ^ (q2 & 4);
    return sign ^ mtab[q1 & 3][ q2 & 3];
}

int getq(char ch)
{
    switch (ch) {
        case 'i': return 1;
        case 'j': return 2;
        case 'k': return 3;
    }
    return 0;
}

int L;
char S[MAXL + 1];
long long X;

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t + 1);

        scanf("%d%lld%s", &L, &X, S);

        int oneS = 0;
        for (int i = 0; i < L; ++i)
            oneS = mulq(oneS, getq(S[i]));

        int allS = 0, cur = oneS;

        long long tX = X;
        while (tX > 0) {
            if (tX & 1) allS = mulq(allS, cur);
            cur = mulq(cur, cur);
            tX >>= 1;
        }

        if (allS != 4) { printf("NO\n"); continue; }

        long long posI = -1, posK = -1;
        int nZ = (X < 8) ? X : 4;

        cur = 0;
        long long pos = 0;

        for (int z = 0; z < nZ; ++z) {
            for (int i = 0; i < L; ++i) {
                cur = mulq(cur, getq(S[i]));
                if (cur == 1 && posI == -1) posI = pos;
                ++pos;
            }
        }

        cur = 0; pos = L * X;
        for (int z = 0; z < nZ; ++z) {
            for (int i = L - 1; i >= 0; --i) {
                cur = mulq(getq(S[i]), cur);
                --pos;
                if (cur == 3 && posK == -1) posK = pos;
            }
        }

        printf((posI != -1 && posK != -1 && posI < posK) ? "YES\n" : "NO\n");
    }

    return 0;
}
