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
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        int A = INPT_INT, N = INPT_INT;

        int a[102];

        for(int i = 0;i<N;++i) a[i] = INPT_INT;

        int res = N;
        if( A > 1 )
        {
            sort( a,a+N );

            for(int k = 0;k<N;++k)
            {
                int sum = A, cnt = k;

                for(int i = 0;i<N-k;++i)
                {
                    while( sum <= a[i] )
                    {
                        sum += sum-1;
                        ++cnt;
                    }
                    sum += a[i];
                }
                res = min(res,cnt);
            }
        }

        printf("Case #%d: %d\n",ca,res);
    }
    return 0;
}
