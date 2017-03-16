/*****************************************
USER: a180285
PROB: Manage your Energy
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

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=100000               ;
const int M=1               ;
const ll P=10000000097ll    ;

void read()
{

}

void print()
{

}

ll v[N];
int num[N];

void pre(int n)
{
	for(int i=n-1; i>=0; i--)
	{
		int j;
		for(j=i+1; j<n; j++)
			if(v[j] > v[i])
				break;
		if(n == j)
			j = i + 1e+7;
		num[i] = j - i;
	}
}

ll doit()
{
	ll e, r, n;
	cin >> e >> r >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];
	pre(n);
	
	ll ans = 0;
	ll now = e;
	for(int i=0; i<n; i++)
	{
		now += r;
		checkmin(now, e);
		ll low = MAX(e - num[i]*r, 0);
		checkmin(low, now);
		ans += (now - low) * v[i];
		now = low;
	}
	return ans;
	
	
}

int main()
{
#ifdef Hw
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T; cas++)
	{
		read();
		ll ans = doit();
		printf("Case #%d: %I64d\n", cas, ans);
	}
    return 0;
}

/**

Input 
 	
Output 
 
3
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5
Case #1: 12
Case #2: 12
Case #3: 39

**/