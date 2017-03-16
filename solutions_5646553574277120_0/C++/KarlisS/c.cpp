#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int c, d, v;
int hv[32];
int flg[32];
size_t need;

static size_t addMask(size_t cmsk, int coin)
{
    size_t nms=cmsk;
    if (coin<= v) nms |= (1ULL<<(coin-1));
    for (int i=0; i+coin<v; i++) {
        if (cmsk&(1ULL<<i)) {
            nms |= (1ULL<<(i+coin));
        }
    }
    return nms;
}

static int recSolve(size_t pmask, int minc, int left)
{
    if (pmask == need) return 0;
    if (left == 0) return 30;
    int ans = 30;
    for (int j=minc; j<=v; j++)
    {
        if (flg[j]) continue;
        size_t m2 = addMask(pmask, j);
        int tans=1+recSolve(m2, j+1, left-1);
        if (tans < ans) ans = tans;
    }
    return ans;
}

static int solve()
{
    memset(flg, 0, sizeof(flg));
    need = (1ULL<<v)-1;
    size_t have=0;
    for (int i=0; i<d; i++) {
        have = addMask(have, hv[i]);
        flg[hv[i]]=1;
    }
    return recSolve(have, 1, 5);
}



int main()
{
    int t;
    scanf("%d", &t);
    for (int nt=1; nt<=t; nt++)
    {
        scanf("%d %d %d", &c, &d, &v);
        for (int i=0; i<d; i++) scanf("%d", &hv[i]);
        printf("Case #%d: ", nt);
        printf("%d\n", solve());
    }
    return 0;
}
