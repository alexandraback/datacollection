#include <assert.h>
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

map<ii , int > mp;

int digcnt( int A ) {
	int cnt = 0;
	while( A > 0 ){
		cnt++;
		A /= 10;
	}
	return cnt;
}
int main() {
	int testcase;scanf("%d" , &testcase );
	for( int cs = 1; cs <= testcase; cs++ ) {
		mp.clear();	
		int A , B;
		scanf("%d %d" , &A , &B );
		assert( digcnt(A) == digcnt(B) );
		int perpow = 1;
		int Digit = digcnt(A);
		for( int i = 1; i < Digit; i++ ) perpow *= 10;
		
		int ans = 0;

		for( int i = A; i <= B; i++ ) {		
			int right = 0 , left = i , pow = perpow , npow = 1;
			while( left > 0 ) {
				int rem = left%10;	
				left /= 10;
				right = rem*npow +(right);
				int val = right*pow+left;
				pow /= 10;npow *= 10;
				if( val > i && val <= B && (!mp[make_pair(i , val )]) ){ mp[make_pair(i,val)] = 1;ans++; }
		//		else if( val > i && val <= B && (mp[make_pair(i , val )]) ){cout << i << " " << val << "\n"; }
			}
		}
		cout << "Case #" << cs << ": " << ans << "\n";
	}
	return 0;
}
