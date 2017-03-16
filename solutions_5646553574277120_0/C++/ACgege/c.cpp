#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 30
using namespace std;

int p[N];
int q[N];

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("c1.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int c,d,v;
       scanf("%d%d%d",&c,&d,&v);

       memset(p,0,sizeof p);


       for(int i=0;i<d;i++)
       {
           int x;
            scanf("%d",&x);
            if(x>v) continue;

            memset(q,0,sizeof q);

            for(int j=1;j<=v;j++)
                if(p[j]==1)
            {
                int y=j+x;
                if(y<=v) q[y]=1;
            }
           p[x]=1;

           for(int j=1;j<=v;j++) p[j]=max(p[j],q[j]);
       }

//       for(int i=1;i<=v;i++)
//        printf("%d %d --\n",i,p[i]);

       int ans=0;
       for(int i=1;i<=v;i++)
        if(p[i]==0)
       {
           ans++;
           int x=i;

             memset(q,0,sizeof q);
            for(int j=1;j<=v;j++)
                if(p[j]==1)
            {
                int y=j+x;
                if(y<=v) q[y]=1;
//                printf("%d-- ",y);
            }
            p[i]=1;
            for(int j=1;j<=v;j++) p[j]=max(p[j],q[j]);
//            printf(" == %d\n",i);
       }

         printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}

