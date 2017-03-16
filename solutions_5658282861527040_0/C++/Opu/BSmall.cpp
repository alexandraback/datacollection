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

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);

    int caseCnt = INPT_INT;

    for(int cNo = 1;cNo<=caseCnt;++cNo)
    {
        int A = INPT_INT, B = INPT_INT, K = INPT_INT;

        int res = 0;
        for(int i = 0;i<A;++i) for(int j = 0;j<B;++j) if((i&j) < K) ++res;

        printf("Case #%d: ",cNo);
        printf("%d\n",res);
    }
    return 0;
}
