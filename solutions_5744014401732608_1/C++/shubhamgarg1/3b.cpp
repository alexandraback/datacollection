#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//string a1[200],a2[200];
//string ans1,ans2;
//int b1[100005],b2[100005],n;
int a[100][100];
int min1=INT_MAX;
typedef pair<int,int> ii;

ll fk[105];

int main()
{
    ll t,p,i,j,r,c=1,k,n,b,m;

    freopen("B-large (3).in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&b,&m);
        memset(a,0,sizeof(a));
        p=pow(2,b-2);
       // printf("%lld %lld",b,m);
        printf("Case #%lld: ",c++);
        if(m>p)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            printf("POSSIBLE\n");
            for(i=b-1;i>=2;i--)
            {
                for(j=i+1;j<=b;j++)
                {
                    a[i][j]=1;
                }
            }
            a[1][b]=1;
            m=m-1;
            ll count1=b-1;
            while(m>0)
            {
                if(m&1)
                {
                    a[1][count1]=1;
                }
                m=m/2;
                count1--;
            }
            for(i=1;i<=b;i++)
            {
                for(j=1;j<=b;j++)
                {
                    printf("%d",a[i][j]);
                }
                printf("\n");
            }

        }



            //printf("%lld\n",p);


    }
    return 0;
}
