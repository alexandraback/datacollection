#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<ext/hash_map>
#include<ext/hash_set>
#include<set>
#include<string>
#include<assert.h>
#include<vector>
#include<time.h>
#include<queue>
#include<deque>
#include<sstream>
#include<stack>
#include<sstream>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.0000000001
#define Pi 3.1415926535897932384626433832795
using namespace std;
using namespace __gnu_cxx;
const long long  MO=1000000000+7;
const long long INF=1000000000+7;
long long n,m,i,j,k;
long long a[50],b[50],c[50],d[50];
long long A;
long long sol(long long x,long long y)
{
    long long z=0;
    long long las=30;
    for (long long i=29;i>MA(x,y);i--)
    z+=(1ll<<i)*(a[i]&b[i]);
    long long R=1;
    long long E=0;
    if (z>=k) return 0;
    if (x!=y){
    for (long long i=x-1;i>y && z<k;i--)
        if (b[i]==0) R*=2; else
        {
            if(z+(1ll<<i)<=k)
            {
                E+=R*(1ll<<(y+i));
                z+=(1ll<<i);
                las=i;
            }
        }
    for (long long i=y-1;i>x && z<k;i--)
        if (a[i]==0) R*=2; else
        {
            if(z+(1ll<<i)<=k)
            {
                E+=R*(1ll<<(x+i));
                z+=(1ll<<i);
                las=i;
            }
        }
    }
    if (MI(x,y)>0) if (x!=y) R*=2;
  //  cout<<E<<endl;
    for (long long i=MI(x,y)-1;i>0 && z<k;i--)
    if (z+(1ll<<i)<=k) las=i,E+=R*(1ll<<(i*2))*3,z+=(1ll<<i); else R*=3;
//  cout<<x<<" "<<y<<" "<<E<<" "<<endl;
  long long i=0;
if (z<k){
    if (MI(x,y)==0){
    E+=R;
            if (x!=y)
    E+=R;
    }else {
       if (z+1<k)
    E+=R*4; else E+=R*3;
    }
}
   // if (z<k)
    //if (las>0)
 //   E+=R;
   // cout<<"@@  "<<E<<endl;
        return E;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("text.txt","w",stdout);
    long long t;
    cin>>t;
    for (long long tt=1;tt<=t;tt++){
     cin>>n>>m>>k;
     for (i=0;i<30;i++)
     {
         a[i]=(((1<<i)&n)>0);
         b[i]=(((1<<i)&m)>0);
         c[i]=(((1<<i)&k)>0);
     }
     A=0;
     for (i=0;i<30;i++)
     for (j=0;j<30;j++)
     if (a[i]==1 && b[j]==1)
      A+=sol(i,j);
    cout<<"Case #"<<tt<<": "<<A<<endl;
    }
    return 0;
}
