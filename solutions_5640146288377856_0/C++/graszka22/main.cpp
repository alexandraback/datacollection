#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

int tb[11];
int r, n, w;

const int PUSTY = 1;
const int TRAFIONY = 2;
const int INF = 1e9;
int funBrat(int pos);

int funJa()
{
    int wy = INF;
    for(int i = 0; i <= n-w; ++i)
    {
        bool czyOdgadlem = true;
        REP(j, w)
            if(tb[i+j] != TRAFIONY)
            {
                czyOdgadlem = false;
                break;
            }
        if(czyOdgadlem)
            return 0;
    }
    REP(i, n)
    {
        if(tb[i] == PUSTY || tb[i] == TRAFIONY)
            continue;
        wy = min(wy, funBrat(i));
    }
    return wy+1;
}


int funBrat(int pos)
{
    int wy = 0;
    tb[pos] = PUSTY;
    bool czyOk = false;
    for(int i = 0; i <= n-w; ++i)
    {
        bool mozebyc = true;
        for(int j = 0; j < w; ++j)
        {
            if(tb[i+j] == PUSTY)
            {
                mozebyc = false;
                break;
            }
        }
        if(mozebyc)
        {
            czyOk = true;
            break;
        }
    }
    if(czyOk)
        wy = max(wy, funJa());
    tb[pos] = TRAFIONY;
    czyOk = false;
    for(int i = 0; i <= n-w; ++i)
    {
        bool mozebyc = true;
        for(int j = 0; j < w; ++j)
        {
            if(tb[i+j] == PUSTY)
            {
                mozebyc = false;
                break;
            }
        }
        if(mozebyc)
        {
            czyOk = true;
            break;
        }
    }
    if(czyOk)
        wy = max(wy, funJa());
    tb[pos] = 0;
    return wy;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        scanf("%d%d%d", &r, &n, &w);
        printf("Case #%d: %d\n", t, n/(w)+w-(n%w == 0 ? 1 : 0));
    }
    return 0;
}

