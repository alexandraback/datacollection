#include<stdio.h>
#include<algorithm>
using namespace std;

int T,n,m,w,sol;

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        scanf("%d %d %d",&n,&m,&w);

        sol=n*m/w;

        if(m%w==0) sol=sol+w-1;
        else sol+=w;

        printf("Case #%d: %d\n",it,sol);
    }

    return 0;
}
