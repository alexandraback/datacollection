/*****************************************
*
* @ingroup UESTC_ACM,2011
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
const int N=1               ;
const int M=1               ;
const ll P=10000000097ll    ;

int ten, num;
int A, B;

void def(int v)
{
    ten = 1;
    num = 0;
    for(v/=10; v>0; v/=10)
    {
        ten *= 10;
        num++;
    }
}

int test(int t)
{
    int v = t;
    int ret = 0;
    map<int, int> mp;
    for(int i=0; i<num; i++)
    {
        v = (v%10)*ten + v/10;
        mp[v]++;
        if( mp[v] > 1 )
            continue;
        ret += (t<v && v<=B);
    }
    return ret;
}

void doit()
{
    scanf("%d %d", &A, &B);
    def(A);
    int ans = 0;
    for(int i=A; i<B; i++)
        ans += test(i);
    printf("%d\n", ans);
}

int main()
{
    int T,_=0;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
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
1 9
10 40
100 500
1111 2222

Case #1: 0
Case #2: 3
Case #3: 156
Case #4: 287

**/

