#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <cstring>
#include <ext/numeric>
using namespace std ;
using namespace __gnu_cxx ;
typedef long long LL ;
const int INF = 1000*1000*1000 ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

int ceil[200][200] ;
int floor[200][200] ;
bool used[200][200] ;
int d[200][200] ;

struct triple {
	int x, y, d ;
	triple(int xx, int yy, int dd) : x(xx), y(yy), d(dd) {}
} ;
bool operator<(const triple &a, const triple &b) {
	return a.d < b.d ;
}

main()
{
	ios_base::sync_with_stdio(0) ;
	int tests ;
	
	cin >> tests ;
	for(int test=1 ; test<=tests ; test++) {
		cout << "Case #" << test << ": " ;
		int n, m, i, j, H ;
		cin >> H >> n >> m ;
		for(i=0 ; i<n ; i++)
			for(j=0 ; j<m ; j++) cin >> ceil[i][j] ;
		for(i=0 ; i<n ; i++)
			for(j=0 ; j<m ; j++) cin >> floor[i][j] ;
		
		memset(used, 0, sizeof(used)) ;
		for(i=0 ; i<n ; i++)
			for(j=0 ; j<m ; j++) d[i][j] = -INF ;
		
	//	cout << "n = " << n << " , m = " << m << endl ;
		
		used[0][0] = true ;
		queue<pair<int,int> > Q1 ;
		vector<pair<int,int> > Q2 ;
		Q1.push(MP(0,0)) ; Q2.push_back(MP(0,0)) ;
		while(!Q1.empty()) {
			pair<int,int> a = Q1.front() ; Q1.pop() ;
			int n_x[] = {0,0,-1,1} ;
			int n_y[] = {-1,1,0,0} ;
			for(int k=0 ; k<4 ; k++) {
				i = a.FI + n_x[k] ;
				j = a.SE + n_y[k] ;
				if(i<0 || i>=n || j<0 || j>=m) continue ;
				if(!used[i][j] && H+50<=ceil[i][j] && floor[i][j]+50<=ceil[i][j] && floor[a.FI][a.SE]+50<=ceil[i][j]
					&& ceil[a.FI][a.SE]>=50+floor[i][j]) {
					used[i][j] = true ;
					Q1.push(MP(i,j)) ;
					Q2.push_back(MP(i,j)) ;
				}
			}
		}
		
		memset(used, 0, sizeof(used)) ;
		priority_queue<triple> kolejka ;
		FOREACH(q, Q2) {
		//	cout << q->FI << " " << q->SE << endl ;
			d[q->FI][q->SE] = H ;
			kolejka.push(triple(q->FI, q->SE, H)) ;
		}
		
		while(!kolejka.empty()) {
			triple a = kolejka.top() ; kolejka.pop() ;
			int x = a.x, y = a.y ;
			int h = d[x][y] ;
			if(used[x][y]) continue ;
		//	cout << "x = " << x << " y = " << y << "  " << d[x][y] << endl ;
			used[x][y] = true ;
			int n_x[] = {0,0,-1,1} ;
			int n_y[] = {-1,1,0,0} ;
			for(int k=0 ; k<4 ; k++) {
				i = a.x + n_x[k] ;
				j = a.y + n_y[k] ;
				if(i<0 || i>=n || j<0 || j>=m || floor[i][j]+50>ceil[i][j] || floor[x][y]+50>ceil[i][j]
					|| ceil[x][y] < 50+floor[i][j]) continue ;
				int nh = min(h, ceil[i][j]-50) ;
			//	cout << "nh = " << nh << endl ;
				if(nh >= floor[x][y]+20) nh -=10 ;
				else nh -= 100 ;
				if(nh > d[i][j]) {
					d[i][j] = nh ;
					kolejka.push(triple(i,j,nh)) ;
				}
			}
		}
		double ret = (H - d[n-1][m-1])/10.0 ;
		cout.setf(ios::fixed) ;
		cout.precision(3) ;
		cout << ret << endl ;
	}
}

