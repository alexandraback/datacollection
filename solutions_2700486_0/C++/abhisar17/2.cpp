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
struct node
{
	bool M[15][10];
};
node P,Q,R;
vector<node> G[21];

void slide_left(int s,int x,int y,node A)
{
	while(y>0 && !A.M[x-1][y-1])
		x--,y--;
	A.M[x][y] = 1;
	G[s].PB(A);
}

void slide_right(int s,int x,int y,node A)
{
	while(y>0 && !A.M[x+1][y-1])
		x++,y--;
	A.M[x][y] = 1;
	G[s].PB(A);
}


void slide(int s,int x,int y,node A)
{
	if( y == 0 )
	{
		A.M[x][y] = 1;
		G[s].PB(A);
	}
	else if( A.M[x][y-2] == 0)
		slide(s,x,y-2,A);
	else
	{
		if( !A.M[x-1][y-1] && !A.M[x+1][y-1])
		{
			slide_left(s,x,y,A);
			slide_right(s,x,y,A);
		}
		else if( !A.M[x-1][y-1] )
		{
			slide_left(s,x,y,A);
		}
		else if( !A.M[x+1][y-1] )
		{
			slide_right(s,x,y,A);
		}
		else
		{
			A.M[x][y] = 1;
			G[s].PB(A);
		}
	}
}
int main()
{
	//node Y;
	//Y.M[0][0] = 1 , Y.M[-2][0] = 1;
	//Q[0][6] = 1;
	int t,cs=0,n,x,y;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<21;i++)
			G[i].clear();
		G[0].PB(P);
		cs++;
		cin>>n>>x>>y;
		cout<<"Case #"<<cs<<": ";
		if(x<-6 || x>6 || y>6)
		{
			cout<<"0.0"<<endl;
			continue;
		}
		else
		{
			x += 6;
		}
		int alltime = 0 , fav = 0;
		int s = 0;
		while(s<n)
		{
			for(int i=0;i<G[s].size();i++)
			{
				slide(s+1,6,6,G[s][i]);
			}
			s++;
		}
		//cout<<G[n].size()<<endl;;
		for(int i=0;i<G[n].size();i++)
		{
			alltime++;
			if( G[n][i].M[x][y] )
				fav++;
		}
		printf("%.12lf\n",double(fav)/alltime);
		//cout<<fav<<" "<<alltime<<endl;
	}
	return 0;
}
