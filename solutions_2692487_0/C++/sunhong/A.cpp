#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

int s[110];
int c[110];

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A_output_small.txt","w",stdout);
    int T,A,N;
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%d%d",&A,&N);
        for (int i=0;i<N;i++) scanf("%d",&s[i]);
        memset(c,0,sizeof(c));
        sort(s,s+N);
        if (A==1)
        {
            printf("Case #%d: %d\n",cases,N);
            continue;
        }
        int sum=A;
        int counter=0;
        for (int i=0;i<=N-1;i++)
        {
            while (sum<=s[i])
            {
                sum+=sum-1;
                counter++;
                //printf("sum=%d result=%d\n",sum,result);
            }
            c[i]=counter;
            sum+=s[i];
            //printf("s[%d]=%d sum=%d result=%d\n",i,s[i],sum,result);
        }
        int result=1000000000;
        for (int i=0;i<N;i++)
        {
            result=min(result,c[i]+N-1-i);
        }
        result=min(result,N);
        printf("Case #%d: %d\n",cases,result);
    }
    return 0;
}
