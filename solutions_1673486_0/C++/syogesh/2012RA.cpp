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

using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()

int main() {
	int testcase;scanf("%d" , &testcase );
	for( int cs = 1; cs <= testcase; cs++ ) {
		int A , B; cin >> A >> B;
		double p[A];
		for( int i = 0; i < A; i++ ) cin >> p[i];
		double DP[A+1][2];DP[0][1] = (1.0-p[0]);DP[0][0] = p[0];	//0 for Right and 1 for Wrong 
		for( int i = 1; i < A; i++ ) {	
			DP[i][0] = DP[i-1][0]*p[i];
			DP[i][1] = (DP[i-1][0]+DP[i-1][1])*(1-p[i])+(DP[i-1][1])*(p[i]);
		}
	//	for( int i = 0; i < A; i++ ) cout << (DP[i][0]+DP[i][1]) << "\n";
		double ans = 1e16;int tmpp = 1.0;
		for( int i = 0; i <= A; i++ ) {	
			double cc = i+(B-A+i+1);
			double cw = i+(B-A+i+1);
			if( i < A ) cw += (B+1);
			double rp = 1.0 , wp = 0.0;
		
				
			if( A-i > 0 ) rp = DP[A-i-1][0]; 			
			if( A-i > 0 ) wp = DP[A-i-1][1];
			ans = min( ans , cc*rp + cw*wp );
			
	//		cout << cc*rp + cw*wp << "\n";
		}
		ans = min( ans , (double)B+2 );
		printf( "Case #%d: %0.6f\n" , cs , ans );
	}
	return 0;
}
