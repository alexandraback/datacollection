/*****************************************
USER: a180285
PROB: Bullseye
LANG: C++
2013,UESTC
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


template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const ull oo=~0ll          ;
const double eps=1e-7       ;
const int N=1               ;
const int M=1               ;
const ll P=10000000097ll    ;

void read()
{
	
}

void print()
{

}

bool can(ull x,ull r,ull t)
{
	if((oo - 2*x*(x+1)) / (2*r) < x)
		return false;
	return 2*x*(x+1) + 2*r*x - 3*x <= t;
}

int doit()
{
	ull r, t;
	cin >> r >> t;
	
	ll low = 1;
	ll high = 1e9;
	while(low < high)
	{
		ll mid = (low + high + 1) / 2;
		if(can(mid, r, t))
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

int main()
{
#ifdef Hw
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

	// for(int i=1; i<10; i++)
	// {
		// printf("%d -> ", i);
		// can(i, 100);
	// }

	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T; cas++)
	{
		read();
		int ans = doit();
		printf("Case #%d: %d\n", cas, ans);
	}
    return 0;
}

/**

nput 
 	
5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000


Output 
 
Case #1: 1
Case #2: 2
Case #3: 3
Case #4: 707106780
Case #5: 49

**/