#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int T,i,Max,N[101],C[1000001];
int rev(int);
int main()
{
    freopen("ProblemA.in","r",stdin);
    freopen("ProblemA.out","w",stdout);

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d",&N[i]);

        if(N[i]>Max)
        {
            Max=N[i];
        }
    }

    for(i=1;i<=Max;i++)
    {
        if(rev(i)<i && i%10!=0)
        {
            C[i]=min(C[i-1]+1,C[rev(i)]+1);
        }
        else
        {
            C[i]=C[i-1]+1;
        }
    }

    for(i=1;i<=T;i++)
    {
        printf("Case #%d: %d\n",i,C[N[i]]);
    }

    return 0;
}
int rev(int num)
{
    int new_num=0;

    while(num!=0)
    {
        new_num*=10;

        new_num+=num%10;

        num/=10;
    }

    return new_num;
}
