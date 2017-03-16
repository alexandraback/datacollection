#include <climits>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cassert>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll unsigned long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()

template <class T>inline string itos( T n ) {return (n)< 0?"-"+itos(-(n)):(n)<10?(string)("")+(char('0'+(n))):itos((n)/10)+itos((n)%10);}

typedef struct point {
	int x , y;string s;
}point;
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 ,-1 , 0 , 0  };
char dir[] = { 'N' , 'S' , 'E' , 'W' };
map<ii  , int> mp;

void Solve() {
	int X , Y; gi(X);gi(Y);
	queue< point > Q;mp.clear();
	Q.push( (point){ 0 , 0 , "" } );
	while( 1 ) {
		point P = Q.front();Q.pop();
		int mv = SZ(P.s);
//		cout << mv <<" " << P.x <<" " << P.y << " " <<  "\n";
		if( mp[ make_pair( P.x , P.y ) ] ) continue; 
		mp[ make_pair( P.x , P.y ) ] = 1;
		if( mv > 500  ) continue;
		if( (P.x == X) && (P.y == Y ) ){
			cout << P.s << "\n";
			return;
		}
		rep( k , 0 ,  4 ) {
			int xx= P.x + (dx[k]*(mv+1));
			int yy=P.y +(dy[k]*(mv+1));
			string ss = P.s+dir[k];
			
			Q.push( (point){ xx , yy , ss } );
		}
	}
}
int main() {
	int T  , cs = 1;
	cin >> T;
	while( cs <= T ) {
		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}
