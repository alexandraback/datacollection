#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
    freopen("result.out","w",stdout);
    freopen("B-small-attempt3.in","r",stdin);
    int T,n;
    int a[2000],b[2000],c[2000],d[2000],e[2000],f[2000];
    bool f1[2000],f2[2000];
    cin>>T;
    for (int N=1; N<=T; N++)
    {
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>a[i]>>b[i];
            c[i]=f[i]=i;
            d[i]=a[i]; e[i]=b[i];
        }
        for (int i=0; i<n; i++) f1[i]=f2[i]=false;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if ((a[i]>a[j]) || ((a[i]==a[j]) && (b[i]<b[j])) )
                {
                    int temp=a[i]; a[i]=a[j]; a[j]=temp;
                    temp=b[i]; b[i]=b[j]; b[j]=temp;
                    temp=c[i]; c[i]=c[j]; c[j]=temp;
                }
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if (e[i]>e[j])
                {
                    int temp=d[i]; d[i]=d[j]; d[j]=temp;
                    temp=e[i]; e[i]=e[j]; e[j]=temp;
                    temp=f[i]; f[i]=f[j]; f[j]=temp;
                }
        int t=0,ans=0;
        bool flag;
        while (true)
        {
              int u=0,ut=0;
              bool fff=false;
              for (int k=0; k<n; k++)
              {
                  if (e[k]>t) break;
                  if ((e[k]<=t) && (!f2[f[k]]))
                  {
                     int x=0;
                     if (!f1[f[k]]) x=2; else x=1;
                     if (x>u)
                     {
                         u=x;
                         ut=f[k];
                         fff=true;
                     }
                  }
                  if (u==2) break;
              }

              if (fff)
              {
                  f2[ut]=true;
                  t+=u;
                  ans++;
                  //cout<<"2  "<<ut<<" "<<u<<" "<<endl;
              }
              else
              {
                  u=0;ut=0;
                  for (int k=0; k<n; k++)
                  {
                      if (a[k]>t) break;
                      if ((a[k]<=t) && (!f1[c[k]]) && (!f2[c[k]]))
                      {
                          u=1;
                          ut=c[k];
                          fff=true;
                      }
                      if (u==1) break;
                  }
                  if (fff)
                  {
                      f1[ut]=true;
                      t+=u;
                      ans++;
                      //cout<<"1  "<<ut<<" "<<u<<" "<<endl;
                  }
              }
              if (!fff)
              {
                  flag=false;
                  break;
              }
              flag=true;
              for (int i=0; i<n; i++)
                  if (!f2[i]) {flag=false; break;}
              if (flag) break;
        }
        if (flag) cout<<"Case #"<<N<<": "<<ans<<endl;
        else cout<<"Case #"<<N<<": Too Bad"<<endl;
    }
    return 0;
}
