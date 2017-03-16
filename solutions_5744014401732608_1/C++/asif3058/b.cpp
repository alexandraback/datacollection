#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

#define mx 10000000
#define ip freopen("b.txt","r",stdin)
#define op freopen("out1.txt","w",stdout)

#define sint1(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sint3(a,b,c) scanf("%d %d %d",&a,&b,&c)


#define sch1(a) scanf("%c",&a)
#define sch2(a,b) scanf("%c %c",&a,&b)
#define sch3(a,b,c) scanf("%c %c %c",&a,&b,&c)


#define sll1(a) scanf("%lld",&a)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define sll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define ll long long int

#define lpi0(a,b) for(int a=0;a<b;a++)
#define lpd0(a,b) for(int a=b-1;a>=0;a--)

#define lpi1(a,b) for(int a=1;a<=b;a++)
#define lpd1(a,b) for(int a=b;a>0;a--)

#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair

#define pi acos(-1)

#define mm(a,b) memset(a,b,sizeof(a))
int s[100][100],x;
ll ps[60];

void dp(int i)
{
    if(i==1)
    {
        x--;
        return;
    }

    if(x>ps[i-2])
    {
        x-=ps[i-2];

        for(int j=i;j>0;j--)
        {
            for(int k=1;k<j;k++)
            {
                s[k][j]=1;
            }
        }
        return;
    }

//    if(x<ps[i-2])
//        return;
    for(int j=i-1;j>0;j--)
    {
        if(x==0)
            return;
        if(x<ps[j-2])
            continue;

        s[j][i]=1;

        dp(j);
    }
}

int main()
{
//    ip;
//    op;
    int t;
    int cs=1;

    ps[0]=1;
    for(int i=1;i<=51;i++)
    {
        ps[i]=ps[i-1]*2;
    }

    sint1(t);

    while(t--)
    {
        int n;


        mm(s,0);

        sint2(n,x);
        ll p=pow(2,(n-2));
        if(x>p)
        {
            printf("Case #%d: IMPOSSIBLE\n",cs++);
            continue;
        }
        dp(n);
//        s[0][n-1]=1;
//        x--;
//        for(int i=0;i<n-1;i++)
//        {
//            for(int j=n-2;j>i;j--)
//            {
//
//                if(x==0)
//                    break;
//
////                    cout<<i<<" "<<j<<endl;;
//
//                s[i][j]=1;
//                x--;
//                if(j<n-1)
//                s[j][n-1]=1;
//            }
//            if(x==0)
//                break;
//        }
        printf("Case #%d: POSSIBLE\n",cs++);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d",s[i][j]);
            }

            cout<<endl;
        }



    }


}
