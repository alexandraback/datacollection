/* BA 2013 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <limits>
#include <limits.h>
#include <iomanip>


using namespace std;
#define pb push_back
#define EPS 0.00001
#define For(x,y) for ( int (x) = 0; (x) < (y); (x)++ )
#define MAX 1


int main(){
	int numCases;
	cin >> numCases;

	for(int caseN=1; caseN <= numCases; caseN++){
		long long A,B,K;
		cin >> A >> B >> K;
		//cout << "A = " << A << ", B=" << B << ",K= " << K << endl;
		// make B the bigger one
		if(A > B){
			long long temp = B;
			B = A;
			A = temp;
		}
		/*******/
		long long ans = 0;

		if(K >= A or K >= B){
			ans = A*B;
		} else{
			ans += K*B;
			// the rest, we will iterate through i >= K
			for(long long n_a = K; n_a < A; n_a++){
				ans += K; // stuff in B that is less than K
				for(long long n_b = K; n_b < B; n_b++){
					if( (n_a & n_b) < K){
						ans ++;
					}
				}
			}






		}

		cout << "Case #" << caseN << ": ";
		// output
		cout << ans;
		cout << endl;
	}

	return 0;
}
