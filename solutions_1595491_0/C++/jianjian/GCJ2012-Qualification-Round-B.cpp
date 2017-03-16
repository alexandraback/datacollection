#include <cstdio>
using namespace std;

int main () {
    freopen("A-small.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int case_cnt;
    scanf("%d", &case_cnt);

    int googler;
    int surprise;
    int require;
    int result;
    for (int crt_case = 1; crt_case <= case_cnt; ++crt_case) {
        scanf("%d %d %d", &googler, &surprise, &require);
        result = 0;
        int normal_standard = 3*require - 2;
        if (normal_standard < require)
            normal_standard = require;
        int surprise_standard = 3*require - 4;
        if (surprise_standard < require)
            surprise_standard = require;

        int score;
        for (int i = 0; i < googler; ++i) {
            scanf("%d", &score);

            if (score >= normal_standard)
                result++;
            else if (score >= surprise_standard &&
                surprise > 0) {
                surprise--;
                result++;
            }
        }

        printf("Case #%d: %d\n", crt_case, result);
    }

    return 0;
}