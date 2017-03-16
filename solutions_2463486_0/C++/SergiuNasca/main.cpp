#include <stdio.h>
using namespace std;
int t,q,p,contor,aux,a[100];
int main()
{
    freopen("sergiu.in","r",stdin);
    freopen("sergiu.out","w",stdout);
    scanf("%d",&t);
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=11;
    a[5]=22;
    for(int k=1;k<=t;++k)
    {
        contor=0;
        scanf("%d %d",&p,&q);
        for(int i=1;i<=5;++i)
            if(a[i]*a[i]>=p&&a[i]*a[i]<=q)contor++;
        printf("Case #%d: %d\n",k,contor);
    }
    return 0;
}
