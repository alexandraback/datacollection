#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 5000005
#define ll long long
#define p(t) cout<<t;
#define f(i,n) for(i=0;i<n;i++)
#define g(i,n) for(i=1;i<=n;i++)


ll a[N],b[N],r,m,n;


int main()
{
ios_base::sync_with_stdio(0);
ll k=0,t=0,x,sum=0,q=0,z=0,y=0,l=0,i,j;
k=1;
ifstream my;
  my.open ("a.txt");
  ofstream out("out.txt");
  my>>q;
 while(q--){
    my>>n>>m;
    y=n-2;
    l=1;
    f(i,y)l=l*2;
    r++;
    out<<"Case #"<<r<<": ";
    if(m>l){out<<"IMPOSSIBLE\n";continue;}
    int a[n+1][n+1];
      g(i,n){
      g(j,n) if(j>i)a[i][j]=1; else a[i][j]=0;
      }
      out<<"POSSIBLE\n";
      k=l-m;
      t=0;
      while(k){
        if(k&1)a[1][n-t-1]=0;
        t++;
        k=k>>1;
      }
      g(i,n)
      {
          g(j,n)out<<a[i][j];
          out<<endl;
      }
 }
  my.close();

return 0;
}
