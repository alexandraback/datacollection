#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fill(x,y) memset((x),(y) ,sizeof(x))
#define type(x) __typeof(x.begin())
#define sz(x) x.size()
#define o ((f+l)/2)
#define umax(x,y) (x)=max((x),(y))
#define NEW(x) (x *)calloc(1,sizeof(x))
#define umin(x,y) (x)=min((x),(y));
#define tmax(x,y,z) max((x),max((y),(z))) 
#define tmin(x,y,z) min((x),min((y),(z))) 
#define PI (acos(-1)) 

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int Lint;
typedef long double LD;
int HM;
LD N,M,TAR;
struct node {
	LD cookie,gain,time;
	node( LD _cookie=0 , LD _gain=0 , LD _time=0 )
	{
		cookie=_cookie;
		gain=_gain;
		time=_time;
	}
	friend bool operator < ( const node &a , const node &b )
	{
		return a.time > b.time ;
	}
	
};

LD bfs( node a )
{
	priority_queue<node> q;
	q.push( a ) ;
	while( !q.empty() )
	{
		a=q.top();
		q.pop();
		if( a.cookie==TAR )
			return a.time;
		q.push( node( 0 , a.gain+M , a.time+((N-a.cookie)/a.gain)  ) );
		q.push( node( TAR , a.gain , a.time+((TAR-a.cookie)/a.gain)  ) );
	}
	return -1;
}
int main ()
{
	//~ freopen("","r",stdin);
	//~ freopen("","w",stdout);
	scanf("%d",&HM);
	for( int i=1 ; i<=HM ; i++ ){
		scanf("%Lf %Lf %Lf",&N,&M,&TAR);
		printf("Case #%d: %.7Lf\n",i,bfs( node( 0 , 2 , 0 ) )); 
	}
		
	return 0;
}
