
#include <cmath>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


#define max(a,b)(a>b?a:b)


int main(){

	
	int cases, caseidx;
	int n, nmin , nmax , ntest ;
	int ans ;
	int logres,logd,logda;
	int distinct[9];
	int d;

	string sn;

	cin >> cases;

	for (caseidx = 1 ; caseidx <= cases ; caseidx++ ){
		ans = 0;
		cin >> nmin >> nmax ;
		for(n=nmin ; n< nmax ; n++){


			logd =  static_cast<int>( log10(static_cast<float>(n)));
			for(logda = logd ; logda;logda--){
			logres = pow(10, logda);
			ntest = (n % logres)*pow(10,logd-logda+1) + (n/logres);
			
			distinct[logda] = ntest;
			if ((ntest > n ) && (ntest <= nmax)){
				for (d = logda+1 ; d <= logd ; d++ ){
					if (ntest == distinct[d] ) break;			 	
				}

				if ( d > logd ) ans++; 
			}


		}			}

		cout << "Case #" << caseidx << ": " << ans << endl  ; 
	}

	return 0;
}

