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

int a[1100];
//int b[1100];
vector<int>b[1100];

int last;
int color[1200];
int color1[1200];
int fun1(int x)
{
    color1[x]=1;
    int cnt=0;
    for(int i=0;i<b[x].size();i++)
    {
        int cnt1=0;
        if(color[b[x][i]]==0&&color1[b[x][i]]==0)
        {
            cnt1=max(cnt1,fun1(b[x][i]));
        }
        cnt=max(cnt,cnt1);
    }
    return cnt+1;
}

int fun(int x)
{
    int s[1100][3];

    mm(s,0);
    mm(color,0);
    s[x][1]=1;
    int i=a[x];
    int cnt=1;
//    last=x;
    int cnt1=0;
    int ans=cnt;
    color[x]=1;
    color[i]=1;
    while(s[i][1]==0)
    {
//        cout<<i<<endl;
        s[i][0]=1;
        s[i][1]=1;
        s[a[i]][0]=1;
        last=i;
        cnt++;
        color[a[i]]=1;
//        s[i]=1;
        if(i==a[a[i]]&&b[i].size()>1)
        {
            mm(color1,0);
//            cout<<b[i].size()<<endl;
            cnt1=fun1(a[i]);
//            cout<<i<<" "<<a[i]<<" "<<cnt1<<endl;
        }
        else
        {
            cnt1=0;
        }
        ans=max(ans,cnt+cnt1);
        i=a[i];
    }
//    cout<<i<<" "<<a[i]<<" "<<s[a[i]][0]<<" "<<endl;

    if(s[a[i]][0]==1&&i!=a[a[i]]&&i!=x)
        ans--;
    if(s[x][0]==0)
        ans=0;
    return ans;
}

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

        sint1(n);
        int x;
        mm(a,0);
//        mm(b,0);
        for(int i=0;i<=n;i++)
        {
            b[i].clear();
        }

        for(int i=1;i<=n;i++)
        {
            sint1(x);
            a[i]=x;
            b[x].push_back(i);
        }

//        for(int i=0;i<=n;i++)
//            cout<<b[i].size()<<endl;

        int ans=0;
        int p=0;
        for(int i=1;i<=n;i++)
        {
            int y=fun(i);

            ans=max(ans,y);
//            cout<<i<<" ANS=="<<ans<<endl;

            if(ans==n)
                break;
        }


        printf("Case #%d: %d\n",cs++,ans);
    }


}
