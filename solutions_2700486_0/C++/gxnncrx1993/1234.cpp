#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <memory>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

const int inf=1000000007;
const ll linf=1000000000000000000LL;
const double eps=0.000001;
const double pi=3.14159265358979323846;

template <class T> T abs(T k){return k>=0?k:-k;}
template <class T> T sqr(T n){return n*n;}
template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template <class T> T mod(T a,T b){return (a%b+b)%b;}
template <class T> void mode(T &a,T b){a=mod(a,b);}
template <class T> void maxe(T &a,T b){a=max(a,b);}
template <class T> void mine(T &a,T b){a=min(a,b);}

void fileio_in_out()
{
     freopen(".in","r",stdin);
     freopen(".out","w",stdout);
}

void fileio_txt()
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
}

//==================================================

const int N=33;

int test;
int n,m,k;
double ans;
int x,y;
int t,tt,tx,ty;
int c[N][N];

int calc(int m)
{
    return m*(2*m-1);
}

void work()
{
     x=abs(x);
     y=abs(y);
     m=(x+y)/2+1;
     if(calc(m-1)+(y+1)+2*(m-1)<=n)
     {
       ans=1.0;
       return;
     }
     if((x!=0&&calc(m-1)+(y+1)>n)||(x==0&&calc(m)>n))
     {
       ans=0.0;
       return;
     }
     t=0;
     tt=n-calc(m-1);
     tx=max(tt-2*(m-1),y+1);
     ty=min(tt,2*m);
     for(int i=tx;i<=ty;i++)
       t+=c[tt][i];
     ans=(double)t;
     for(int i=0;i<tt;i++)
       ans/=2.0;
}

int main()
{
    //fileio_in_out();
    fileio_txt();
    
    for(int i=0;i<N;i++)
      c[i][0]=c[i][i]=1;
    for(int i=1;i<N;i++)
      for(int j=1;j<i;j++)
        c[i][j]=c[i-1][j-1]+c[i-1][j];
    
    scanf("%d",&test);
    for(int tcase=1;tcase<=test;tcase++)
    {
      scanf("%d%d%d",&n,&x,&y);
      //printf("%d %d %d\n",n,x,y);
      work();
      
      printf("Case #%d: %.15lf\n",tcase,ans);
    }
    
    //system("pause");
    return 0;
}

