#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;

int tr,tc;
char g[5][5];

bool won(char c)
{
    bool all_eq;
    g[tr][tc] = c;

    // check row, col.
    for(int i = 0;i<4;++i)
    {
        all_eq = true;
        for(int j = 1;j<4;++j) if(g[i][j]!=g[i][j-1]) all_eq = false;
        if(all_eq && g[i][0]==c) return true;

        all_eq = true;
        for(int j = 1;j<4;++j) if(g[j][i]!=g[j-1][i]) all_eq = false;
        if(all_eq && g[0][i]==c) return true;
    }

    // check both diagonal.
    if(g[0][0]==c && g[1][1]==g[0][0] && g[2][2]==g[0][0] && g[3][3]==g[0][0]) return true;
    if(g[3][0]==c && g[2][1]==g[3][0] && g[1][2]==g[3][0] && g[0][3]==g[3][0]) return true;

    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_Small.out","w",stdout);

    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        for(int i = 0;i<4;++i) scanf("%s",g[i]);

        bool game_ended = true;
        for(int i = 0;i<4;++i) for(int j = 0;j<4;++j)
        {
            if(g[i][j] == 'T')
            {
                tr = i; tc = j;
            }
            if(g[i][j] == '.')
            {
                game_ended = false;
            }
        }

        printf("Case #%d: ",ca);
        if( won('X') ) puts("X won");
        else if( won('O') )puts("O won");
        else if( game_ended ) puts("Draw");
        else puts("Game has not completed");
    }
    return 0;
}
