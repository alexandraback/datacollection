#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long LL;
#define VI vector<int>
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A,0,sizeof(A))
#define MSV(A,a) memset(A,a,sizeof(A))
#define MAX(a,b) ((a>=b)?(a):(b))
#define MIN(a,b) ((a>=b)?(b):(a))
#define II pair<int,int>
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A,x) (A.find(x)!=A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define DEB(n) cout<<"(<<< DEBUG "<<n<<" >>>)"<<endl;
//int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
//int dx[] = {1,1,1,0,0,-1,-1,-1}, dy[] = {1,0,-1,1,-1,1,0,-1};
inline void inp( int &n )
{
        n=0;
        int ch=getcx();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
		n=n*sign;
}
const int n = 4;
char board[10][10];
char player[2] = {'X','O'};
bool is_valid(int x,int y)
{
	return x>=0 && y>=0 && x<n && y<n;
}
int dx[] = { 0,1,1,1};
int dy[] = { 1,1,0,-1};
bool is_won(int p,int x,int y,int step)
{
	for(int i=0;i<4;i++)
	{
		int nx = x + i*dx[step];
		int ny = y + i*dy[step];
		//cout<<nx<<" "<<ny<<" "<<player[p]<<endl;
		if( !is_valid(nx,ny) || board[nx][ny] == player[p^1] || board[nx][ny] == '.')
			return 0;
	}
	//cout<<p<<" "<<x<<" "<<y<<" "<<step<<endl;
	return 1;
}
int determine_state()
{
	int ec = 0;
	REP(i,n)
		REP(j,n)
			if( board[i][j] == '.' )
				ec++;
	REP(i,n)
		REP(j,n)
			REP(k,2)
				REP(l,4)
					if( is_won(k,i,j,l) )
						return k;
	if(ec)
		return 3;
	return 2;
}
int main()
{
	char ans[4][50] = {"X won" , "O won" , "Draw" , "Game has not completed"};
	int t;
	scanf("%d",&t);
	REP(tc,t)
	{
		REP(i,n)
			scanf("%s",board[i]);
		printf("Case #%d: %s\n",tc+1,ans[ determine_state() ] );
	}
	return 0;
}
