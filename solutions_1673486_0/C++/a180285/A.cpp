/*****************************************
*
* @ingroup UESTC_ACM,2012
* @param   A
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
const int N=1<<20               ;
const int M=1               ;
const ll P=10000000097ll    ;

int A, B;
double p[N];

void doit()
{
    int i,j,k;
    scanf("%d %d", &A, &B);
    For(i, A)
        scanf("%lf", &p[i]);
    for(i=1; i<A; i++)
        p[i] *= p[i-1];
    double ans = B + 2;
    int yes, no;
    yes = B-A+1;
    no  = 2*B - A + 2;
    for(i=A-1; i>=0; i--)
    {
//        printf("i -> %d\n", i);
//        printf("%f %f\n", p[i], (1-p[i]));
//        printf("%d %d\n", yes, no);
        checkmin(ans, p[i]*yes + (1-p[i])*no);
        yes += 2;
        no += 2;
    }
    printf("%lf\n", ans);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        printf("Case #%d: ", _);
        doit();

    }
    return 0;
}

/**

3
2 5
0.6 0.6

1 20
1

3 4
1 0.9 0.1

Case #1: 7.000000
Case #2: 20.000000
Case #3: 4.500000

**/

