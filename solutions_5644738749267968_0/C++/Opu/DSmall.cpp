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

int N, dp[11][(1<<10)];
double naomi[1005], ken[1005];

int calc(int i, int mask)
{
    if(i==N) return 0;
    int &ret = dp[i][mask];

    if(ret != -1) return ret;
    ret = 0;

    for(int j = 0;j<N;++j) if(!(mask&(1<<j)))
    {
        ret = max(ret, calc(i+1,mask|(1<<j))+(naomi[i]>ken[j]));
    }
    return ret;
}

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small.out","w",stdout);
    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        N = INPT_INT;

        for(int i = 0;i<N;++i) scanf("%lf",&naomi[i]);
        for(int i = 0;i<N;++i) scanf("%lf",&ken[i]);

        sort(naomi,naomi+N);
        sort(ken,ken+N);

        int war = 0, j = 0;
        for(int i = 0;i<N;++i)
        {
            while( j < N && naomi[i] > ken[j] ) ++j;
            war += (j >= N);
            ++j;
        }

        memset(dp,-1,sizeof(dp));

        printf("Case #%d: ",ca);
        printf("%d %d\n",calc(0,0),war);
    }
    return 0;
}
