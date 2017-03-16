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
const int N=128               ;
const int M=1               ;
const ll P=10000000097ll    ;

string problem = "buylow";

int mp[N][N];
int r, c;

void read()
{
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			scanf("%d", &mp[i][j]);
}

bool check(int x,int y)
{
	for(int i=0; i<r; i++)
		if( mp[i][y] > mp[x][y] )
			goto next;
	return true;
	next:
	for(int j=0; j<c; j++)
		if( mp[x][j] > mp[x][y] )
			return false;
	return true;
}

bool doit()
{
	read();
	
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			if( !check(i, j) )
				return false;
		}
	return true;
	
}

void print()
{

}

int main()
{
#ifdef Hw
    freopen("usaco.in", "r", stdin);
    freopen("usaco.out", "w", stdout);
#else
    freopen((problem + ".in").c_str(), "r", stdin);
    freopen((problem + ".out").c_str(), "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for(int _=1; _<=T; _++)
	{
		bool ans = doit();
		printf("Case #%d: %s\n", _, ans? "YES" : "NO");
	}


    return 0;
}

/**



Input 
 	
Output 
 
3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1

Case #1: YES
Case #2: NO
Case #3: YES



**/
