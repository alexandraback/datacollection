#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define rp(i,l,r) for ( int i=(int)(l); i<=(int)(r); ++i )
#define dp(i,l,r) for ( int i=(int)(l); i>=(int)(r); --i )
#define rpt(i,t) for ( typeof(t.begin()) i=t.begin(); i!=t.end(); ++i )
#define In insert
#define Co count
#define Fi first
#define Se second
#define PB push_back
#define MP make_pair

const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1};

typedef long long LL;
typedef vector < int > VI;
typedef vector < string > VS;
typedef vector < LL > VL;
typedef vector < double > VD;
typedef pair < int , int > PII;

#define mn 110

const double zero=0.000000001;
const int inf=-10000000;

int T,n,m,h;
int u[mn][mn],d[mn][mn],dist[mn][mn];
bool bo[mn][mn];

int main()
{
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	cin >> T ;
	rp( Test,1,T )
	{
		cin >> h >> n >> m ;
		rp( i,1,n ) rp( j,1,m ) cin >> u[i][j];
		rp( i,1,n ) rp( j,1,m ) cin >> d[i][j];
		rp( i,1,n ) rp( j,1,m ) dist[i][j]=-1000000;
		memset( bo , 0 , sizeof bo );
		dist[1][1]=h;
		while ( 1 )
		{
			int Max=inf , x , y ;
			rp( i,1,n ) rp( j,1,m ) if ( !bo[i][j] && Max<dist[i][j] )
			{
				x=i , y=j;
				Max=dist[i][j];
			} // 0 - 0
			//cout << x << " " << y << " " << dist[x][y] << endl;
			//scanf("%*c");
			if ( bo[x][y] ) break;
			if ( x==n && y==m ) break;
			rp( k,0,3 )
			{	
				int X=dx[k]+x , Y=dy[k]+y;
				if ( X<=0 || Y<=0 || X>n || Y>m ) continue;
				if ( bo[X][Y] ) continue;
				if ( u[X][Y]-d[X][Y]<50 ) continue;
				if ( u[X][Y]-d[x][y]<50 ) continue;
				if ( u[x][y]-d[X][Y]<50 ) continue;
				int temp=min( u[X][Y]-50 , dist[x][y] );
				if ( temp!=h ) if ( temp-d[x][y]<20 ) temp-=100; else temp-=10;
				dist[X][Y]=max( dist[X][Y] , temp );
			} // 0 - 0
			bo[x][y]=1;
		} // 0 - 0
		cout << "Case #" << Test << ": " << (double)(h-dist[n][m])/10 << endl;
	} // 0 - 0
} // 0 - 0 