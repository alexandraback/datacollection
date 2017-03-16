/*****************************************
*
* @ingroup UESTC_ACM,2012
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
const int N=1<<10               ;
const int M=1               ;
const ll P=10000000097ll    ;

struct dot
{
    int a, b;
};

int n;
dot a[N];

int cmp(dot a,dot b)
{
    if( a.b != b.b )
        return a.b < b.b;
    return a.a < b.a;
}

int def(int st)
{
    int g = 1;
    int num = 1;
    for(int i=0; i<n; i++)
    {
        while(g < a[i].b)
            g++, num++;
        g += 2;
        if( i==st )
            g--;
        num++;
    }
    return num;
}

int doit()
{
    int i,j,k;
    int ok = 0;
    scanf("%d", &n);
    For(i, n)
    {
        scanf("%d %d", &a[i].a, &a[i].b);
        if( 0==a[i].a || 0==a[i].b )
            ok = 1;
    }
    if( 0==ok )
        return -1;
    sort(a, a+n, cmp);
    if( 0 == a[0].b )
    {
        int g = 2;
        int num = 1;
        for(int i=1; i<n; i++)
        {
            while(g < a[i].b)
                g++, num++;
            g += 2;
            num++;
        }
        return num;
    }
    int ans = oo;
    For(i, n)
    {
        if( 0 == a[i].a )
            checkmin(ans, def(i));
    }
    return ans;
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b1.out", "w", stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        int ans = doit();
        printf("Case #%d: ", _);
        if( ans < 0 )
            puts("Too Bad");
        else
            printf("%d\n", ans);
    }
    return 0;
}

/**

4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6

Case #1: 3
Case #2: 3
Case #3: Too Bad
Case #4: 6

**/

