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

const int N=1111111;

int test;
int n,m,k,ans;
int a[N];

void getans()
{
     if(m==1)
     {
       ans=n;
       return;
     }
     sort(a+1,a+1+n);
     ans=inf;
     k=0;
     for(int i=1;i<=n;i++)
     {
       mine(ans,k+(n-i+1));
       while(m<=a[i])
       {
         m=m*2-1;
         k++;
       }
       m+=a[i];
     }
     mine(ans,k);
}

int main()
{
    //fileio_in_out();
    fileio_txt();
    
    scanf("%d",&test);
    for(int tcase=1;tcase<=test;tcase++)
    {
      scanf("%d%d",&m,&n);
      for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
      
      getans();
      
      printf("Case #%d: %d\n",tcase,ans);
    }
    
    //system("pause");
    return 0;
}

