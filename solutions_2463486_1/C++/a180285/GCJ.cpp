/*****************************************
USER: zacdxv1
PROB: 
LANG: C++
2013,USACO
*****************************************/

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

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=1               ;
const int M=1               ;
const ll P=10000000097ll    ;

string problem = "buylow";

void read()
{

}

bool is_palidrom(ll x)
{
	static char s[22];
	int sn = 0;
	while( x > 0 )
	{
		s[sn++] = x % 10;
		x /= 10;
	}
	for(int i=0; i<sn/2; i++)
		if( s[i] != s[sn-i-1] )
			return false;
	return true;
}

void doit()
{

	for(ll i = 1; i<1e7; i++)
		if( is_palidrom(i) && is_palidrom(i*i) )
			printf("%lldll,\n", i*i);

}

void print()
{

}

int get_ans()
{
	ll v[] = {
1ll,
4ll,
9ll,
121ll,
484ll,
10201ll,
12321ll,
14641ll,
40804ll,
44944ll,
1002001ll,
1234321ll,
4008004ll,
100020001ll,
102030201ll,
104060401ll,
121242121ll,
123454321ll,
125686521ll,
400080004ll,
404090404ll,
10000200001ll,
10221412201ll,
12102420121ll,
12345654321ll,
40000800004ll,
1000002000001ll,
1002003002001ll,
1004006004001ll,
1020304030201ll,
1022325232201ll,
1024348434201ll,
1210024200121ll,
1212225222121ll,
1214428244121ll,
1232346432321ll,
1234567654321ll,
4000008000004ll,
4004009004004ll,

	
	};
	int vn = sizeof(v) / sizeof(ll);
	ll low, high;
	cin >> low >> high;
	ll* lp = lower_bound(v, v+vn, low);
	ll* hp = upper_bound(v, v+vn, high);
	return hp - lp;
}

int main()
{
#ifdef Hw
    freopen("usaco.in", "r", stdin);
    freopen("usaco.out", "w", stdout);
#endif

/* 	doit();
	return 0; */

	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		int ans = get_ans();
		printf("Case #%d: %d\n", cas, ans);
	}

    return 0;
}

/**



Input 
 	
Output 
 
3
1 4
10 120
100 1000

Case #1: 2
Case #2: 0
Case #3: 2



**/
