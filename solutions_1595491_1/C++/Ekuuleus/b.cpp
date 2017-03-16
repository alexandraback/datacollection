
#include <cmath>
#include <string>
#include <iostream>

using namespace std;


#define max(a,b)(a>b?a:b)


int main(){

	
	int cases, caseidx;

 		int n,s,p,d;
	int r1 , r2;
	int ni ;

	cin >> cases;

	for (caseidx = 1 ; caseidx <= cases ; caseidx++ ){

		cin >> n >> s >> p ;
		r1 = r2 = 0;
		
		
		for ( ni = 0 ; ni < n ; ni ++){
			cin >> d;
			if (( d >= (p*3-2)) ) { 
				r1++ ; 
			} else {
  				if ( d >= max((p*3-(p>1?4:2)),1)) r2++ ;
			}
		}
		if ( r2 > s ) r2=s;
				
		cout << "Case #" << caseidx << ": " << r1 + r2 << endl  ; 
	}

	return 0;

}

