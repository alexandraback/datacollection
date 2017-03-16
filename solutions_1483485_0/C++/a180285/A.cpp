/*****************************************
*
* @ingroup UESTC_ACM,2011
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
const int N=1               ;
const int M=1               ;
const ll P=10000000097ll    ;

int to[257];

void read()
{
    int i,j,k;
    char s[1<<10];
    char st[1<<10];
    freopen("in.txt", "r", stdin);
    gets(s);
    gets(st);
    int sn = strlen(s);
    For(i, sn)
    {
        if( 0 == to[s[i]] )
            to[s[i]] = st[i];
        else if( to[s[i]] != st[i] )
            exit(-2);
    }
//    for(i='a'; i<='z'; i++)
//        putchar(to[ i ]);
//    puts("");
//    sort(to+'a', to+'z'+1);
//    for(i='a'; i<='z'; i++)
//        putchar(to[ i ]);
//    puts("");
}

void get()
{
    char s[1<<10];
    gets(s);
    int i;
    For(i, strlen(s))
    {
        if( 0 == to[ s[i] ] )
        {
            printf("lost of %c\n", s[i]);
            exit(-1);
        }
        printf("%c", to[ s[i] ]);
    }
    puts("");
}

void doit()
{
    int T;
    char s[19];
    freopen("a.in", "r", stdin);
    scanf("%d", &T);
    gets(s);
    int i;
    for(i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        get();
    }
}

int main()
{
    freopen("a.out", "w", stdout);
    read();
    doit();
    return 0;
}

