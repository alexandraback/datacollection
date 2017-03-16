#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define FORALL(a,b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)
#define FOR(i,a,b) for(int i = a; i < (int)(b); ++i)

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long LL;

const double EPS = 1e-6;
const int INF = 1<<29;

bool win(int mat[4][4], int v){
    for (int i = 0; i < 4; ++i)
        if ((mat[i][0]&mat[i][1]&mat[i][2]&mat[i][3]) == v)
            return 1;
    for (int i = 0; i < 4; ++i)
        if ((mat[0][i]&mat[1][i]&mat[2][i]&mat[3][i]) == v)
            return 1;
    if ((mat[0][0]&mat[1][1]&mat[2][2]&mat[3][3]) == v) return 1;
    if ((mat[0][3]&mat[1][2]&mat[2][1]&mat[3][0]) == v) return 1;
    return 0;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t, cas = 0;
    char ch;
    scanf("%d", &t);
    int mat[4][4];

    while (t--){
        bool full = 1;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j){
                scanf(" %c", &ch);
                if (ch == 'X') mat[i][j] = 1;
                else if (ch == 'O') mat[i][j] = 2;
                else if (ch == 'T') mat[i][j] = 3;
                else mat[i][j] = 0, full = 0;
            }
        printf("Case #%d: ", ++cas);
        if (win(mat,1)) puts("X won");
        else if (win(mat,2)) puts("O won");
        else if (full) puts("Draw");
        else puts("Game has not completed");
    }

    return 0;
}
