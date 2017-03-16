#include <iostream>
#include <limits>

using namespace std;

void solve (int ci){


	double C, F, X ;

	cin >> C >> F >> X ;

	double rate1 = 2 ;
	double timeT = 0;

	double rate2 ;
	double tF ;

	for(;;) {

		tF = C / rate1  ;
		rate2 = rate1 + F ;
 
		if ( (tF + ( X / rate2 )) < ( X / rate1 )) {
			// but the factory.
			timeT += tF ;
			rate1 = rate2 ;			
		} else {
			timeT += X / rate1 ;
			break ;
		}
	}
	std::cout.precision(std::numeric_limits<double>::digits10);

	cout << "Case #" << ci << ": " << timeT << endl;

}



int main(){
	int c;
	cin >> c;
	
	for (unsigned int ci = 1 ; ci <= c ; ++ci ){
		solve (ci);
	}
}



