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
#define EPS 0.000001
#define For(x,y) for ( int (x) = 0; (x) < (y); (x)++ )
#define MAX 1
// EPS is 10^-6

int main(){
	int numCases;
	cin >> numCases;

	for(int caseN=1; caseN <= numCases; caseN++){
		double C,F,X;
		cin >> C >> F >> X;
		/******************/
		double rate = 2.0;
		double time = 0.0;
		while(true){
			//cout << "Rate is " << rate << endl;
			//cout << "Time is " << time << endl;
			if( (X/rate) > ( (C/rate) + (X/(rate+F)) )){
				time += C/rate;
				rate = rate + F;
			} else {
				time += X/rate;
				break;
			}

		}

		cout << "Case #" << caseN << ": ";
		cout << setprecision(12)	<< time << endl;
	}

	return 0;
}
