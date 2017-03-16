#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[10][10];

bool check(char who) {
    for (int i = 1; i <= 4; ++i) {
        bool yes1 = true, yes2 = true;
        for (int j = 1; j <= 4; ++j) {
            if (a[i][j] != who && a[i][j] != 'T') yes1 = false;
            if (a[j][i] != who && a[j][i] != 'T') yes2 = false;
        }
        if (yes1 || yes2) return true;
    }
    bool yes1 = true, yes2 = true;
    for (int i = 1; i <= 4; ++i) {
        int j = i, k = 5 - i;
        if (a[i][j] != who && a[i][j] != 'T') yes1 = false;
        if (a[i][k] != who && a[i][k] != 'T') yes2 = false;
    }
    if (yes1 || yes2) return true;
    return false;
}

void runOneCase(int cas) {
    for (int i = 1; i <= 4; ++i)
        scanf("%s", a[i] + 1);
    bool moreSteps = false;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            if (a[i][j] == '.')
                moreSteps = true;
    bool o = check('O');
    bool x = check('X');

    printf("Case #%d: ", cas);

    if (o) puts("O won"); else
    if (x) puts("X won"); else
    if (moreSteps) puts("Game has not completed"); else
        puts("Draw");
}

int main(){
    freopen("A2.in", "r", stdin);
    freopen("out2.txt" , "w", stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <=t; ++i)
        runOneCase(i);
    return 0;
}
