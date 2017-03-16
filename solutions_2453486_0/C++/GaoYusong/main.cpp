#include <cstdio>

using namespace std;

char ss[10][10];

bool check(char ob)
{
    for (int i = 0; i < 4; i++) {
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            if (ss[i][j] != ob && ss[i][j] != 'T') {
                ok = false;
            }
        }
        if (ok)
            return true;
    }

    for (int j = 0; j < 4; j++) {
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            if (ss[i][j] != ob && ss[i][j] != 'T') {
                ok = false;
            }
        }
        if (ok)
            return true;
    }

    bool ok1 = true, ok2 = true;
    for (int d = 0; d < 4; d++) {
        if (ss[d][d] != ob && ss[d][d] != 'T') {
            ok1 = false;
        }
        if (ss[d][3 - d] != ob && ss[d][3 - d] != 'T') {
            ok2 = false;
        }
    }
    return ok1 || ok2;
}

int main()
{
    int T;
    int cn = 0;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {

        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%s", ss[i]);
            for (int j = 0; j < 4; j++) {
                if (ss[i][j] != '.')
                    cnt++;
            }
        }

        bool ret1 = check('X'),
             ret2 = check('O');
        printf("Case #%d: ", ++cn);
        if (ret1) {
            printf("X won\n");
        } else if(ret2) {
            printf("O won\n");
        } else {
            if (cnt == 16) {
                printf("Draw\n");
            } else {
                printf("Game has not completed\n");
            }
        }


    }
    
    return 0;
}
