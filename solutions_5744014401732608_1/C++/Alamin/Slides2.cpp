/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};

ll p,t,i,j,m,b,arr[55][55],cnt,mx;

int main()
{
     freopen("B-largec.in","r",stdin);
     freopen("SlidesOutL.txt","w",stdout);

    scanf(" %lld",&t);

    for(p=1LL;p<=t;p++)
    {
        cnt=0LL;
        scanf(" %lld %lld",&b,&m);
        mx=1LL<<(b-2LL);
        memset(arr,0LL,sizeof(arr));
        if(m>mx)
        {
            printf("Case #%lld: IMPOSSIBLE\n",p);
            continue;
        }
        /*dig=0;
        mm=m;
        while(mm)
        {
            mm/=2LL;
            dig++;
        }*/
        printf("Case #%lld: POSSIBLE\n",p);
            arr[1][b]=1LL;
            for(i=2LL;i<b;i++)
            {
                arr[1][i]=1LL;
                arr[i][b]=1LL;

                for(j=2LL;j<i;j++)
                {
                    arr[i][j]=1LL;
                    cnt++;
                }
            }
            ll bd=mx-m;
            ll bd2=bd;
            ll now=b-1LL;
            ll kata=1LL;
            while(bd2)
            {
                if(bd2%2LL)
                {bd-=kata;
                kata*=2LL;
                arr[now][b]=0LL;
                }
                now--;
                bd2/=2LL;
            }

            for(i=1LL;i<=b;i++)
            {
                for(j=1LL;j<=b;j++)
                {
                    printf("%lld",arr[i][j]);
                }
                printf("\n");
            }
    }

    return 0;
}

