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
#define ip freopen("c.txt","r",stdin)
#define op freopen("out.txt","w",stdout)

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

struct edge{
    int x;
    int y;
    int z;
};




int xy[15][15];
int xz[15][15];
int yz[15][15];

int main()
{
//    ip;
//    op;
    int t;
    int cs=1;

    sint1(t);

    while(t--)
    {
        int n;
        edge ans[100000];
        int x,y,z;

        sint3(x,y,z);
        sint1(n);
        //queue<edge>Q;
        mm(xy,0);
        mm(yz,0);
        mm(xz,0);


        int s=0;

        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(xy[i][j]>=n)
                    continue;

                for(int k=1;k<=z;k++)
                {
                    if(xy[i][j]>=n)
                    break;

                    if((yz[j][k]>=n)||(xz[i][k]>=n))
                        continue;

                    s++;
                    xy[i][j]++;
                    xz[i][k]++;
                    yz[j][k]++;

//                    edge e;
//                    e.x=i;
//                    e.y=j;
//                    e.z=k;

                    ans[s].x=i;
                    ans[s].y=j;
                    ans[s].z=k;
//                    Q.push(e);
                }
            }
        }

//        cout<<endl<<x<<" "<<y<<" "<<z<<endl;
        printf("Case #%d: %d\n",cs++,s);


        for(int i=1;i<=s;i++)
//        while(!Q.empty())
        {
//            edge e=Q.front();
//            printf("%d %d %d\n",e.x,e.y,e.z);
//            Q.pop();

            printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
        }
    }


}
