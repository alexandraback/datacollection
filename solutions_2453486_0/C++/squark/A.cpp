#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

char bo[5][5];

bool check(char ch){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++)
            if(bo[i][j] != ch && bo[i][j] != 'T')
                break;
        if(j == 4)
            return 1;
    }
    for(j = 0; j < 4; j++){
        for(i = 0; i < 4; i++)
            if(bo[i][j] != ch && bo[i][j] != 'T')
                break;
        if(i == 4)
            return 1;
    }
    for(i = 0; i < 4; i++)
        if(bo[i][i] != ch && bo[i][i] != 'T')
            break;
    if(i == 4)
        return 1;
    for(i = 0; i < 4; i++)
        if(bo[i][3-i] != ch && bo[i][3-i] != 'T')
            break;
    if(i == 4)
        return 1;
    return 0;
}

bool checkEpmty(){
    int i, j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            if(bo[i][j] == '.')
                return 1;
    return 0;
}

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        printf("Case #%d: ", i0);
        for(int i = 0; i < 4; i++)
            scanf("%s", bo[i]);
        if(check('X'))
            printf("X won\n");
        else if(check('O'))
            printf("O won\n");
        else if(checkEpmty())
            printf("Game has not completed\n");
        else
            printf("Draw\n");
    }
    return 0;
}
