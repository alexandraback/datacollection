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

#define N 2222222

const char printans[][23]={"O won","X won","Draw","Game has not completed"};

int test;
int n;
int a[4][4][2];
char s[4][4];

int ans()
{
    int white=0;
    mset(a);
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        switch(s[i][j])
        {
          case 'O':
            a[i][j][0]=1;
          break;
          case 'X':
            a[i][j][1]=1;
          break;
          case 'T':
            a[i][j][0]=a[i][j][1]=1;
          break;
          case '.':
            white=1;
          break;
        }
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<4;j++)
      {
        if(a[j][0][i]&&a[j][1][i]&&a[j][2][i]&&a[j][3][i])
          return i;
        if(a[0][j][i]&&a[1][j][i]&&a[2][j][i]&&a[3][j][i])
          return i;
      }
      if(a[0][0][i]&&a[1][1][i]&&a[2][2][i]&&a[3][3][i])
        return i;
      if(a[0][3][i]&&a[1][2][i]&&a[2][1][i]&&a[3][0][i])
        return i;
    }
    return 2+white;
}

int main()
{
    //fileio_in_out();
    fileio_txt();
    
    scanf("%d",&test);
    for(int tcase=1;tcase<=test;tcase++)
    {
      for(int i=0;i<4;i++)
        scanf("%s",s[i]);
      printf("Case #%d: %s\n",tcase,printans[ans()]);
    }
    
    //system("pause");
    return 0;
}
