#include<iostream>
#include<algorithm>
#define INF 2000000010
using namespace std;
int a[1010],b[1010];
int T,n;
int minb()
{
     int minn=INF,minpos=-1;
     for(int i=0;i<n;i++)
     {
          if(b[i]!=-1&&b[i]<=minn)
          {
               minpos=i;
               minn=b[i];
               }
          }
     return minpos;
     }
int mina(int z)
{
     int maxx=-1,maxpos=-1;
     for(int i=0;i<n;i++)
     {
          if(a[i]!=-1&&a[i]<=z&&b[i]>=maxx)
          {
               maxpos=i;
               maxx=b[i];
               }
          }
     return maxpos;
     }
int main()
{
     freopen("B-small-attempt0.in","r",stdin);
     freopen("B-small-attempt0.out","w",stdout);

     cin>>T;
     for(int t=1;t<=T;t++)
     {
          cin>>n;
          for(int i=0;i<n;i++)
          cin>>a[i]>>b[i];

          int star=0,ans=0;
          while(star<2*n)
          {
               int bb=minb(),aa=mina(star);
               if(bb!=-1&&star>=b[bb])
               {
                    if(a[bb]!=-1)
                    {
                         star+=2;
                         a[bb]=-1;
                         b[bb]=-1;
                         }
                    else
                    {
                         star++;
                         b[bb]=-1;
                         }
                    ans++;
                    //cout<<"b "<<bb<<" "<<star<<endl;
                    }
               else if(aa!=-1&&star>=a[aa])
               {
                    star++;
                    a[aa]=-1;
                    ans++;
                    //cout<<"a "<<aa<<" "<<star<<endl;
                    }
               else
               {
                    //cout<<a[0]<<a[1]<<b[0]<<b[1]<<endl;
                    break;
                    }
               }
          if(star==2*n)
          cout<<"Case #"<<t<<": "<<ans<<endl;
          else
          cout<<"Case #"<<t<<": Too Bad"<<endl;
          }

     return 0;
     }
