/*****************************************
USER: zacdxv1
PROB: Tic-Tac-Toe-Tomek
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

char s[5][5];

bool check_T()
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if( 'T' == s[i][j] )
				return true;
	return false;
}

int dx[] = { 1, 1, 1, 0, 0,-1,-1,-1};
int dy[] = { 1, 0,-1, 1,-1, 1, 0,-1};

bool has_space()
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if( s[i][j] == '.' )
				return true;
	return false;
}

bool in(int x)
{
	return x>=0 && x<4;
}

bool success(int x,int y,int len)
{
	int tx, ty;
	for(int dt=0; dt<8; dt++)
	{
		for(int id=0; id<len; id++)
		{
			tx = x + dx[ dt ] * id;
			ty = y + dy[ dt ] * id;
			if( in(tx) && in(ty) && (s[x][y]==s[tx][ty] || s[tx][ty]=='T') )
				continue;
			goto no;
		}
		return true;
	no:
		tx++;
	}
	return false;
}

int check(int len)
{
	char ret = '.';
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if( '.'!=s[i][j] )
			{
				if( success(i, j, len) )
				{
					if( '.'==ret )
						ret = s[i][j];
					else if( ret != s[i][j] )
						return 2;
				}
			}
	switch( ret )
	{
	case 'X':
		return 0;
		break;
	case 'O':
		return 1;
		break;
	case '.':
		if( has_space() )
			return 3;
		else
			return 2;
		break;
	}
	return -1;
}

int doit()
{
	for(int i=0; i<4; i++)
		scanf("%s", s[i]);
	bool has_T = check_T();
	return check(4);
}

void print()
{
	
}

int main()
{
#ifdef Hw
    freopen("usaco.in", "r", stdin);
    freopen("usaco.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	
	string str[] = {"X won", "O won", "Draw", "Game has not completed"};

	for(int _=1; _<=T; _++)
	{
		int ans = doit();
		printf("Case #%d: %s\n", _, str[ans].c_str());
	}



    return 0;
}

/**

Input 
 	
Output 
 
6
XXXT
....
OO..
....

XOXT
XXOO
OXOX
XXOO

XOX.
OX..
....
....

OOXX
OXXX
OX.T
O..O

XXXO
..O.
.O..
T...

OXXX
XO..
..O.
...O

Case #1: X won
Case #2: Draw
Case #3: Game has not completed
Case #4: O won
Case #5: O won
Case #6: O won

**/
