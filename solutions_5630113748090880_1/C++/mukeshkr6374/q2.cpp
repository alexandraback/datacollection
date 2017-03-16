#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,i,n,k,j,p;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&n);
        long long a[2505]={0};
        for(i=0;i<(2*n)-1;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lld",&p);
                a[p]++;
            }
        }
        printf("Case #%lld: ",k);

        for(i=0;i<2501;i++)
        {
            if(a[i]%2==1)
                printf("%lld ",i);
        }
        printf("\n");
    }
    return 0;
}
