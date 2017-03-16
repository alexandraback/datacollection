/*****************************************
*
* @ingroup UESTC_ACM,2011
* @param   B
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
const int N=128               ;
const int M=1               ;
const ll P=10000000097ll    ;

int def(int v)
{
    if( v > 28 )
        return 10;
    if( v < 2 )
        return v;
    if( v % 3 == 0 )
        return v/3 + 1;
    if( v % 3 == 1 )
        return v/3 + 1;
    if( v % 3 == 2 )
        return v/3 + 2;
    exit(-2);
}

void doit()
{
    int n, p, s;
    int a[N];
    int ans = 0;
    scanf("%d %d %d", &n, &s, &p);
    p--;
    int i,j,k;
    For(i, n)
        scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    for(i=0; a[i]>p*3 && i<n-s; i++)
        ans++;
    For(j, s)
    {
        if( def(a[i+j]) > p )
            ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    int T,_=0;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d",&T);
    while( _++ < T )
    {
        printf("Case #%d: ", _);
        doit();
    }
    return 0;
}

/**

4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21

Case #1: 3
Case #2: 2
Case #3: 1
Case #4: 3

**/
