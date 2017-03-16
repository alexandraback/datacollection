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

#define N 11111111

int test;
ll n,m;
int a[N],b[N];
char s[111];

int check(ll k)
{
    int len=0;
    while(k)
    {
      s[len++]=k%10;
      k/=10;
    }
    for(int i=0;i<len/2;i++)
      if(s[i]!=s[len-1-i])
        return 0;
    return 1;
}

int ans()
{
    return a[(int)sqrt(m)]-a[(int)sqrt(n-1)];
}

int main()
{
    //fileio_in_out();
    fileio_txt();
    
    for(ll i=1;i<=10000000;i++)
      b[i]=check(i)&&check(i*i),a[i]=a[i-1]+b[i];
    
    scanf("%d",&test);
    for(int tcase=1;tcase<=test;tcase++)
    {
      scanf("%I64d%I64d",&n,&m);
      printf("Case #%d: %d\n",tcase,ans());
    }
    
    //system("pause");
    return 0;
}
