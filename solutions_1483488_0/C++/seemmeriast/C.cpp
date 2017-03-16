#include<iostream>
#include<algorithm>
using namespace std;
int T;
int a,b;
int pow10[]={1,10,100,1000,10000,100000,1000000,10000000};
int check[2000010];
void cleararray()
{
     for(int i=0;i<2000005;i++)
     check[i]=0;
     }
int numdigit(int k)
{
     for(int i=0;i<=8;i++)
     {
          if(pow10[i]>k)
          return i;
          }
     return 8;
     }
int recycle(int k,int n)
{
     int ans=0;
     for(int i=0;i<n;i++)
     {
          if(!check[k]&&a<=k&&k<=b)
          {
               ans++;
               check[k]=1;
               }

          int d=k%10;
          k/=10;
          k+=d*pow10[n-1];
          }

     return ans;
     }
int main()
{
     freopen("C-small-attempt0.in","r",stdin);
     freopen("C-small-attempt0.out","w",stdout);

     cin>>T;
     for(int t=1;t<=T;t++)
     {
          cleararray();

          cin>>a>>b;
          int n=numdigit(a);

          int ans=0;
          for(int i=a;i<=b;i++)
          {
               if(!check[i])
               {
                    int r=recycle(i,n);
                    ans+=r*(r-1)/2;
                    //cout<<i<<" "<<r<<endl;
                    }
               }

          cout<<"Case #"<<t<<": "<<ans<<endl;
          }

     return 0;
     }
