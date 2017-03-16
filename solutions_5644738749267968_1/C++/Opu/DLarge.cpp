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

int N;
double naomi[1005], ken[1005];

int calc()
{
    int ret = 0, j = N-1;

    for(int i = N-1;i>=0;--i)
    {
        while(j >= 0 && naomi[i] < ken[j]) --j;
        ret += (j>=0);
        --j;
    }
    return ret;
}

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
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

        printf("Case #%d: ",ca);
        printf("%d %d\n",calc(),war);
    }
    return 0;
}
