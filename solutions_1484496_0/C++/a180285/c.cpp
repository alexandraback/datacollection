/*****************************************
*
* @ingroup UESTC_ACM,2012
* @param   C
* @author  a180285
*
*****************************************/

# include <assert.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# pragma comment (linker,"/STACK:16777216")

# define For(i,a)   for(i=0; i<(a); i++)
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0xf,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;
typedef istringstream        Iss     ;

template<class T> inline const T& MIN(const T& a,const T& b){return a<b? a : b;}
template<class T> inline const T& MAX(const T& a,const T& b){return a>b? a : b;}
template<class T> inline void checkmin(T &a,const T& b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,const T& b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=512               ;
const int M=1               ;
const ll P=10000000097ll    ;

int at[1<<22];
int v[N];
int n;

int sum(int id)
{
    int ans = 0;
    int i;
    for(i=0; i<n; i++)
        if( id & (1<<i) )
            ans += v[i];
    return ans;
}

void pt(int id)
{
    int i;
    int f = 0;
    for(i=0; i<n; i++)
        if( id & (1<<i) )
        {
            if( f )
                putchar(' ');
            else
                f = 1;
            printf("%d", v[i]);
        }
    puts("");
}

void doit()
{
    scanf("%d", &n);
    int i,j,k;
    For(i, n)
        scanf("%d", &v[i]);
    MEM(at);
    for(i=1; i<(1<<n); i++)
    {
        if( at[sum(i)] )
        {
            pt(i);
            pt( at[sum(i)] );
            return ;
        }
        at[ sum(i) ] = i;
    }
    puts("Impossible");
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        printf("Case #%d:\n", _);
        doit();
    }
    return 0;
}

