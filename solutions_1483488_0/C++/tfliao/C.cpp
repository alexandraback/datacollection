#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, nCase = 1 ;
int A, B;
int ans ;
int digit ;
int base ;

void setDigit () {
	int t = A/10, d = 0, b = 1;
	while ( t ) { t/=10, ++d, b*=10 ; }
	digit = d, base = b ;
}

int test ( int x ) {
	if ( digit == 0 ) return 0 ;
	int count = 0 ;
	vector<int> y;
	
	int t=x;
	for ( int i=0;i<digit;++i ) {
		t = 10*(t%base) + t/base;
		y.push_back(t);
//		cout << t << endl;
	}
	sort ( y.begin(), y.end() ) ;
	
	if ( y[0] > x && y[0] <= B ) ++count ;
	for ( int i=1;i<y.size();++i ) {
		if ( y[i] == y[i-1] ) continue ;
		if ( y[i] > x && y[i] <= B ) ++count ;
	}
	return count ;
}


int main()
{
	cin >> T;
	while ( T-- > 0 ) {
		cin >> A >> B ;
		setDigit();
		ans = 0 ;
		for ( int i=A;i<=B;++i ) {
			ans += test(i);
		}
		
		cout << "Case #" << nCase++ << ": " << ans << endl;
	}
	return 0; 
}