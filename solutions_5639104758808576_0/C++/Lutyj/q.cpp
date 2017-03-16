#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXL = 1001;

int maxS;
char S[MAXL + 1];

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t + 1);

        scanf("%d%s", &maxS, S);

        for (int add = 0; add <= maxS; ++add) {
            bool good = true;
            int cur = add;

            for (int i = 0; i <= maxS; ++i) {
                int d = S[i] - '0';

                if (cur < i && d > 0) { good = false; break; }
                cur += d;
            }

            if (good) {
                printf("%d\n", add);
                break;
            }
        }
    }

    return 0;
}
