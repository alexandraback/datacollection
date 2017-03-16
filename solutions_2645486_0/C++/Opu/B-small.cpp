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

int N,R,E;
const int inf = (1<<30);

int v[12], dp[10][20];

int calc(int e,int i)
{
    if( i == N ) return 0;
    int &ret = dp[e][i];
    if( ret != -1 ) return ret;

    ret = 0;
    for(int j = 0;j<=e;++j) ret = max( ret , calc(min(E,e-j+R),i+1) + j*v[i] );
    return ret;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);

    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        int e = INPT_INT, r = INPT_INT, n = INPT_INT;

        for(int i = 0;i<n;++i) v[i] = INPT_INT;

        int res = 0;

        E = e;N = n; R = r;
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",ca,calc(e,0));
    }
    return 0;
}
