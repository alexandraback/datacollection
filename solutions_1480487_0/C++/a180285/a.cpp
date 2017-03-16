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
const int N=128               ;
const int M=1               ;
const ll P=10000000097ll    ;

struct dot
{
    double v;
    double ans;
    int id;
};

int sgn(double x)
{
    return (x>eps) - (x<-eps);
}

int fcmp(double a,double b)
{
    return sgn(a-b);
}

double sqr(double x)
{
    return x*x;
}

dot d[N];
int n;

int cmp_v(dot a,dot b)
{
    return a.v > b.v;
}

int cmp_id(dot a,dot b)
{
    return a.id < b.id;
}

void doit()
{
    int i,j,k;
    double sum = 0;
    MEM(d);
    scanf("%d", &n);
    For(i, n)
    {
        scanf("%lf", &d[i].v);
        d[i].id = i;
        sum += d[i].v;
    }
    double all = sum;
    sort(d, d+n, cmp_v);
    sum *= 2;
    for(j=0; j<n; j++)
    {
        if( fcmp(d[j].v, sum/(n-j) ) <= 0 )
            break;
        d[j].ans = 0;
        sum -= d[j].v;
    }
    double avg = sum / (n-j);
    //printf("avg = %g\n", avg);
    for(; j<n; j++)
    {
        d[j].ans = (avg-d[j].v) / all;
    }
    sort(d, d+n, cmp_id);
    For(i, n)
    {
        printf(" %f", d[i].ans*100);
    }
    puts("");
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        printf("Case #%d:", _);
        doit();
    }
    return 0;
}

