#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B_small_output.txt","w",stdout);
    int A,B,K;
    int T;
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%d%d%d",&A,&B,&K);
        int result = 0;
        for (int i=0;i<A;i++)
        {
            for (int j=0;j<B;j++)
            {
                if ((i&j)<K) result++;
            }
        }
        printf("Case #%d: %d\n",cases,result);
    }
    return 0;
}
