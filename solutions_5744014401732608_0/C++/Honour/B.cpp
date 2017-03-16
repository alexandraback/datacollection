//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;


long long pr[100][100], ar[2509];

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    long long i,j,k,l,n,cas,test,flag,temp,now,ans=0,m;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        scanf("%lld%lld",&n,&m);

        if(m>(1LL<<(n-2)))
        {
            printf("Case #%lld: IMPOSSIBLE\n",cas);
        }
        else
        {
            printf("Case #%lld: POSSIBLE\n",cas);

            temp=m-1;

            memset(ar,0,sizeof(ar));
            memset(pr,0,sizeof(pr));

            pr[1][n]=1;

            for(i=0;i<(n-2);i++)
            {
                if((1LL<<i) & temp)
                {
                    ar[n-(i+1)]=1;
                }
            }

            for(j=2;j<=n;j++)
            {
                for(k=j+1;k<=n;k++)
                {
                    pr[j][k]=1;
                }
            }

            for(i=2;i<n;i++)
            {
                if(ar[i])
                {
                    pr[1][i]=1;
                }
            }

            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    printf("%lld",pr[i][j]);
                }

                printf("\n");
            }

        }



    }



}
