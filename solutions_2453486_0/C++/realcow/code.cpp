#include <iostream>
#include <algorithm>

using namespace std;

char b[5][5];
bool check(char c)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++) {
            if (!(b[i][j] == c || b[i][j] == 'T')) 
                break;
        }
        if (j == 4) return true;

        for (j = 0; j < 4; j++) {
            if (!(b[j][i] == c || b[j][i] == 'T')) 
                break;
        }
        if (j == 4) return true;
    }
    
    for (i = 0; i < 4; i++) 
        if (!(b[i][i] == c || b[i][i] == 'T')) 
            break;
    if (i == 4) return true;

    for (i = 0; i < 4; i++) 
        if (!(b[i][4 - i - 1] == c || b[i][4 - i - 1] == 'T')) 
            break;
    if (i == 4) return true;

    return false;
}
int main()
{
    int T;
    int i, j, n = 1;

    scanf("%d", &T);

    while (T--) {
        for (i = 0; i < 4; i++) scanf("%s", b[i]);

        if (check('X'))
            printf("Case #%d: X won\n", n);
        else if (check('O'))
            printf("Case #%d: O won\n", n);
        else {
            bool vacant = false;
            for (i = 0; i < 4; i++) if (strchr(b[i], '.')) vacant = true;

            if (vacant) printf("Case #%d: Game has not completed\n", n);
            else printf("Case #%d: Draw\n", n);
        }
        n++;
    }
    return 0;
}