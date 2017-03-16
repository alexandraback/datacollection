#include <iostream>
#include <cstdio>
#include <cstring>
#define N 110
#define ll long long
using namespace std;
ll a[N],b[N];
int x[N],y[N];
int T;
int n,m;

int main()
{
    freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    cin>>T;
    for (int ttt=1;ttt<=T;ttt++)
    {
        cin>>n>>m;
        for (int k=1;k<=n;k++)
           cin>>a[k]>>x[k];
        for (int k=1;k<=m;k++)
           cin>>b[k]>>y[k];
        for (int k=n+1;k<=3;k++)
           {
               a[k]=0;
               x[k]=0;
           }
           ll wh=0;
        if (x[1]==x[2]&&x[2]==x[3])
        {
            a[1]+=a[2]+a[3];
            x[2]=0;
            x[3]=0;
        }
        else
        if (x[1]==x[2])
        {
            a[2]+=a[1];
            x[1]=0;
        }
        else
        if (x[3]==x[2])
        {
            a[2]+=a[3];
            x[3]=0;
        }

        for (int i=0;i<=m+1;i++)
        {
            for (int j=i;j<=m+1;j++)
            {
                ll temp1=0;
                ll temp2=0;
                ll temp3=0;
               for (int k=1;k<=i;k++)
                  if (y[k]==x[1])
                  {
                       temp1+=b[k];
                  }
                for (int k=i+1;k<=j;k++)
                  if (y[k]==x[2])
                  {
                      temp2+=b[k];
                  }
                for (int k=j+1;k<=m;k++)
                  if (y[k]==x[3])
                  {
                      temp3+=b[k];
                  }
                  ll ans=0;
                  ans+=min(a[1],temp1);
                  ans+=min(a[2],temp2);
                  ans+=min(a[3],temp3);
                  if (ans>wh) wh=ans;
            }
        }
        if (x[1]==x[3])
        {
            a[2]=a[3];
            x[2]=x[3];
            a[1]+=a[2];
            a[3]=0;
            x[3]=0;
            a[2]=0;
            x[2]=0;


        for (int i=0;i<=m+1;i++)
        {
            for (int j=i;j<=m+1;j++)
            {
                ll temp1=0;
                ll temp2=0;
                ll temp3=0;
               for (int k=1;k<=i;k++)
                  if (y[k]==x[1])
                  {
                       temp1+=b[k];
                  }
                for (int k=i+1;k<=j;k++)
                  if (y[k]==x[2])
                  {
                      temp2+=b[k];
                  }
                for (int k=j+1;k<=m;k++)
                  if (y[k]==x[3])
                  {
                      temp3+=b[k];
                  }
                  ll ans=0;
                  ans+=min(a[1],temp1);
                  ans+=min(a[2],temp2);
                  ans+=min(a[3],temp3);
                  if (ans>wh) wh=ans;
            }
        }

        }
        printf("Case #%d: ",ttt);
        cout<<wh<<endl;

    }
    return 0;
}
