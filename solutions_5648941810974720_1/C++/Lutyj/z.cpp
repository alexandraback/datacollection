#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXL = 3000;

int L;
char S[MAXL + 1];

const char digits[10][6] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int occ[10];
map<char, int> cnt;

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%s", S);
        L = strlen(S);
        cnt.clear();

        for (int i = 0; i < L; ++i)
            ++cnt[S[i]];

        memset(occ, -1, sizeof(occ));

        int fnd = 0;

        while (fnd < 10) {
            for (int d = 0; d < 10; ++d) {
                if (occ[d] != -1) continue;

                int DL = strlen(&digits[d][0]);
                for (int i = 0; i < DL; ++i) {
                    bool good = true;

                    for (int td = 0; td < 10; ++td)
                        if (occ[td] == -1 && td != d && strchr(&digits[td][0], digits[d][i]) != 0) {
                            good = false; break;
                        }

                    if (good) {
                        // printf("%c %d\n", digits[d][i], d);
                        occ[d] = cnt[digits[d][i]];
                        for (int k = 0; k < DL; ++k)
                            cnt[digits[d][k]] -= occ[d];
                        ++fnd;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: ", t+1);

        for (int d = 0; d < 10; ++d)
            for (int i = 0; i < occ[d]; ++i)
                printf("%d", d);

        printf("\n");
    }

    return 0;
}
