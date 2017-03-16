#include <iostream>
#include <stdio.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int N = 128;

int n, m;
int a[N][N];

bool check(int x, int y)
{
    bool res = false;
    bool ok = true;
    REP(i, n) if(a[i][y] > a[x][y]) ok = false;
    res |= ok;
    ok = true;
    REP(j, m) if(a[x][j] > a[x][y]) ok = false;
    res |= ok;
    return res;
}

int main()
{
    freopen("D:/tc_algo/a.in", "r", stdin);
    freopen("D:/tc_algo/a.out", "w", stdout);

    int T;
    scanf("%d", &T);
    REP(t, T) {
        scanf("%d %d", &n, &m);
        REP(i, n) REP(j, m) scanf("%d", &a[i][j]);

        string res = "YES";
        REP(i, n) REP(j, m) if(!check(i, j)) res = "NO";

        printf("Case #%d: %s\n", t + 1, res.c_str());
    }

    return 0;
}
